<?php

namespace Currency\MVC\Controllers;



use Currency\Collections\ICollection;
use Currency\Database\DbCreator;
use Currency\Exceptions\DbProviderException;
use Currency\Logs\LogsCreator;
use Currency\MVC\Response\Response;


abstract class Controller
{
    protected $logsCreator;
    protected $globalVars;
    protected $dbConnection;

    public function __construct(ICollection $globalVarsCollection)
    {
        $this->logsCreator = new LogsCreator();
        $this->globalVars = $globalVarsCollection;
        $response = new Response('Database instantiation');

        try {
            $dbCreator = new DbCreator();
            $this->dbConnection = $dbCreator->create(DB_PROVIDER);
            $this->dbConnection->initializeConnection([
               'host' => DB_HOST,
                'dbName' => DB_NAME,
                'user' => DB_USER,
                'password' => DB_PASSWORD
            ]);

        } catch (DbProviderException | \PDOException $error ) {
           $this->logsCreator->create('Error')
               ->saveMessage('DB provider/connection Instantiation', $error);
            $response
                ->setResponse([
                    'errors' => [
                        ['id' => 'db_connection_error', 'desc' => 'problem with connection to database occurred']
                    ]
                ])
                ->setStatusCode(500)
                ->sendResponse();

        }
    }
}