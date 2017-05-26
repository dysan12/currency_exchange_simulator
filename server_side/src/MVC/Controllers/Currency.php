<?php
/**
 * Created by PhpStorm.
 * User: Michal
 * Date: 2017-05-22
 * Time: 23:02
 */

namespace Currency\MVC\Controllers;


use Currency\MVC\Models;
use Currency\MVC\Response\Response;

class Currency extends AuthorizedController
{
    public function getCurrent()
    {
        $model = new Models\Currency($this->dbConnection);
        $rates = $model->getCurrent();

        $response = new Response('Rates');

        $response
            ->setResponse([
                'data' => json_decode($rates)
            ])
            ->setStatusCode(200)
            ->sendResponse();
    }
}