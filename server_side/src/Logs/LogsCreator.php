<?php

namespace Currency\Logs;

use Currency\CustomInterfaces\ICreator;

class LogsCreator implements ICreator
{
    /**
     * Create instance of ILog
     * @param string $class - class of logs [Error, Warning etc.]
     * @return ILog
     */
    public function create(string $class): ILog
    {
        $namespace = 'Currency\Logs\\';
        $logType = $namespace . $class . 'Log';
        if (class_exists($logType))
            return new $logType();

        return new ErrorLog();
    }
}