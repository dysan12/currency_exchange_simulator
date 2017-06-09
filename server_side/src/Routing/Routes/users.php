<?php



$routesCollection->addItem(new Currency\Routing\Route('userDetails', '/users/([\w%-]{1,40})', [
    'type' => 'collection',
    'requestMethod' => 'GET',
    'controllerSet' => ['Users', 'getUserDetails']
]));

$routesCollection->addItem(new Currency\Routing\Route('modifyUser', '/users/([\w%-]{1,40})', [
    'type' => 'resource',
    'requestMethod' => 'PUT',
    'controllerSet' => ['Users', 'modifyUser']
]));

$routesCollection->addItem(new Currency\Routing\Route('deleteUser', '/users/([\w%-]{1,40})', [
    'type' => 'resource',
    'requestMethod' => 'DELETE',
    'controllerSet' => ['Users', 'deleteUser']
]));

$routesCollection->addItem(new Currency\Routing\Route('createUser', '/users/?', [
    'type' => 'collection',
    'requestMethod' => 'POST',
    'controllerSet' => ['UsersRestricted', 'createUser']
]));
