<?php

namespace Currency\MVC\Models;


use Currency\Database\IDbProvider;
use Currency\Exceptions\DbQueryNoResultsException;

/**
 * Class Rates handles receiving data about rates from DB.
 * @package Currency\MVC\Models
 */
class Rates extends Model
{
    private $dbConnection = null;

    public function __construct(IDbProvider $dbConnection)
    {
        $this->dbConnection = $dbConnection;
    }

    /**
     * Get all rates.
     * @return array - rates with details
     * @throws DbQueryNoResultsException - throws if there are not rates in db
     */
    public function getRateCollection(): array
    {
        $sqlQuery = "SELECT * FROM rates";

        $this->dbConnection->executeQuery($sqlQuery);

        $rates = $this->dbConnection->getResult();

        if (count($rates) === 0)
            throw new DbQueryNoResultsException('no results in database');

        return $rates;
    }

    /**
     * Get rate by given date.
     * @param string $date - date in format "YYYY-MM-DD"
     * @return array - rate details
     * @throws DbQueryNoResultsException - throws if there are not rates specified by $date
     */
    public function getRateByData(string $date): array
    {
        $sqlQuery = "SELECT * FROM rates WHERE date = :date";

        $this->dbConnection->executeQuery($sqlQuery, ['date' => $date]);

        $rates = $this->dbConnection->getResult();

        if (count($rates) === 0)
            throw new DbQueryNoResultsException('no results in database');

        return $rates;
    }

    /**
     * Get last added rate.
     * @return array - rate details
     * @throws DbQueryNoResultsException - throws if there are not rates in db
     */
    public function getLastRate(): array
    {
        $sqlQuery = "SELECT * FROM rates ORDER BY date DESC LIMIT 1";

        $this->dbConnection->executeQuery($sqlQuery);

        $rates = $this->dbConnection->getResult();

        if (count($rates) === 0)
            throw new DbQueryNoResultsException('no results in database');

        return $rates;
    }

}