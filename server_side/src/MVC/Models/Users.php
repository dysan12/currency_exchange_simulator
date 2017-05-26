<?php

namespace Currency\MVC\Models;


use Currency\Database\IDbProvider;
use Currency\Exceptions\DbQueryCreatingFailure;
use Currency\Exceptions\DbQueryNoResultsException;
use Currency\Exceptions\DbQueryValueNotUnique;
use Currency\Exceptions\DbQueryValueTooLong;

/**
 * Class Users handles getting and modifying user data
 * @package Currency\MVC\Models
 */
class Users extends Model
{
    private $dbConnection;

    public function __construct(IDbProvider $dbConnection)
    {
        $this->dbConnection = $dbConnection;
    }

    /**
     * Get user details. Query based on passed userLogin.
     * @param string $userLogin - login of user.
     * @return array - user's details.
     * @throws DbQueryNoResultsException - throws if user doesn't exist in database table.
     */
    public function getUserDetails(string $userLogin): array
    {
        $sqlQuery = 'SELECT login, name, surname, email FROM users WHERE login = :userLogin';

        $this->dbConnection->executeQuery($sqlQuery, ['userLogin' => $userLogin]);

        $result = $this->dbConnection->getResult();
        if (!count($result))
            throw new DbQueryNoResultsException('there are no such user in DB');

        return $result;
    }

    /**
     * Creating user according to passed data. Default values are ['name' => 'user_name'].
     * @param string $login - must be unique
     * @param string $password
     * @param string $email - must be unique
     * @param array $defaultValues - for eg. user name
     * @return int - result of creating
     * @throws DbQueryCreatingFailure - throws if there would be problems with creating user
     * @throws DbQueryValueNotUnique - throws if login or email wouldn't be unique
     * @throws DbQueryValueTooLong - throws if any of passed values exceeded appropriate length
     */
    public function createUser(string $login, string $password, string $email, array $defaultValues = [])
    {
        $sqlQuery = "INSERT INTO users (login, password, email, name) VALUES (:login, :password, :email, :name)";
        $valuesToBind = ['login' => $login, 'password' => $password, 'email' => $email, 'name' => $defaultValues['name'] ?? ''];

        if (strlen($login) > 40 || strlen($password) > 60 || strlen($email) > 120 || strlen($defaultValues['name'] ?? '') > 40)
            throw new DbQueryValueTooLong('length of values cannot exceed(letters): login(40), password(60), email(120), name(40)');

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