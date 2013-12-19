<?php
/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_jodconverter_admin_settings_form() {
  $form = array();
  
  $form['islandora_jodconverter_openoffice_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Openoffice Port'),
    '#default_value' => variable_get('islandora_jodconverter_openoffice_port'),
    '#size' => 150,
    '#required' => TRUE,
  );  
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

  return $form;
}

function islandora_jodconverter_admin_settings_form_validate($form, &$form_state){
  // @Todo: validate the port number.
}
function islandora_jodconverter_admin_settings_form_submit($form, &$form_state){
  // @Todo: set the port number.
}