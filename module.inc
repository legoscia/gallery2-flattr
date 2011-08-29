<?php
/*
 * Gallery - a web based photo album viewer and editor
 * Copyright (C) 2000-2008 Bharat Mediratta
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
 * @version $Revision$
 * @author Magnus Henoch
 */

/**
 * Flattr
 *
 * Describe your new module here!
 *
 * @package Flattr
 */
class FlattrModule extends GalleryModule {

    function FlattrModule() {
	global $gallery;
	$this->setId('flattr');
	$this->setName($gallery->i18n('Flattr'));
	$this->setDescription($gallery->i18n('My Flattr module'));
	$this->setVersion('1.0.0');
	$this->_templateVersion = 1;
	$this->setCallbacks('getSiteAdminViews');
	$this->setGroup('other', $gallery->i18n('Other'));
	$this->setRequiredCoreApi(array(7, 20));
	$this->setRequiredModuleApi(array(3, 6));
    }

    /**
     * @see GalleryModule::getSiteAdminViews()
     */
    function getSiteAdminViews() {
      return array(
        null,
        array(
          array('name' => $this->translate('Flattr configuration'),
                'view' => 'flattr.Flattr')));
    }
}
?>