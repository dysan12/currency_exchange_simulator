<?php

namespace Tests;

use Currency\Database\IDbProvider;
use Currency\MVC\Models\Authorization;
use PHPUnit\Framework\TestCase;

class LoggingTest extends TestCase
{
    protected $authObj;

    public function setUp()
    {
        $dbStub = $this->createMock(IDbProvider::class);
        $dbStub->method('getResult')
            ->willReturn([
                ['login' => 'qwerty', 'password' => '123456'],
                ['login' => '123456789', 'password' => 'qwerty']
            ]);

        $this->authObj = new Authorization($dbStub);
    }

    /**
     * @dataProvider arrayCredentials
     */
    public function testCheckingIf_AuthCredentials_WillReturnTrueWithCorrectData(string $login, string $password)
    {
        $hashingAlgorithm = 'sha3-256';

        $realm = 'provide credentials';
        $nonce = '123456789';
        $methodRequest = 'POST';
        $urlRequest = 'login';

        $a1 = hash($hashingAlgorithm, sprintf('%s:%s:%s', $login, $realm, $password));
        $a2 = hash($hashingAlgorithm, sprintf('%s:%s', $methodRequest, $urlRequest));
        $resultHash = hash($hashingAlgorithm, sprintf('%s:%s:%s', $a1, $nonce, $a2));

        $result = $this->authObj->authCredentials($resultHash, $realm, $nonce, $methodRequest, $urlRequest);

        $this->assertEquals($login, $result);
    }

    public function arrayCredentials()
    {
        return [
            ['qwerty', '123456'],
            ['123456789', 'qwerty']
        ];
    }
}