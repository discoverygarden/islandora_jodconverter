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
  module_load_include('inc', 'islandora_jodconverter', 'includes/utilities');
  $form['format'] = array(
    '#type' => 'fieldset',
    '#title' => t('Document format Configurations'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['format']['islandora_jodconverter_suported_format_tabs'] = array(
    '#type' => 'vertical_tabs',
   );
  
  $families = islandora_jodconverter_get_familis();
  foreach ($families as $family_name => $family) {
    $form['format'][$family_name] = array(
      '#type' => 'fieldset',
      '#title' => t("$family_name Formats"),
      '#collapsible' => TRUE,
      '#group' => 'islandora_jodconverter_suported_format_tabs',
    );
    $form['format'][$family_name]["islandora_jodconverter_$family_name" . "_from"] = array(
      '#type' => 'checkboxes',
      '#options' => drupal_map_assoc($family['from']),
      '#default_value'=>$family['from'],
      '#title' => t('Configure the formats which can be converted from'),
    );
    $form['format'][$family_name]["islandora_jodconverter_$family_name" . "_to"] = array(
      '#type' => 'checkboxes',
      '#options' => drupal_map_assoc($family['to']),
      '#default_value'=>$family['to'],
      '#title' => t('Configure the formats which can be converted To'),
    );
  }
  
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

  return $form;
}

function islandora_jodconverter_admin_settings_form_validate($form, &$form_state){
  // @Todo: validate the port number.
}
function islandora_jodconverter_admin_settings_form_submit($form, &$form_state){
  // @Todo: set the port number.
  module_load_include('inc', 'islandora_jodconverter', 'includes/utilities');
  $families = islandora_jodconverter_get_familis();
  $islandora_jodconverter_families = array();
  foreach (array_keys($families) as $family) {
    $islandora_jodconverter_families[$family] = array(
      'from' => $form_state['values']["islandora_jodconverter_$family" . "_from"],
      'to' => $form_state['values']["islandora_jodconverter_$family" . "_to"]
    );
  }
  variable_set('islandora_jodconverter_families', $islandora_jodconverter_families);
}