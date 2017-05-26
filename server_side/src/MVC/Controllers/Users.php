<?php

namespace Currency\MVC\Controllers;


use Currency\Collections\ArrayCollection;
use Currency\Exceptions\DbQueryMultipleResultException;
use Currency\Exceptions\DbQueryNoResultsException;
use Currency\Exceptions\DbQueryValueNotUnique;
use Currency\MVC\Response\Response;
use Currency\MVC\Models;

class Users extends AuthorizedController
{
    public function getUserDetails()
    {
        $dataRequest = new ArrayCollection();
        $dataRequest->setCollection($this->globalVars->getItem('dataRequest'));
        $response = new Response('User Details');

        $requestedLogin = $dataRequest->getItem('details')[0];

        if (!($requestedLogin === $this->token['user_login'])) {
            $response
                ->setStatusCode(401)
                ->setResponse([
                    'errors' => [
                        ['id' => 'incorrect_token_login', 'desc' => 'token belongs to another user']
                    ]
                ])
                ->sendResponse();
        }

        try {
            $model = new Models\Users($this->dbConnection);
            $details = $model->getUserDetails($requestedLogin);
            $response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $details
                ]);

        } catch (DbQueryNoResultsException $exception) {
            $this->logsCreator->create('Error')->saveMessage('User table', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'internal_problem', 'desc' => 'problem with database cohesion']
                    ]
                ]);

        } catch (\PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'internal_problem', 'desc' => 'problem with PDO query']
                    ]
                ]);

        } finally {
            $response->sendResponse();
        }

    }

    public function modifyUser()
    {

    }

    public  function deleteUser()
    {

    }

}