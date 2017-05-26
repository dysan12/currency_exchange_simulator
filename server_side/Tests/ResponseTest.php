<?php


class ResponseTest extends \PHPUnit\Framework\TestCase
{
    /**
     * @dataProvider arrayWithCodesAndItsTextualRepresentations
     */
    public function testTextStatusCode_WithDefinedCode_ReturnsProperString(int $code, string $txtRep)
    {
        $response = new \Currency\MVC\Response\Response();

        $response->setStatusCode($code);

        assertEquals($txtRep, $response->getStatusCode());
    }

    public function arrayWithCodesAndItsTextualRepresentations()
    {
        return [
            [200, '200 OK'],
            [204, '204 No Content'],
            [500, '500 Internal Server Error']
        ];
    }

    public function testTextStatusCode_WithUnDefinedCode_ReturnsStatus200()
    {
        $response = new \Currency\MVC\Response\Response();

        $response->setStatusCode(4343);

        assertEquals('200 OK', $response->getStatusCode());
    }


}