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

/**
 * @package Flattr
 * @author  Magnus Henoch <magnus.henoch@gmail.com>
 * @version $Revision$
 */
class FlattrCallbacks {
  function callback($params, &$smarty, $callback, $userId) {
    global $gallery;

    switch ($callback) {
    case 'GetPhoto':
      $itemId = $params['itemId'];
      list ($ret, $item) = GalleryCoreApi::loadEntitiesById($itemId, 'GalleryItem');
      if ($ret) {
        return $ret;
      }
      $isPhoto = GalleryUtilities::isA($item, 'GalleryPhotoItem');
      $block =& $smarty->_tpl_vars['block'];
      if ($isPhoto) {
        $urlGenerator  =& $gallery->getUrlGenerator();
        $url = $urlGenerator->generateUrl(
          array('itemId' => $itemId),
          array('htmlEntities' => true,
                'forceFullUrl' => true,
                'forceSessionId' => false));
        $block['flattr']['url'] = $url;

        list ($ret, $username) = GalleryCoreApi::getPluginParameter('module', 'flattr', 'username');
        if ($ret) {
          return array($ret, null);
        }
        $block['flattr']['username'] = $username;
      }
      $block['flattr']['isPhoto'] = $isPhoto;

      return null;
    }

    return GalleryCoreApi::error(ERROR_BAD_PARAMETER);
  }
}
?>