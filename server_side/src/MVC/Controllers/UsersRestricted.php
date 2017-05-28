<?php

namespace Currency\MVC\Controllers;


use Currency\Collections\ArrayCollection;
use Currency\Exceptions\DbQueryCreatingFailure;
use Currency\Exceptions\DbQueryValueNotUnique;
use Currency\Exceptions\DbQueryValueTooLong;
use Currency\Exceptions\ItemCollectionException;
use Currency\MVC\Response\Response;
use Currency\MVC\Models;

/**
 * Class UsersRestricted controller with actions which not require user authentication.
 * @package Rates\MVC\Controllers
 */
class UsersRestricted extends Controller
{

    /**
     * Create user.
     * Generates response accordingly(code - reason):
     *      201 - if user is created
     *      401 - if passed values are: too long, some of its are not unique, one of its were not given
     *      500 - if problem with executing query occur
     */
    public function createUser()
    {
        $dataRequest = new ArrayCollection();
        $dataRequest->setCollection($this->globalVars->getItem('dataRequest'));
        $defaultFields = $dataRequest->getCollection();

        $response = new Response('User Creation');

        try {
            $login = $dataRequest->getItem('login');
            $password = $dataRequest->getItem('password');
            $email = $dataRequest->getItem('email');
            $name = $defaultFields['name'] ?? '';

            $model = new Models\Users($this->dbConnection);
            $model->createUser($login, $password, $email, ['name' => $name]);
            $response
                ->setStatusCode(201)
                ->setResponse([
                    'messages' => [
                        ['id' => 'created_user', 'desc' => 'user found successfully']
                    ]
                ]);
        } catch (DbQueryValueNotUnique $exception) {
            $response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'values_not_unique', 'desc' => $exception->getMessage()]
                    ]
                ]);

        } catch (ItemCollectionException $exception) {
            $response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'empty_fields', 'desc' => 'login, password, email fields are required']
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
        } catch (DbQueryCreatingFailure | \PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'creating_failure', 'desc' => 'problem with creating user record']
                    ]
                ]);

        } finally {
            $response->sendResponse();
        }
    }

}