<?php

$routesCollection->addItem(new Currency\Routing\Route('login', '/login/?', [
    'type' => 'action',
    'requestMethod' => 'POST',
    'controllerSet' => ['Authorization', 'login']
]));

$routesCollection->addItem(new Currency\Routing\Route('404 page', '/404/?', [
    'type' => 'site',
    'requestMethod' => 'GET',
    'controllerSet' => ['Others', 'returnNotFound']
]));