<?php

namespace Currency\MVC\Controllers;



use Currency\Collections\ICollection;
use Currency\Database\DbCreator;
use Currency\Exceptions\DbProviderException;
use Currency\Logs\LogsCreator;
use Currency\MVC\Response\Response;

/**
 * Class Controller abstract class for controllers.
 * @package Currency\MVC\Controllers
 */
abstract class Controller
{
    protected $logsCreator;
    protected $globalVars;
    protected $dbConnection;

    /**
     * Controller constructor. Saves LogsCreator, DbConnection and GlobalVars to its property.
     * Generates response accordingly(code - reason):
     *      500 - if cannot instantiate connection with database.
     * @param ICollection $globalVarsCollection
     */
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