<?php
function moonshine_form_settings_reset(&$form, $theme) {
	$form['core'] = array(
    '#type' => 'vertical_tabs',
    '#attributes' => array('class' => array('entity-meta')),
    '#weight' => -899,
   );

  $form['theme_settings']['#group'] = 'core';
  $form['logo']['#group'] = 'core';
  $form['favicon']['#group'] = 'core';
  $form['general']['#group'] = 'core';
  $form['components']['#group'] = 'core';
  $form['social']['#group'] = 'core';

}
