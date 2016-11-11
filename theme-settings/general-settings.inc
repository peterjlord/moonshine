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
	$form['general']['footer']['footer-links'] = array(
    '#type' => 'details',
    '#title' => t('Footer Links'),
    '#open' => TRUE,
	);

  $footer_copy = _ms_setting('footer_copy', $theme);
	$form['general']['footer']['moonshine_footer_copy'] = array(
    '#type' => 'textfield',
    '#title' => t("Footer Copyright"),
    '#default_value' => $footer_copy,
	);

   $footer_links = _ms_setting('footer-links', $theme);
	
	 $settings['theme'] = $theme;
   $settings['footer_links'] = $footer_links;
   $settings['parent'] = 'moonshine_footer-links';

   $settings['link'] = 'Link1';
   _moonshine_form_theme_footer_link($form['general']['footer']['footer-links'], $settings);

   $settings['link'] = 'Link2';
   _moonshine_form_theme_footer_link($form['general']['footer']['footer-links'], $settings);


}
function _moonshine_form_theme_footer_link(&$form, $settings) {
  $camelCaseLink= _moonshine_camelcase($settings['link']);
  $theme = $settings['theme'];
  $linkTitle= isset($settings['footer_links'][$camelCaseLink]) ? $settings['footer_links'][$camelCaseLink] : '';
  $linkUrl= isset($settings['footer_links'][$camelCaseLink. '_url']) ? $settings['footer_links'][$camelCaseLink . '_url'] : '';
  $form[$camelCaseLink] = array(
    '#type' => 'textfield',
    '#title' => t(ucfirst($camelCaseLink)),
    '#parents' => array( $settings['parent'], $camelCaseLink  ),
    '#default_value' => $linkTitle,
  );
  $form[$camelCaseLink . '_url'] = array(
    '#type' => 'textfield',
    '#title' => t(ucfirst($camelCaseLink). ' URL'),
    '#parents' => array( $settings['parent'], $camelCaseLink . '_url'  ),
    '#default_value' => $linkUrl,
  );
}

