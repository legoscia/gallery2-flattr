<?php
/*
 * Flattr Gallery2 plugin
 * Copyright (C) 2011 Erlang Solutions Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA  02110-1301, USA.
 */

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
