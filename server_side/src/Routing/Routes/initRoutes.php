<?php
$routeFiles = ['users', 'rates', 'main'];

$routesCollection = new Currency\Routing\RoutesCollection();

foreach ($routeFiles as $file) {
    require_once($file . '.php');
}