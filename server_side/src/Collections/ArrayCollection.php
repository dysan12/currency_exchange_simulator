<?php

namespace Currency\Collections;

use Currency\Exceptions\ItemCollectionException;


class ArrayCollection implements ICollection
{
    protected $collection = [];

    public function setCollection($collection): void
    {
        $this->collection = $collection;
    }

    public function addItem($value, $index): void
    {
        $this->collection[$index] = $value;
    }

    public function getItem($index)
    {
        if (isset($this->collection[$index]))
            return $this->collection[$index];

        throw new ItemCollectionException('requested item:"' . $index . '" was not set');
    }

    public function getCollection(): array
    {
        return $this->collection;
    }
}