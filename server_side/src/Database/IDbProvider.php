<?php

namespace Currency\Database;


interface IDbProvider
{
    public function initializeConnection(array $configArray);

    /**
     * @param string $query
     * @param array $valuesToBind
     * @return array - result of query.
     */
    public function executeQuery(string $query, array $valuesToBind = []): bool;

    public function getResult(): array;
}