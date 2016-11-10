<?php
/**
 * Retrieves a setting for the current theme or for a given theme.
 *
 * This is a wrapper for theme_get_setting(), ensuring to use deprecated
 * setting values instead.
 *
 * @param string $name
 *   The name of the setting to be retrieved.
 * @param string $theme
 *   The name of a given theme; defaults to the currently active theme.
 * @param string $prefix
 *   The prefix used on the $name of the setting, this will be appended with
 *   "_" automatically if set.
 *
 * @return mixed
 *   The value of the requested setting, NULL if the setting does not exist.
 *
 * @see theme_get_setting()
 */
use Drupal\file\Entity\File;
use Drupal\Component\Utility\Html;

function _moonshine_setting($name, $theme = NULL, $prefix = 'moonshine') {
  $prefix = !empty($prefix) ? $prefix . '_' : '';
  $setting = theme_get_setting($prefix . $name, $theme);
  return $setting;
}

function _moonshine_camelcase($str, $noStrip =[]) {
  // non-alpha and non-numeric characters become spaces
  $str = preg_replace('/[^a-z0-9' . implode("", $noStrip) . ']+/i', ' ', $str);
  $str = trim($str);
  // uppercase the first character of each word
  $str = ucwords($str);
  $str = str_replace(" ", "", $str);
  $str = lcfirst($str);

  return $str;
}


