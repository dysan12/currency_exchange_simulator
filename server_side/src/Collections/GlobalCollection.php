<?php

namespace Currency\Collections;

use Currency\Exceptions\ItemCollectionException;

class GlobalCollection implements ICollection
{
    protected $collection = [];

    public function setCollection($collection): void
    {
        $this->collection = $collection;
    }

    public function addItem($value, $name): void
    {
        $this->collection[$name] = $value;
    }

    public function getItem($name)
    {
        if (isset($this->collection[$name]))
            return $this->collection[$name];

        throw new ItemCollectionException('requested item:"' . $name . '" was not set');
    }

    public function getCollection(): array
    {
        return $this->collection;
    }

}