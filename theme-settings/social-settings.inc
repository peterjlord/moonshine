<?php
function moonshine_form_settings_social(&$form, $theme) {
	$social = _moonshine_setting('social', $theme);

	$settings['theme'] = $theme;
  $settings['social'] = $social;
  $settings['parent'] = 'moonshine_social';


	$form['social'] = array(
    '#type' => 'details',
    '#title' => t('Social'),
    '#open' => TRUE,
   );
  $form['social']['social-networks'] = array(
    '#type' => 'details',
    '#title' => t('Social Networks'),
    '#open' => TRUE,
   );
	$form['social']['social-networks']['the-links'] = array(
    '#type' => 'details',
    '#title' => t('Links'),
    '#open' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="socials_display"]' => array('checked' => TRUE),
      ),
    ),
  );
  $settings['link'] = 'Facebook';
  moonshine_form_theme_social_link($form['social']['social-networks']['the-links'], $settings);

  $settings['link'] = 'Twitter';
  moonshine_form_theme_social_link($form['social']['social-networks']['the-links'], $settings);

  $settings['link'] = 'Google+';
  moonshine_form_theme_social_link($form['social']['social-networks']['the-links'], $settings);

  $settings['link'] = 'LinkedIn';
  moonshine_form_theme_social_link($form['social']['social-networks']['the-links'], $settings);

  $settings['link'] = 'Reddit';
  moonshine_form_theme_social_link($form['social']['social-networks']['the-links'], $settings);

  $settings['link'] = 'Youtube';
  moonshine_form_theme_social_link($form['social']['social-networks']['the-links'], $settings);
}


function moonshine_form_theme_social_link(&$form, $settings) {
  $camelCaseLink= _moonshine_camelcase($settings['link']);
  $theme = $settings['theme'];
  $socialLink= isset($settings['social'][$camelCaseLink]) ? $settings['social'][$camelCaseLink] : '';
  $form[$camelCaseLink] = array(
    '#type' => 'textfield',
    '#title' => t(ucfirst($camelCaseLink)),
    '#parents' => array( $settings['parent'], $camelCaseLink ),
    '#default_value' => $socialLink,
  );
	//ksm($form);
}
                                                                                        
