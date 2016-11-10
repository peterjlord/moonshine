<?php
function moonshine_form_settings_general(&$form, $theme) {
	$form['general'] = array(
    '#type' => 'details',
    '#title' => t('General'),
		'#weight' => -100,
  );
  $form['general']['container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Container'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
}
