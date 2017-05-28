<?php
$routeFiles = ['users','rates', 'main', 'investments'];

$routesCollection = new Currency\Routing\RoutesCollection();

foreach ($routeFiles as $file) {
    require_once($file . '.php');
}