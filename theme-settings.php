<?php
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;
use Drupal\Component\Serialization\Json;
use GuzzleHttp\Exception\RequestException;

/**
 * Implements hook_form_FORM_ID_alter().
 */
function moonshine_form_system_theme_settings_alter(&$form, FormStateInterface $form_state, $form_id = NULL) {
	$theme = \Drupal::theme()->getActiveTheme()->getName();
	include_once(drupal_get_path('theme', $theme) . '/includes/functions.inc');
	include_once(drupal_get_path('theme', $theme) . '/theme-settings/general-settings.inc');
	include_once(drupal_get_path('theme', $theme) . '/theme-settings/component-settings.inc');
	include_once(drupal_get_path('theme', $theme) . '/theme-settings/social-settings.inc');
	include_once(drupal_get_path('theme', $theme) . '/theme-settings/develop-settings.inc');
	include_once(drupal_get_path('theme', $theme) . '/theme-settings/reset.inc');

	moonshine_form_settings_general($form, $theme);
	moonshine_form_settings_components($form, $theme);
	moonshine_form_settings_social($form, $theme);
	moonshine_form_settings_develop($form, $theme);
	moonshine_form_settings_reset($form, $theme);

}
