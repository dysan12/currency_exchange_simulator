<?php

namespace Currency\MVC\Models;


use Currency\Database\IDbProvider;

/**
 * TESTING CLASS
 * @package Currency\MVC\Models
 */
class Currency extends Model
{
    protected $dbConnection;

    public function __construct(IDbProvider $dbConnection)
    {
        $this->dbConnection = $dbConnection;
    }

    public function getCurrent()
    {
        $ch = curl_init('http://api.fixer.io/latest');
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_BINARYTRANSFER, true);

        return curl_exec($ch);
    }
}