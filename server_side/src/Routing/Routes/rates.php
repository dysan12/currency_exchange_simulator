<?php

$routesCollection->addItem(new Currency\Routing\Route('Currency', '/currency/?', [
    'type' => 'action',
    'requestMethod' => 'GET',
    'controllerSet' => ['Currency', 'getCurrent']
]));