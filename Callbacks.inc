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
    case 'IsPhoto':
      $itemId = $params['itemId'];
      list ($ret, $item) = GalleryCoreApi::loadEntitiesById($itemId, 'GalleryItem');
      if ($ret) {
        return $ret;
      }
      $isPhoto = GalleryUtilities::isA($item, 'GalleryPhotoItem');
      $block =& $smarty->_tpl_vars['block'];
      if ($isPhoto) {
        $block['flattr']['foobar'] = 'this is probably a photo';
        $urlGenerator  =& $gallery->getUrlGenerator();
        $url = $urlGenerator->generateUrl(
          array('itemId' => $itemId),
          array('htmlEntities' => true,
                'forceFullUrl' => true,
                'forceSessionId' => false));
        $block['flattr']['url'] = $url;
      }
      else {
        $block['flattr']['foobar'] = 'this is probably NOT a photo';
      }        
      $block['flattr']['isPhoto'] = '' . $isPhoto; /* !!$isPhoto; */

      return null;
    }

    return GalleryCoreApi::error(ERROR_BAD_PARAMETER);
  }
}
?>