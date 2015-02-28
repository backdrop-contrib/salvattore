<?php

/**
 * @file
 * Provide administration of PACE module.
 */

function salvattore_settings_form() {
  $config = config('salvattore.settings');

  $form = array();

  $form['salvattore_use_min_js'] = array(
    '#title' => t('Javascript file to use'),
    '#description' => t('Please choose whether you want the minified or the full version of the JS file.'),
    '#type' => 'radios',
    '#options' => array(
      '1' => 'Minified',
      '0' => 'Full (debug)',
    ),
    '#default_value' => $config->get('salvattore_use_min_js'),
  );


  $form['salvattore_load_default_css'] = array(
    '#title' => t('Load default CSS'),
    '#description' => t('Salvattore is easily configurable via CSS and you should write your own in your theme.<br>If some reason you want to use the default then enable this setting.'),
    '#type' => 'checkbox',
    '#default_value' => $config->get('salvattore_load_default_css'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for salvattore_settings_form().
 */
function salvattore_settings_form_submit($form, &$form_state) {
  $config = config('salvattore.settings');
  $config->set('salvattore_use_min_js', $form_state['values']['salvattore_use_min_js']);
  $config->set('salvattore_load_default_css', $form_state['values']['salvattore_load_default_css']);
  $config->save();
  backdrop_set_message(t('Salvattore configuration has been saved.'));
}
