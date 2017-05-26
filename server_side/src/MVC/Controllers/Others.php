<?php
namespace Currency\MVC\Controllers;


use Currency\MVC\Response\Response;

class Others extends Controller
{
    public function returnNotFound()
    {
        $similarRoute = $this->globalVars->getItem('similarRoute');

        $sugMethod = $similarRoute->getRequestMethod();
        $sugUrl = $similarRoute->getUrl();

        $response = new Response('Invalid request');
        $response
            ->setStatusCode(404)
            ->setResponse([
                'errors' => [
                    ['id' => 'invalid_request', 'desc' => 'method or url of request are invalid']
                ],
                'messages' => [
                    ['id' => 'similar_request', 'desc' => 'url: ' . $sugUrl . ' method: '. $sugMethod]
                ]
            ])
            ->sendResponse();

    }
}