<?php
function moonshine_form_settings_general(&$form, $theme) {
	$form['general'] = array(
    '#type' => 'details',
    '#title' => t('General'),
		'#weight' => -100,
  );
	$form['general']['moonshine_back_to_top'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Back to Top Arrow'),
    '#default_value' => _moonshine_setting('back_to_top', $theme),
  );
}
