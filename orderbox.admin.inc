<?php

/**
 * @file
 * Settings for the Orderbox Settings.
 *
 * @author: Adolfo G. Nasol http://drupal.org/user/547004
 *
 */

function orderbox_settings() {
  $form = array();
 
  $form['orderbox_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('HTTP API Authentication'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
  );
  $form['orderbox_settings']['orderbox_reseller_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Reseller ID'),
    '#default_value' => variable_get('orderbox_reseller_id'),
    '#description' => t('To get your Reseller Id, login from within your Reseller Control Panel.<br />Go to <strong>Settings -> Personal Information</strong> and then click <strong>Primary Profile</strong>. The first field is your Reseller Id.'),
    '#required' => TRUE,
  );
  $form['orderbox_settings']['orderbox_reseller_password'] = array(
    '#type' => 'password', 
    '#title' => t('Authentication Password'),
    '#default_value' => variable_get('orderbox_reseller_password'),
    '#description' => t('This is your Reseller Password and is needed for making HTTP API request to Orderbox/Logicboxes mini ERP system.'),
    '#required' => TRUE,
  );
  
  if(module_exists('orderbox_domains') && (!variable_get('orderbox_reseller_password'))) {
      drupal_set_message(t('To be able send request through Orderbox HTTP API, please set your Authentication Password'), 'warning');
  } else {
     drupal_set_message(t('Ordebox Authentication Password was configured and set.'), 'status');
  }
  
  if(module_exists('orderbox_login')) {
      
  $form['orderbox_login_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Login Configuration'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
  );
  $form['orderbox_login_settings']['orderbox_control_panel_branded_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Control Panel URL'),
    '#default_value' => variable_get('orderbox_control_panel_branded_url'),
    '#description' => t('You can either use the Partially Branded URL or the Fully Branded URL.<br />To get your Domain Control Panel URL, point to <strong>Settings ->Branding Settings</strong> and then click <strong>Control Panel</strong>.'),
    '#required' => TRUE,
  );
  $form['orderbox_login_settings']['orderbox_allow_reseller_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow Reseller Login'),
    '#default_value' => variable_get('orderbox_allow_reseller_login', 0),
    '#description' => t('Check if you want to allow your sub reseller to login, if not check only customer can use this login form.'),
  );
  }
  
  return system_settings_form($form);
}
