<?php

namespace Currency\MVC\Controllers;


use Currency\Collections\ArrayCollection;
use Currency\Exceptions\CredentialsException;
use Currency\Exceptions\ItemCollectionException;
use Currency\Exceptions\TokenException;
use Currency\MVC\Models;
use Currency\MVC\Response\Response;

class Authorization extends Controller
{
    public function login()
    {
        $model = new Models\Authorization($this->dbConnection);
        $response = new Response('Authorization process');

        $dataRequest = new ArrayCollection();
        $dataRequest->setCollection($this->globalVars->getItem('dataRequest'));

        try {
            $hashResponse = $dataRequest->getItem('response');
            $realm = $dataRequest->getItem('realm');
            $nonce = $dataRequest->getItem('nonce');
            $methodRequest = $_SERVER['REQUEST_METHOD'];
            $urlRequest = $_SERVER['REQUEST_URI'];

            $userLogin = $model->authCredentials($hashResponse, $realm, $nonce, $methodRequest, $urlRequest);
            [$tokenID, $lifeTime] = $model->generateToken($userLogin);
            $response
                ->setStatusCode(200)
                ->setResponse([
                'data' => [
                    'tokenID' => $tokenID,
                    'lifeTime' => $lifeTime
                ]
            ]);

        } catch (ItemCollectionException $exception) {
            $response
                ->setStatusCode(400)
                ->setResponse([
                    'errors' => [
                        ['id' => 'missing_fields', 'desc' => 'there are some missing fields in the request']
                    ]
                ]);

        } catch (CredentialsException $exception) {
            $response
                ->setStatusCode(401)
                ->setResponse([
                    'errors' => [
                        ['id' => 'invalid_credentials', 'desc' => $exception->getMessage()]
                    ]
                ]);

        } catch (TokenException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('Token generator', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'internal_problem', 'desc' => $exception->getMessage()]
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
}