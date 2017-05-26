<?php

namespace Tests;

use Currency\Routing\Route;
use PHPUnit\Framework\TestCase;

class RouteTest extends TestCase
{
    public function testFilterAvailability_WithVarietyRoutesTypes_ReturnsCorrectly()
    {
        $route = new Route('TestingRoute', 'test/world', ['type' => 'collection']);

        $this->assertEquals(1, $route->isFilterEnabled());

        $route->setType('resource');
        $this->assertEquals(0, $route->isFilterEnabled());
    }


}