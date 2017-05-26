<?php
/**
 * Created by PhpStorm.
 * User: Michal
 * Date: 2017-05-22
 * Time: 21:12
 */

namespace Currency\Database;


use Currency\Exceptions\DbQueryException;

class MySQL implements IDbProvider
{
    private $connection = null;
    private $currentExecution;
    private $result;

    /**
     * Instantiate connection between server and DBMS.
     * @param array $config - configuration array consist of [host, dbName, user, password] indexes.
     */
    public function initializeConnection(array $config)
    {
        $this->connection = new \PDO('mysql:host=' . $config['host'] . ';dbname=' . $config['dbName'] . ';charset=utf8',
            $config['user'], $config['password']);

        $this->connection->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
        $this->connection->setAttribute(\PDO::ATTR_CASE, \PDO::CASE_LOWER);
    }

    public function executeQuery(string $query, array $valuesToBind = []): bool
    {
        if ($this->connection instanceof \PDO) {

            $prepared = $this->connection->prepare($query);
            foreach ($valuesToBind as $name => $value) {
                $prepared->bindValue(':' . $name, $value);
            }
            $this->currentExecution = $prepared;

            return $prepared->execute();
        }

        throw new DbQueryException('Connection must be initialized properly before executing query.');
    }

    /**
     * Return saved result and delete it from instance.
     * @return array
     */
    public function getResult(): array
    {
        $result = $this->currentExecution->fetchAll(\PDO::FETCH_ASSOC);
        $this->currentExecution = null;

        if (count($result) === 1)
            return $result[0];

        return $result;
    }
}