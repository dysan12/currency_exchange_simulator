<?php

namespace Currency\MVC\Response;

/**
 * Class Response handle with setting up and sending HTTP response. Using fluent interface.
 * @package Currency\MVC\Response
 */
class Response
{
    protected $response;
    protected $statusCode;

    public function __construct(string $header = '')
    {
        if (strlen($header))
            $this->setHeader($header);
    }

    public function setHeader(string $header): self
    {
        $this->response['header'] = $header;

        return $this;
    }

    public function setResponse($response): self
    {
        $this->response['response'] = $response;

        return $this;
    }

    /**
     * Convert conveyed status code into version with textual description and save it to statusCode property.
     * @param int $statusCode
     * @return Response
     */
    public function setStatusCode(int $statusCode): self
    {
        $this->statusCode = $this->getStatusCodeFullVersion($statusCode);

        return $this;
    }

    /**
     * Set appropriate headers and send response in JOSN format.
     */
    public function sendResponse()
    {
        header($_SERVER['SERVER_PROTOCOL'] . ' ' . $this->statusCode, true);
        header('Content-Type: application/json');
        echo json_encode($this->response);
        exit();
    }

    /**
     * Return code and textual phrase of status code.
     * @param $statusCode
     * @return string - full version of status code (code + textual phrase).
     */
    private function getStatusCodeFullVersion($statusCode)
    {
        switch ($statusCode)
        {
            case 200:
                $fullVersion = '200 OK';
                break;
            case 201:
                $fullVersion = '201 Created';
                break;
            case 204:
                $fullVersion = '204 No Content';
                break;
            case 400:
                $fullVersion = '400 Bad Request';
                break;
            case 401:
                $fullVersion = '401 Unauthorized ';
                break;
            case 403:
                $fullVersion = '403 Forbidden';
                break;
            case 404:
                $fullVersion = '404 Not Found';
                break;
            case 500:
                $fullVersion = '500 Internal Server Error';
                break;
        }
        return $fullVersion ?? '200 OK';
    }
}