<?php

namespace Currency\Database;


use Currency\Exceptions\DbQueryException;

class MySQL implements IDbProvider
{
    private $connection = null;
    private $currentExecution;

    /**
     * Instantiate connection between server and DBMS.
     * @param array $config - configuration array consist of [host, dbName, user, password] indexes.
     */
    public function initializeConnection(array $config): void
    {
        $this->connection = new \PDO('mysql:host=' . $config['host'] . ';dbname=' . $config['dbName'] . ';charset=utf8',
            $config['user'], $config['password']);

        $this->connection->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
        $this->connection->setAttribute(\PDO::ATTR_CASE, \PDO::CASE_LOWER);
    }

    /**
     * Bind values to query and execute it.
     * @param string $query - SQL query
     * @param array $valuesToBind - values to bind for eg. ['name' => 'Michal'] would be bound to 'id = :name'
     * @return bool - result of executing
     * @throws DbQueryException - throws if PDO connection wouldn't be created earlier
     */
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
     * Get result from PDOStatement and return it. If there is only one result, return it as direct array.
     * @return array - query result
     */
    public function getResult(): array
    {
        try {
            $result = $this->currentExecution->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\PDOException $exception) {
            $result = [];
        } finally {
            $this->currentExecution = null;

            if (count($result) === 1)
                return $result[0];

            return $result;
        }
    }
}