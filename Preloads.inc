<?php
class FlattrPreloads {
  function preload(&$template, $preload, $paramSet) {
    static $loaded;

    if (!empty($loaded[$preload])) {
      return null;
    }

    $loaded[$preload] = 1;
    $template->javascript('http://api.flattr.com/js/0.6/load.js?mode=auto');
    return null;
  }
}
?>
