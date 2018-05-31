<?php
namespace Drupal\islandora_jodconverter;

class IslandoraJodconverterAdminSettingsForm extends FormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'islandora_jodconverter_admin_settings_form';
  }

  public function buildForm(array $form, \Drupal\Core\Form\FormStateInterface $form_state) {
    $form = [];

    // @FIXME
    // Could not extract the default value because it is either indeterminate, or
    // not scalar. You'll need to provide a default value in
    // config/install/islandora_jodconverter.settings.yml and config/schema/islandora_jodconverter.schema.yml.
    $form['islandora_jodconverter_openoffice_port'] = [
      '#type' => 'textfield',
      '#title' => t('Openoffice Port'),
      '#default_value' => \Drupal::config('islandora_jodconverter.settings')->get('islandora_jodconverter_openoffice_port'),
      '#size' => 150,
      '#required' => TRUE,
    ];
    $form['submit'] = ['#type' => 'submit', '#value' => t('Save')];

    return $form;
  }

  public function validateForm(array &$form, \Drupal\Core\Form\FormStateInterface $form_state) {
    $port = $form_state->getValue(['islandora_jodconverter_openoffice_port']);
    if (!preg_match('/^[0-9]*$/', $port)) {
      $form_state->setError($form['islandora_jodconverter_openoffice_port'], t('port should be a ingeter value'));
    }
  }

  public function submitForm(array &$form, \Drupal\Core\Form\FormStateInterface $form_state) {
    $port = !$form_state->getValue(['islandora_jodconverter_openoffice_port']) ? $form_state->getValue(['islandora_jodconverter_openoffice_port']) : 8100;
    $port = intval($port);
    \Drupal::configFactory()->getEditable('islandora_jodconverter.settings')->set('islandora_jodconverter_openoffice_port', $port)->save();
  }

}
