<?php

namespace Currency\Collections;


interface ICollection
{
    public function setCollection($collection);

    public function addItem($value, $index);

    public function getItem($index);

    public function getCollection(): array;
}