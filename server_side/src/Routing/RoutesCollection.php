<?php

namespace Currency\Routing;

use Currency\Collections\ICollection;
use Currency\Exceptions\ItemCollectionException;


/**
 * Class RoutesCollection collects routes.
 * @package Currency\Routing
 */
class RoutesCollection implements ICollection
{
    private $collection = [];

    public function setCollection($collection): void
    {
        $this->collection = $collection;
    }

    public function addItem($route, $index = NULL): void
    {
        if($index)
            $this->collection[$index] = $route;
        else
            $this->collection[] = $route;
    }

    public function getItem($index)
    {
        if (isset($this->collection[$index]))
            return $this->collection[$index];

        throw new ItemCollectionException('requested route:"' . $index . '" was not set');
    }

    public function getCollection(): array
    {
        return $this->collection;
    }
}