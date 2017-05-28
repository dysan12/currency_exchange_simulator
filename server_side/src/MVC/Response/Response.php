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

    /**
     * Set header included JSON response
     * @param string $header - content of header
     * @return Response
     */
    public function setHeader(string $header): self
    {
        $this->response['header'] = $header;

        return $this;
    }

    /**
     * Set response included in JSON
     * @param $response - content
     * @return Response
     */
    public function setResponse($response): self
    {
        $this->response['response'] = $response;

        return $this;
    }

    public function getStatusCode(): string
    {
        return $this->statusCode;
    }
    /**
     * Convert conveyed status code into version with textual description and save it to statusCode property.
     * @param int $statusCode
     * @return Response
     */
    public function setStatusCode(int $statusCode): self
    {
        $this->statusCode = $this->getStatusCodeWithText($statusCode);

        return $this;
    }

    /**
     * Set appropriate headers send response in JOSN format and finish script.
     */
    public function sendResponse()
    {
        header($_SERVER['SERVER_PROTOCOL'] . ' ' . $this->statusCode, true);
        header('Content-Type: application/json');
        echo json_encode($this->response);
        exit();
    }

    /**
     * Return code with textual phrase of status code.
     * @param int $code - status code
     * @return string - complete version of status code (code + textual phrase).
     */
    private function getStatusCodeWithText(int $code)
    {
        $statusCodes = [
            200 => 'OK',
            201 => 'Created',
            204 => 'No Content',
            400 => 'Bad Request',
            401 => 'Unauthorized',
            403 => 'Forbidden',
            404 => 'Not Found',
            500 => 'Internal Server Error'
        ];

        if (array_key_exists($code, $statusCodes))
            return $code . ' ' . $statusCodes[$code];

        return '200 OK';
    }
}