<?php
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