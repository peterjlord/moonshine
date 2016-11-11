<?php
function moonshine_form_settings_develop(&$form, $theme) {
  $develop = _moonshine_setting('develop', $theme);

  $settings['theme'] = $theme;
  //$settings['social'] = $social;
  $settings['parent'] = 'moonshine_social';


  $form['develop'] = array(
    '#type' => 'details',
    '#title' => t('Develop'),
    '#open' => TRUE,
   );
  $form['develop']['development'] = array(
    '#type' => 'details',
    '#title' => t('Development Settings'),
    '#open' => TRUE,
   );
	$form['develop']['moonshine_display_grid'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display Grid'),
    '#default_value' => _moonshine_setting('display_grid', $theme),
	);
}
