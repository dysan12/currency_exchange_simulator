<?php declare(strict_types=1);

use PHPUnit\Framework\TestCase;

class DataRenderingTest extends TestCase
{
    private $routeMatching;


    public function setUp()
    {
        $collection = new Currency\Routing\RoutesCollection();

        $collection->addItem(new Currency\Routing\Route('getUser', '/users/([\w%-]{1,30})', [
            'type' => 'resource',
            'requestMethod' => 'GET'
        ]));
        $collection->addItem(new Currency\Routing\Route('newUser', '/users', [
            'type' => 'collection',
            'requestMethod' => 'POST'
        ]));
    }
    /**
     * @dataProvider arrayWithUrlsNVariables
     */
    public function testIf_RenderURLDataReturnsAllData(string $url, array $result, Currency\Routing\IRoute $route)
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