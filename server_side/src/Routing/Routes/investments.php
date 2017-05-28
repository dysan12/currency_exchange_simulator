<?php

$routesCollection->addItem(new Currency\Routing\Route('getUserInvestments', '/investments/([\w%-]{1,40})&([\w%-]{1,200})', [
    'type' => 'resource',
    'requestMethod' => 'GET',
    'controllerSet' => ['Investments', 'getInvestment']
]));

$routesCollection->addItem(new Currency\Routing\Route('modifyInvestment', '/investments/([\w%-]{1,40})&([\w%-]{1,200})', [
    'type' => 'resource',
    'requestMethod' => 'PUT',
    'controllerSet' => ['Investments', 'modifyInvestment']
]));

$routesCollection->addItem(new Currency\Routing\Route('deleteInvestment', '/investments/([\w%-]{1,40})&([\w%-]{1,200})', [
    'type' => 'resource',
    'requestMethod' => 'DELETE',
    'controllerSet' => ['Investments', 'deleteInvestment']
]));

$routesCollection->addItem(new Currency\Routing\Route('createInvestment', '/investments/?', [
    'type' => 'collection',
    'requestMethod' => 'POST',
    'controllerSet' => ['Investments', 'createInvestment']
]));

$routesCollection->addItem(new Currency\Routing\Route('getUserInvestments', '/investments/?', [
    'type' => 'collection',
    'requestMethod' => 'GET',
    'controllerSet' => ['Investments', 'getInvestments']
]));