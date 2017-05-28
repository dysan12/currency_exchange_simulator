<?php

namespace Currency\MVC\Controllers;


use Currency\Collections\ArrayCollection;
use Currency\Exceptions\DbQueryExecutingFailure;
use Currency\Exceptions\DbQueryModifyingFailure;
use Currency\Exceptions\DbQueryNoResultsException;
use Currency\Exceptions\DbQueryValueNotUnique;
use Currency\Exceptions\DbQueryValueTooLong;
use Currency\Exceptions\ItemCollectionException;
use Currency\MVC\Response\Response;
use Currency\MVC\Models;

class Users extends AuthorizedController
{
    /**
     * Get user details.
     * Generates response accordingly(code - reason):
     *      200 - if in response are included user's details
     *      401 - if user has no right to receive data
     *      500 - if problem with executing query occur or if in database there is no user like provided
     */
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
                    'data' => $details,
                    'messages' => [
                        ['id' => 'user_details', 'desc' => 'user\'s details in response']
                    ]
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

    /**
     * Modify user details.
     * Generates response accordingly(code - reason):
     *      200 - if user is modified
     *      401 - if passed values are: too long, some of its are not unique, one of its were not given
     *      500 - if problem with executing query occur
     */
    public function modifyUser()
    {
        $dataRequest = new ArrayCollection();
        $dataRequest->setCollection($this->globalVars->getItem('dataRequest'));

        $response = new Response('User Modifying');

        try {
            $login = $dataRequest->getItem('login');
            $email = $dataRequest->getItem('email');
            $name = $dataRequest->getItem('name');

            $model = new Models\Users($this->dbConnection);
            $model->modifyUser($login, $email, $name);
            $userDetails = $model->getUserDetails($login);
            $response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $userDetails,
                    'messages' => [
                        ['id' => 'modified_user', 'desc' => 'user modified successfully']
                    ]
                ]);
        } catch (ItemCollectionException $exception) {
            $response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'empty_fields', 'desc' => 'login, name, email fields are required']
                    ]
                ]);
        } catch (DbQueryValueTooLong $exception) {
            $response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'empty_fields', 'desc' => $exception->getMessage()]
                    ]
                ]);
        } catch (DbQueryExecutingFailure | \PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'creating_failure', 'desc' => 'there were problems with executing SQL query'],
                        ['id' => 'login_email_occupied', 'desc' => 'login and email seems to be occupied']
                    ]
                ]);

        } finally {
            $response->sendResponse();
        }
    }

    /**
     * Call deleting user and tokens associated with user.
     * Generates response accordingly(code - reason):
     *      200 - if user is deleted properly
     *      401 - if user has no right to delete indicated user
     *      500 - if problem with executing query occur
     */
    public function deleteUser()
    {
        $dataRequest = new ArrayCollection();
        $dataRequest->setCollection($this->globalVars->getItem('dataRequest'));
        $response = new Response('Deleting User');

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
            $model->deleteUser($requestedLogin);
            $model->destroyAllUserTokens($requestedLogin);
            $response
                ->setStatusCode(200)
                ->setResponse([
                    'messages' => [
                        ['id' => 'record_deleted', 'desc' => 'user deleted successfully']
                ]]);

        } catch (DbQueryExecutingFailure | \PDOException $exception) {
            $this->logsCreator->create('Error')->saveMessage('User deleting', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'db_query_fail', 'desc' => 'there were problems with executing SQL query']
                    ]
                ]);
        } finally {
            $response->sendResponse();
        }
    }

}