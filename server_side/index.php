<?php

require 'vendor/autoload.php';
require 'config.php';
require 'src/Routing/Routes/initRoutes.php';

$globalVarsCollection = new \Currency\Collections\GlobalCollection();
$logsCreator = new Currency\Logs\LogsCreator();

$router = new Currency\Routing\Router($routesCollection, $globalVarsCollection, $logsCreator);
preg_match('/(?:currency)(.{0,70})/', $_SERVER['REQUEST_URI'], $matches);
$url = explode('/', $_SERVER['REQUEST_URI']);
$router->run($matches[1], $_SERVER['REQUEST_METHOD']);
$route = $router->getMatchedRoute();
$controllerPath = 'Currency\MVC\Controllers\\' . $route->getControllerName();
$controller = new $controllerPath($globalVarsCollection, $logsCreator);
$controller->{$route->getControllerMethod()}();