<?php

namespace Currency\MVC\Models;


use Currency\Database\IDbProvider;
use Currency\Exceptions\DbQueryCreatingFailure;
use Currency\Exceptions\DbQueryNoResultsException;
use Currency\Exceptions\DbQueryValueNotUnique;

class Users extends Model
{
    private $dbConnection;

    public function __construct(IDbProvider $dbConnection)
    {
        $this->dbConnection = $dbConnection;
    }

    public function getUserDetails(string $userLogin): array
    {
        $sqlQuery = 'SELECT login, name, surname, email FROM users WHERE login = :userLogin';

        $this->dbConnection->executeQuery($sqlQuery, ['userLogin' => $userLogin]);

        $result = $this->dbConnection->getResult();
        if (!count($result))
            throw new DbQueryNoResultsException('there are no such user in DB');

        return $result;
    }

    public function createUser(string $login, string $password, string $email, array $defaultValues = [])
    {
        $sqlQuery = "INSERT INTO users (login, password, email, name) VALUES (:login, :password, :email, :name)";

        $valuesToBind = ['login' => $login, 'password' => $password, 'email' => $email, 'name' => $defaultValues['name'] ?? ''];

        if (!$this->checkValueAvailability('email', 'users',  $email))
            throw new DbQueryValueNotUnique('provided email is already in use');
        elseif (!$this->checkValueAvailability('login', 'users', $login))
            throw new DbQueryValueNotUnique('provided login is already in use');

        if ($this->dbConnection->executeQuery($sqlQuery, $valuesToBind)) {
            return 1;
        } else {
            throw new DbQueryCreatingFailure('problem with creating record in DB');
        }
    }

    /**
     * Check if provided value is unique in appropriate table.
     * @param string $name
     * @param string $value
     * @return int - if is occupied return 0, otherwise 1
     */
    private function checkValueAvailability(string $name, string $tableName, string $value)
    {
        $sqlQuery = sprintf("SELECT %s FROM %s WHERE %s = :%s", $name, $tableName, $name, $name);

        $this->dbConnection->executeQuery($sqlQuery, [$name => $value]);

        if ($this->dbConnection->getResult())
            return 0;
        else
            return 1;
    }
}