<?php

namespace Currency\Collections;

use Currency\Exceptions\ItemCollectionException;

class GlobalCollection implements ICollection
{
    protected $collection;

    public function setCollection($collection)
    {
        $this->collection = $collection;
    }

    public function addItem($value, $name)
    {
        $this->collection[$name] = $value;
    }

    /**
     * @param $name
     * @return mixed
     * @throws ItemCollectionException
     */
    public function getItem($name)
    {
        if (isset($this->collection[$name]))
            return $this->collection[$name];

        throw new ItemCollectionException('requested item:"' . $name . '" was not set');;
    }

    public function getCollection(): array
    {
        return $this->collection;
    }

}