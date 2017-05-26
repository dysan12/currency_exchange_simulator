<?php
/**
 * Created by PhpStorm.
 * User: Michal
 * Date: 2017-05-22
 * Time: 21:06
 */

namespace Currency\Database;

use Currency\CustomInterfaces\ICreator;
use Currency\Exceptions\DbProviderException;

class DbCreator implements ICreator
{
    public function create(string $provider): IDbProvider
    {
        $className = 'Currency\Database\\' . $provider;
        if (class_exists($className)) {
            return new $className();
        }
        throw new DbProviderException('Provider "' . $provider . '" is not implemented yet.');
    }
}