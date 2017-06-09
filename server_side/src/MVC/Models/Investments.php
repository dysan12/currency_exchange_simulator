<?php

namespace Currency\MVC\Models;


use Currency\Database\IDbProvider;
use Currency\Exceptions\DbQueryCreatingFailure;
use Currency\Exceptions\DbQueryExecutingFailure;
use Currency\Exceptions\DbQueryNoResultsException;
use Currency\Exceptions\DbQueryValueTooLong;

class Investments extends Model
{
    private $dbConnection;

    public function __construct(IDbProvider $dbConnection)
    {
        $this->dbConnection = $dbConnection;
    }

    /**
     * Create new investment.
     * @param string $owner - user login
     * @param string $foundDate - date of found
     * @param string $investName - name of investment
     * @return bool - result of execution
     * @throws DbQueryCreatingFailure - throws if creating was failure.
     */
    public function createInvestment(string $owner, string $foundDate, string $investName)
    {
        $sqlQuery = "INSERT INTO investments (user_login, found_date, name, PLN) VALUES (:owner, :foundDate, :investName, 10000)";

        if (strlen($owner) > 40 || strlen($investName) > 200)
            throw new DbQueryValueTooLong('length of values cannot exceed(letters): owner(40), name(200)');

        $result = $this->dbConnection->executeQuery($sqlQuery, [
            'owner' => $owner,
            'foundDate' => $foundDate,
            'investName' => $investName
        ]);

        if (!$result)
            throw new DbQueryCreatingFailure('problem with creating investment occurred');

        return $result;
    }

    /**
     * Get user's investments collection.
     * @param string $owner - login of owner
     * @return array - investments collection
     * @throws DbQueryCreatingFailure - throws if problem with executing query occurred.
     */
    public function getInvestmentsCollection(string $owner)
    {
        $sqlQuery = "SELECT * FROM investments WHERE user_login = :login";

        $result = $this->dbConnection->executeQuery($sqlQuery, ['login' => $owner]);

        if (!$result)
            throw new DbQueryExecutingFailure('problem with getting investments collection occurred');

        return $this->dbConnection->getResult();
    }

    /**
     * Get user's investment
     * @param string $investOwner - login of owner
     * @param string $investName - name of investment
     * @return array - investment details
     * @throws DbQueryExecutingFailure - throws if problem with executing query occurred
     * @throws DbQueryNoResultsException - throws if there is no such investment in DB
     */
    public function getInvestment(string $investOwner, string $investName)
    {
        $sqlQuery = "SELECT * FROM investments WHERE user_login = :owner AND name = :name";

        $result = $this->dbConnection->executeQuery($sqlQuery, ['owner' => $investOwner, 'name' => $investName]);

        if (!$result)
            throw new DbQueryExecutingFailure('problem with getting investment occurred');

        $investment = $this->dbConnection->getResult();
        if (!count($investment))
            throw new DbQueryNoResultsException('no such investment in DB');

        return $investment;
    }

    /**
     * Deleting investment from DB
     * @param string $investOwner - owner's login
     * @param string $investName - investment's name
     * @return bool - result of executing
     * @throws DbQueryExecutingFailure - throws if problem with executing query occurred
     */
    public function deleteInvestment(string $investOwner, string $investName)
    {
        $sqlQuery = "DELETE FROM investments WHERE user_login = :owner AND name = :name";

        $result = $this->dbConnection->executeQuery($sqlQuery, ['owner' => $investOwner, 'name' => $investName]);

        if (!$result)
            throw new DbQueryExecutingFailure('problem with deleting investment occurred');

        return $result;
    }

    /**
     * Modify investment.
     * @param string $investOwner - owner's login
     * @param string $investName - investment's name
     * @param array $currencies - all currencies passed in convention ['PLN' => 3242]
     * @return bool - result of executing
     * @throws DbQueryExecutingFailure - throws if problem with executing query occurred
     */
    public function modifyInvestment(string $investOwner, string $investName, array $currencies)
    {
        $currenciesEquals = [];
        foreach ($currencies as $currency => $value) {
            $currenciesEquals[] = $currency . '= :' . $currency;
        }

        $sqlQuery = "UPDATE investments SET " . implode(' ,', $currenciesEquals) . " WHERE user_login = :owner AND name = :name";

        $result = $this->dbConnection->executeQuery($sqlQuery, array_merge($currencies, ['owner' => $investOwner, 'name' => $investName]));

        if (!$result)
            throw new DbQueryExecutingFailure('problem with modifying investment occurred');

        return $result;
    }
}