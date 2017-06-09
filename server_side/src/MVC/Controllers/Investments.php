<?php

namespace Currency\MVC\Controllers;


use Currency\Collections\ArrayCollection;
use Currency\Collections\ICollection;
use Currency\Exceptions\CredentialsException;
use Currency\Exceptions\DbQueryCreatingFailure;
use Currency\Exceptions\DbQueryExecutingFailure;
use Currency\Exceptions\DbQueryNoResultsException;
use Currency\Exceptions\DbQueryTooFewValues;
use Currency\Exceptions\DbQueryValueTooLong;
use Currency\Exceptions\ItemCollectionException;
use Currency\MVC\Response\Response;
use Currency\MVC\Models;

class Investments extends AuthorizedController
{
    protected $response;
    protected $dataRequest;
    protected $mainModel;

    public function __construct(ICollection $globalVarsCollection)
    {
        parent::__construct($globalVarsCollection);

        $this->dataRequest = new ArrayCollection();
        $this->dataRequest->setCollection($this->globalVars->getItem('dataRequest'));

        $this->response = new Response();
        $this->mainModel = new Models\Investments($this->dbConnection);
    }

    public function modifyInvestment()
    {
        $this->response->setHeader('Modify Investment');
        $investKeys = $this->dataRequest->getItem('details');
        $investOwner = $investKeys[0];
        $investName = $investKeys[1];

        try {
            if ($investOwner !== $this->token['user_login'])
                throw new CredentialsException('requested owner is not owner of provided token');

            $investCurrencies = [];

            $requestCollection = $this->dataRequest->getCollection();
            $currenciesKeys = [
                'AUD', 'BGN', 'BRL', 'CAD', 'CHF', 'CNY', 'CZK', 'DKK', 'GBP', 'HKD', 'HRK', 'HUF', 'IDR', 'ILS', 'INR', 'JPY', 'KRW', 'MXN', 'MYR', 'NOK', 'NZD', 'PHP', 'RON', 'RUB', 'SEK', 'SGD', 'THB', 'TRY', 'USD', 'ZAR', 'PLN', 'EUR'
            ];
            foreach ($requestCollection as $name => $value) {
                if (in_array($name, $currenciesKeys)) {
                    $investCurrencies[$name] = $value;
                }
            }

            if (count($currenciesKeys) !== count($investCurrencies))
                throw new DbQueryTooFewValues('all currencies ought to be passed in request');

            $this->mainModel->modifyInvestment($investOwner, $investName, $investCurrencies);
            $investment = $this->mainModel->getInvestment($investOwner, $investName);

            $this->response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $investment,
                    'messages' => [
                        ['id' => 'modifying_investment_success', 'desc' => 'indicated investment modified successfully']
                    ]
                ]);
        } catch (DbQueryTooFewValues  $exception) {
            $this->response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'access_error', 'desc' => $exception->getMessage()]
                    ]
                ]);
        } catch (CredentialsException  $exception) {
            $this->response
                ->setStatusCode(404)
                ->setResponse([
                    'errors' => [
                        ['id' => 'access_error', 'desc' => $exception->getMessage()]
                    ]
                ]);
        } catch (DbQueryExecutingFailure | \PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $this->response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'getting_failure', 'desc' => 'problem with getting data from DB']
                    ]
                ]);
        } finally {
            $this->response->sendResponse();
        }
    }

    public function deleteInvestment()
    {
        $this->response->setHeader('Delete Investment');
        $investKeys = $this->dataRequest->getItem('details');
        $investOwner = $investKeys[0];
        $investName = $investKeys[1];

        try {
            if ($investOwner !== $this->token['user_login'])
                throw new CredentialsException('requested owner is not owner of provided token');

            $investment = $this->mainModel->deleteInvestment($investOwner, $investName);
            $this->response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $investment,
                    'messages' => [
                        ['id' => 'deleting_investments_success', 'desc' => 'indicated investment deleted successfully']
                    ]
                ]);
        } catch (CredentialsException  $exception) {
            $this->response
                ->setStatusCode(404)
                ->setResponse([
                    'errors' => [
                        ['id' => 'access_error', 'desc' => $exception->getMessage()]
                    ]
                ]);
        } catch (DbQueryExecutingFailure | \PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $this->response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'getting_failure', 'desc' => 'problem with getting data from DB']
                    ]
                ]);
        } finally {
            $this->response->sendResponse();
        }

    }

    public function createInvestment()
    {
        $this->response->setHeader('Create Investment');

        try {
            $investOwner = $this->dataRequest->getItem('user');
            $investFoundData = date("Y-m-d");
            $investName = $this->dataRequest->getItem('name');

            if ($investOwner !== $this->token['user_login'])
                throw new CredentialsException();

            $this->mainModel->createInvestment($investOwner, $investFoundData, $investName);

            $this->response
                ->setStatusCode(201)
                ->setResponse([
                    'messages' => [
                        ['id' => 'investment_created', 'desc' => 'investment created successfully']
                    ]
                ]);

        } catch (ItemCollectionException $exception) {
            $this->response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'username_required', 'desc' => 'name of investment and owner(user login) ought to be passed in request']
                    ]
                ]);
        } catch (CredentialsException $exception) {
            $this->response
                ->setStatusCode(404)
                ->setResponse([
                    'errors' => [
                        ['id' => 'authorization_error', 'desc' => 'it\'s not possible to add investment on someone behalf']
                    ]
                ]);
        } catch (DbQueryValueTooLong $exception) {
            $this->response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'passed_values_problem', 'desc' => $exception->getMessage()]
                    ]
                ]);
        } catch (DbQueryCreatingFailure | \PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $this->response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'creating_failure', 'desc' => 'problem with creating investment record / user currently has investment with the same name']
                    ]
                ]);
        } finally {
            $this->response->sendResponse();
        }

    }

    public function getInvestment()
    {
        $this->response->setHeader('Get Investment');

        $investKeys = $this->dataRequest->getItem('details');
        $investOwner = $investKeys[0];
        $investName = $investKeys[1];

        try {
            if ($investOwner !== $this->token['user_login'])
                throw new CredentialsException('requested owner is not owner of provided token');

            $investment = $this->mainModel->getInvestment($investOwner, $investName);
            $this->response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $investment,
                    'messages' => [
                        ['id' => 'investment', 'desc' => 'investment details in response']
                    ]
                ]);
        } catch (CredentialsException | DbQueryNoResultsException $exception) {
            $this->response
                ->setStatusCode(404)
                ->setResponse([
                    'errors' => [
                        ['id' => 'access_error', 'desc' => $exception->getMessage()]
                    ]
                ]);
        } catch (DbQueryExecutingFailure | \PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $this->response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'getting_failure', 'desc' => 'problem with getting data from DB']
                    ]
                ]);
        } finally {
            $this->response->sendResponse();
        }
    }

    public function getInvestments()
    {
        $this->response->setHeader('Get Investment\'s collection');


        try {
            $investOwner = $this->dataRequest->getItem('user');

            if ($investOwner !== $this->token['user_login'])
                throw new CredentialsException();

            $investments = $this->mainModel->getInvestmentsCollection($investOwner);

            $this->response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $investments,
                    'messages' => [
                        ['id' => 'investments_collection', 'desc' => 'investment collection in response']
                    ]
                ]);

        } catch (ItemCollectionException $exception) {
            $this->response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'username_required', 'desc' => 'owner login ought to be passed in filter URL(?user=NAME)']
                    ]
                ]);
        } catch (CredentialsException $exception) {
            $this->response
                ->setStatusCode(404)
                ->setResponse([
                    'errors' => [
                        ['id' => 'authorization_error', 'desc' => 'it\'s not possible to get someone\'s investments']
                    ]
                ]);
        } catch (DbQueryExecutingFailure | \PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $this->response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'getting_failure', 'desc' => 'problem with getting data from DB']
                    ]
                ]);
        } finally {
            $this->response->sendResponse();
        }
    }
}