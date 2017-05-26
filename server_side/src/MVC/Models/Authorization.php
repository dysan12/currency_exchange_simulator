<?php

namespace Currency\MVC\Models;


use Currency\Database\IDbProvider;
use Currency\Exceptions\CredentialsException;
use Currency\Exceptions\TokenException;

/**
 * Class Authorization handle generating tokens. Every token has 20 minutes life. Every use of valid token extend life to
 * another 20 minutes.
 * @package Currency\MVC\Models
 */
class Authorization extends Model
{
    private $dbConnection = null;

    public function __construct(IDbProvider $dbConnection)
    {
        $this->dbConnection = $dbConnection;
    }

    /**
     * Check if provided hash is equal to any credentials from DB. Authentication based on Digest Auth.
     * @param string $response
     * @param string $realm
     * @param string $nonce
     * @param string $methodRequest
     * @param string $urlRequest
     * @return string - name of matched user
     * @throws CredentialsException - throws if provided credentials are invalid
     */
    public function authCredentials(string $response, string $realm, string $nonce, string $methodRequest, string $urlRequest): string
    {
        $hashingAlgorithm = 'sha3-256';

        $sqlQuery = "SELECT login, password FROM users";

        $this->dbConnection->executeQuery($sqlQuery);
        $credentials = $this->dbConnection->getResult();

        foreach ($credentials as $userCredentials) {
            $a1 = hash($hashingAlgorithm, sprintf('%s:%s:%s', $userCredentials['login'], $realm, $userCredentials['password']));
            $a2 = hash($hashingAlgorithm, sprintf('%s:%s', $methodRequest, $urlRequest));
            $resultHash = hash($hashingAlgorithm, sprintf('%s:%s:%s', $a1, $nonce, $a2));

            if ($resultHash === $response) {
                return $userCredentials['login'];
            }
        }
        throw new CredentialsException('provided authentication credentials were invalid');
    }

    /**
     * Check whether random token is not occupied, if so draw another one.
     * @return array - generated token with expiration time ['tokenID' => $tokenID, 'lifeTime' => $lifeTime].
     * @throws TokenException - throws if token was not created.
     */
    public function generateToken(string $userLogin): array
    {
        do{
            $tokenID = md5(random_int(0, PHP_INT_MAX));
            try{
               $this->checkToken($tokenID);
               $isOccupied = 1;
            } catch (TokenException $error) {
                $isOccupied = 0;
            }

        } while (strlen($tokenID) > 128 || $isOccupied);

        $lifeTime = time() + (60 * 20);

        $sqlQuery = sprintf("INSERT INTO `tokens` (id_token, expiration, user_login) VALUES ('%s', '%s', '%s')", $tokenID, $lifeTime, $userLogin);

        if ($this->dbConnection->executeQuery($sqlQuery))
            return ['tokenID' => $tokenID, 'lifeTime' => $lifeTime];

        throw new TokenException('problem with crating new token has arisen');
    }

    /**
     * Check if token is valid or if is expired.
     * @param string $tokenID
     * @return array - token details
     * @throws TokenException - throws if provided token is expired or is invalid.
     */
    public function checkToken(string $tokenID)
    {
        $sqlQuery = "SELECT id_token, expiration, user_login FROM tokens WHERE id_token = :tokenID ";

        $this->dbConnection->executeQuery($sqlQuery, ['tokenID' => $tokenID]);
        $result = $this->dbConnection->getResult();

        if (count($result)) {
            $time = time();
            $time2 = (int)$result['expiration'];
            if ((int)$result['expiration'] > time()) {
                $this->extendToken($tokenID);

                return $result;
            } else {
                $this->deleteToken($tokenID);

                throw new TokenException('provided token has expired');
            }
        }
        throw new TokenException('provided token is invalid');
    }
    /**
     * Extend token life time.
     * @param string $tokenID
     * @return bool
     */
    private function extendToken(string $tokenID): bool
    {
        $lifeTime = time() + (60 * 20);
        $sqlQuery = sprintf("UPDATE `tokens` SET expiration='%s' WHERE id_token='%s'", $lifeTime, $tokenID);

        return $this->dbConnection->executeQuery($sqlQuery);
    }

    /**
     * Delete Token from DB.
     * @param string $tokenID - token ID
     * @return bool
     */
    private function deleteToken(string $tokenID): bool
    {
        $sqlQuery = "DELETE FROM tokens WHERE id_token=:tokenID";

        return $this->dbConnection->executeQuery($sqlQuery, ['tokenID' => $tokenID]);
    }
}