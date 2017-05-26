<?php

namespace Tests;

use Currency\Collections\GlobalCollection;
use Currency\Exceptions\ItemCollectionException;
use PHPUnit\Framework\TestCase;

class GlobalCollectionTest extends TestCase
{
    public function testExtractDataCollection_IfThereIsNoSuchElement_ThrowException()
    {
        $this->expectException(ItemCollectionException::class);

        $collection = new GlobalCollection();

        $collection->getItem('whatever');
    }

    public function testExtractDataCollection_IfThereIsSuchElement_ReturnElement()
    {
        $expectedValue = 'works';
        $collection = new GlobalCollection();

        $collection->setCollection(['whatever' => $expectedValue]);

        $this->assertEquals($expectedValue, $collection->getItem('whatever'));
    }
}