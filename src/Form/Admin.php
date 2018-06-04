<?php

namespace Drupal\islandora_jodconverter\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Module settings form.
 */
class Admin extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'islandora_jodconverter_admin_settings_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form = [];
    $config = $this->config('islandora_jodconverter.settings');

    $form['islandora_jodconverter_openoffice_port'] = [
      '#type' => 'number',
      '#title' => $this->t('Openoffice Port'),
      '#default_value' => $config->get('islandora_jodconverter_openoffice_port'),
      '#size' => 150,
      '#required' => TRUE,
    ];
    $form['submit'] = [
      '#type' => 'submit',
      '#value' => $this->t('Save'),
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['islandora_jodconverter.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $config = $this->config('islandora_jodconverter.settings');
    $port = $form_state->getValue('islandora_jodconverter_openoffice_port');
    $config->set('islandora_jodconverter_openoffice_port', $port);
    $config->save();
  }

}
