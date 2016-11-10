<?php
function moonshine_form_settings_components(&$form, $theme) {
 $form['components'] = array(
    '#type' => 'details',
    '#title' => t('Components'),
		'#open' => TRUE,
    '#weight' => -100,
  );
  $form['components']['breadcrumbs']['moonshine_breadcrumb'] = array(
    '#type' => 'select',
    '#title' => t('Breadcrumb visibility'),
    '#default_value' => _moonshine_setting('breadcrumb', $theme),
    '#options' => array(
      0 => t('Hidden'),
      1 => t('Visible'),
      2 => t('Only in admin areas'),
    ),
  );
  $form['components']['breadcrumbs']['moonshine_breadcrumb_home'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show "Home" breadcrumb link'),
    '#default_value' => _moonshine_setting('breadcrumb_home', $theme),
    '#description' => t('If your site has a module dedicated to handling breadcrumbs already, ensure this setting is enabled.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="moonshine_breadcrumb"]' => array('value' => 0),
      ),
    ),
  );
  $form['components']['breadcrumbs']['moonshine_breadcrumb_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show current page title at end'),
    '#default_value' => _moonshine_setting('breadcrumb_title', $theme),
    '#description' => t('If your site has a module dedicated to handling breadcrumbs already, ensure this setting is disabled.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="moonshine_breadcrumb"]' => array('value' => 0),
      ),
    ),
  );
  $form['components']['breadcrumbs']['moonshine_breadcrumb_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix text'),
    '#description' => t('Enter the prefix text for breadcrumbs.'),
    '#default_value' => _moonshine_setting('breadcrumb_text', $theme),
  );
	
}
