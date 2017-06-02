<?php

namespace Currency\MVC\Controllers;


use Currency\Collections\ArrayCollection;
use Currency\Collections\ICollection;
use Currency\Exceptions\ItemCollectionException;
use Currency\Exceptions\TokenException;
use Currency\MVC\Models;
use Currency\MVC\Response\Response;

/**
 * Class AuthorizedController abstract class for actions which require authorization. Check if provided token is valid.
 * @package Currency\MVC\Controllers
 */
abstract class AuthorizedController extends Controller
{
    protected $token;

    /**
     * AuthorizedController constructor.
     * Generates response accordingly(code - reason):
     *      401 - if token were not passed with request / token is invalid
     * @param ICollection $globalVarsCollection
     */
    public function __construct(ICollection $globalVarsCollection)
    {
        parent::__construct($globalVarsCollection);

        $dataRequest = new ArrayCollection();
        $dataRequest->setCollection($this->globalVars->getItem('dataRequest'));

        $response = new Response('Token authorization');

        try {
            $tokenID = $dataRequest->getItem('tokenID');
            $authObj = new Models\Authorization($this->dbConnection);
            $this->token = $authObj->checkToken($tokenID);

        } catch (ItemCollectionException $exception) {
            $response
                ->setResponse([
                    'errors' => [
                        ['id' => 'token_not_provided', 'desc' => 'authorization token were not provided with request']
                    ]
                ])
                ->setStatusCode(401)
                ->sendResponse();

        } catch (TokenException $exception) {
            $response
                ->setResponse([
                    'errors' => [
                        ['id' => 'token_error', 'desc' => $exception->getMessage()]
                    ]
                ])
                ->setStatusCode(401)
                ->sendResponse();

        }
    }
}