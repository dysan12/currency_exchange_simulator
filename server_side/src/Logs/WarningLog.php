<?php

namespace Currency\Logs;


class WarningLog implements ILog
{
    /**
     * Save message to warnings.log file. Format: [DATE][MODULE]Message-File-Code-Line
     * @param string $module - name of module where problem occurred
     * @param \Exception $exception - instance of arose exception
     */
    public function saveMessage(string $module, \Exception $exception): void
    {
        $errorContent = "[" . date("d-m-Y H:i:s") . "]" . "[" . $module . "] " . $exception->getMessage() . " - File:" . $exception->getFile() . " - Code:" . $exception->getCode() . " - Line:" . $exception->getLine() . "\n";

        file_put_contents( LOGS_DIR . 'warnings.log', $errorContent, FILE_APPEND);

    }
}