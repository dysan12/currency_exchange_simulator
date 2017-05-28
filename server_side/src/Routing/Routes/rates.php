<?php

$routesCollection->addItem(new Currency\Routing\Route('getRateCollection', '/rates/?', [
    'type' => 'collection',
    'requestMethod' => 'GET',
    'controllerSet' => ['Rates', 'getRateCollection']
]));

$routesCollection->addItem(new Currency\Routing\Route('getRate', '/rates/(\d{4}-\d{2}-\d{2}|current)', [
    'type' => 'resource',
    'requestMethod' => 'GET',
    'controllerSet' => ['Rates', 'getRate']
]));
