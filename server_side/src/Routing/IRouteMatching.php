<?php

namespace Currency\Routing;


interface IRouteMatching
{
    public function matchRouteByUrl(string $url, string $requestMethod): IRoute;

    public function matchRouteByName(string $name, string $requestMethod): IRoute;

    public function getMostSimilarRoute(string $url): IRoute;

}