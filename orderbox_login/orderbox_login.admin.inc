<?php

/**
 * @file
 * Settings for the Orderbox Login module.
 *
 * @author: Adolfo G. Nasol http://drupal.org/user/547004
 *
 */

function orderbox_login_settings() {
  $form = array();
 
  $form['orderbox_login_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic configuration'),
    '#collapsed' => TRUE,
  );
  $form['orderbox_login_settings']['orderbox_login_action_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Foundation API Servlet URL'),
    '#default_value' => variable_get('orderbox_login_action_url'),
    '#description' => t('Servlet URL, use in form actions, change this if in case your not using the same URL.'),
    '#required' => TRUE,
  );
  $form['orderbox_login_settings']['orderbox_control_panel_branded_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Control Panel URL'),
    '#default_value' => variable_get('orderbox_control_panel_branded_url'),
    '#description' => t('You can either use the Partially Branded URL or the Fully Branded URL.<br />To get your Domain Control Panel URL, point to <strong>Settings ->Branding Settings</strong> and then click <strong>Control Panel</strong>.'),
    '#required' => TRUE,
  );
  $form['orderbox_login_settings']['orderbox_reseller_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Reseller ID'),
    '#default_value' => variable_get('orderbox_reseller_id'),
    '#description' => t('To get your Reseller Id, login from within your Reseller Control Panel.<br />Go to <strong>Settings -> Personal Information</strong> and then click <strong>Primary Profile</strong>. The first field is your Reseller Id.'),
    '#required' => TRUE,
  );
  $form['orderbox_login_settings']['orderbox_allow_reseller_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow Reseller Login'),
    '#default_value' => variable_get('orderbox_allow_reseller_login', 0),
    '#description' => t('Check if you want to allow your sub reseller to login, if not check only customer can use this login form.'),
  );
  
  return system_settings_form($form);
}

