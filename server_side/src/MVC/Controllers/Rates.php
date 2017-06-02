<?php
/**
 * Created by PhpStorm.
 * User: Michal
 * Date: 2017-05-22
 * Time: 23:02
 */

namespace Currency\MVC\Controllers;


use Currency\Collections\ArrayCollection;
use Currency\Exceptions\DbQueryNoResultsException;
use Currency\MVC\Models;
use Currency\MVC\Response\Response;

/**
 * Class Rates controller for receiving rates
 * @package Currency\MVC\Controllers
 */
class Rates extends Controller
{
    /**
     * Get collection of rates
     * Generates response accordingly(code - reason):
     *      200 - if collection is returned
     *      500 - if problem with executing query occur
     */
    public function getRateCollection()
    {
        $response = new Response('Rate Collection');

        try {
            $model = new Models\Rates($this->dbConnection);
            $collection = $model->getRateCollection();
            $response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $collection,
                    'messages' => [
                        ['id' => 'rates_collection', 'desc' => 'rates collection in response']
                    ]
                ]);
        } catch (\PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'query_issue', 'desc' => 'problem with executing query occurred']
                    ]
                ]);
        } finally {
            $response->sendResponse();
        }
    }

    public function getRate()
    {
        $dataRequest = new ArrayCollection();
        $dataRequest->setCollection($this->globalVars->getItem('dataRequest'));

        $rateDetail = $dataRequest->getItem('details')[0];
        $response = new Response('Rate Detail');

        try {
            $model = new Models\Rates($this->dbConnection);

            if ($rateDetail === 'current')
                $rates = $model->getLastRate();
            else
                $rates = $model->getRateByData($rateDetail);

            $response
                ->setStatusCode(200)
                ->setResponse([
                    'data' => $rates,
                    'messages' => [
                        ['id' => 'rate_details', 'desc' => 'rate details in response']
                    ]
                ]);
        } catch (DbQueryNoResultsException $exception) {
            $response
                ->setStatusCode(404)
                ->setResponse([
                    'errors' => [
                        ['id' => 'no_results', 'desc' => 'requested rate is not stored in DB']
                    ]
                ]);
        } catch (\PDOException $exception) {
            $this->logsCreator->create('Warning')->saveMessage('PDO query', $exception);
            $response
                ->setStatusCode(500)
                ->setResponse([
                    'errors' => [
                        ['id' => 'query_issue', 'desc' => 'problem with executing query occurred']
                    ]
                ]);
        } finally {
            $response->sendResponse();
        }


    }

}