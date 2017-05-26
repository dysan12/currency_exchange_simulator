<?php

namespace Currency\Collections;


interface ICollection
{
    /**
     * Set collection to instance property
     * @param $collection
     * @return mixed
     */
    public function setCollection($collection);

    /**
     * Adding item to collection(if not loaded it creates its ones
     * @param $value
     * @param $index
     * @return mixed
     */
    public function addItem($value, $index);

    /**
     * Get item from collection, if item do not exists throw ItemCollectionException
     * @param $index
     * @return mixed
     */
    public function getItem($index);

    /**
     * @return array - handled collection
     */
    public function getCollection(): array;
}