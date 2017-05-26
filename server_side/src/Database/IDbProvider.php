<?php

namespace Currency\Database;


interface IDbProvider
{
    /**
     * Instantiate connection between server and DBMS
     * @param array $config - configuration array consist of [host, dbName, user, password] indexes.
     */
    public function initializeConnection(array $configArray): void;

    /**
     * @param string $query - SQL query
     * @param array $valuesToBind - values to bind for eg. ['name' => 'Michal'] would be bound to 'id = :name'
     * @return bool - result of executing
     */
    public function executeQuery(string $query, array $valuesToBind = []): bool;

    /**
     * @return array - result of previously made query execution
     */
    public function getResult(): array;
}