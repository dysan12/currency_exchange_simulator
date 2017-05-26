<?php

use PHPUnit\Framework\TestCase;

class DataRenderingTest extends TestCase
{
    /**
     * @dataProvider arrayWithUrlsNVariables
     */
    public function testRenderingFromUrl_WithSpecificUrl_ReturnsAllIncludedData(string $url, array $result, Currency\Routing\IRoute $route)
    {
        $dataRender = new Currency\Routing\DataRendering();
        $this->assertEquals($result, $dataRender->renderFromUrl($url, $route));
    }

    public function arrayWithUrlsNVariables()
    {
        return [
            [
                '/users?order_by=name&set=3&chunk=15',
                ['order_by' => 'name', 'set' => '3', 'chunk' => '15', 'details' => []],
                new Currency\Routing\Route('user', '/users', ['type' => 'collection'])
            ],
            [
                '/users/dysan?order=name',
                ['details' => ['dysan']],
                new Currency\Routing\Route('getUser', '/users/([\w%-]{1,30})', ['type' => 'resource'])
            ]
        ];
    }
}