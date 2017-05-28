<?php
/*
 * Script downloads data about current rates from fixer.io API and saves it into database. Script works properly only once a day, once
 */
require_once 'config.php';

//Historical API for receiving rates form the past(uncomment line 22 and comment 23)
//$date = '2017-05-26';
//$apiUrlHistorical = "http://www.apilayer.net/api/historical?access_key=" . RATES_API_KEY . "&date=" . $date . "&currencies=AUD,%20BGN,%20BRL,%20CAD,%20CHF,%20CNY,%20CZK,%20DKK,%20GBP,%20HKD,%20HRK,%20HUF,%20IDR,%20ILS,%20INR,%20JPY,%20KRW,%20MXN,%20MYR,%20NOK,%20NZD,%20PHP,%20RON,%20RUB,%20SEK,%20SGD,%20THB,%20TRY,%20PLN,%20ZAR,%20EUR";

$apiUrl = "http://www.apilayer.net/api/live?access_key=" . RATES_API_KEY . "&currencies=AUD,%20BGN,%20BRL,%20CAD,%20CHF,%20CNY,%20CZK,%20DKK,%20GBP,%20HKD,%20HRK,%20HUF,%20IDR,%20ILS,%20INR,%20JPY,%20KRW,%20MXN,%20MYR,%20NOK,%20NZD,%20PHP,%20RON,%20RUB,%20SEK,%20SGD,%20THB,%20TRY,%20PLN,%20ZAR,%20EUR";

$currencies = "AUD, BGN, BRL, CAD, CHF, CNY, CZK, DKK, GBP, HKD, HRK, HUF, IDR, ILS, INR, JPY, KRW, MXN, MYR, NOK, NZD, PHP, RON, RUB, SEK, SGD, THB, TRY, PLN, ZAR, EUR";
$currenciesToBind = ":AUD, :BGN, :BRL, :CAD, :CHF, :CNY, :CZK, :DKK, :GBP, :HKD, :HRK, :HUF, :IDR, :ILS, :INR, :JPY, :KRW, :MXN, :MYR, :NOK, :NZD, :PHP, :RON, :RUB, :SEK, :SGD, :THB, :TRY, :PLN, :ZAR, :EUR";

//Get current rates from fixer.io
$ch = curl_init($apiUrl);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_BINARYTRANSFER, true);

$apiResponse = json_decode(curl_exec($ch), true);
//$date = $apiResponse['date'];
$date  = date("Y-m-d", $apiResponse['timestamp']);
$base = $apiResponse['source'];
$sourceRates = $apiResponse['quotes'];

//Convert received style of rates(from 'USDPLN' => 0,7843 into 'PLN' => 0,7834)
foreach ($sourceRates as $name => $value) {
    preg_match('/USD([A-Z]{3})/', $name, $match);
    $rates[$match[1]] = $value;
}

//Create connection with DB
$connection = new \PDO('mysql:host=' . DB_HOST . ';dbname=' . DB_NAME . ';charset=utf8',
    DB_USER, DB_PASSWORD);
$connection->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
$connection->setAttribute(\PDO::ATTR_CASE, \PDO::CASE_LOWER);

//Check if in db is record with the same date, if not add this one
$sqlQuery = "SELECT date FROM rates WHERE date = :date";
$pdoStm = $connection->prepare($sqlQuery);
$pdoStm->execute([':date' => $date]);

if (!count($pdoStm->fetchAll())) {
    $sqlQuery = "INSERT INTO rates (date, base, " . $currencies . ") VALUES (:date, :base, " . $currenciesToBind . ")";
    $pdoStm = $connection->prepare($sqlQuery);

    $pdoStm->bindValue(':date' , $date);
    $pdoStm->bindValue(':base' , $base);

    foreach ($rates as $currency => $value) {
        $pdoStm->bindValue(':' . $currency, $value);
    }
    if ($pdoStm->execute())
        echo 'Rates added successfully.';
    else
        echo 'Problem with adding rates occurred.';

} else {
    echo 'Rates can be added once a day. Try again tomorrow.';
}




