<?php

/**
 * @file
 *   Notifications module drush integration.
 */

/**
 * Implementation of hook_drush_command().
 *
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function notifications_drush_command() {
  $items = array();

  $items['notification-clean-sent'] = array(
    'description' => "Cleanup notification sent history.",
    'drupal dependencies' => array('notifications'),
    'aliases' => array('ncs', 'notifications'),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function notifications_drush_help($section) {
  switch ($section) {
    case 'drush:notification-clean-sent':
      return dt("Cleanup notification sent history.");
  }
}

/**
 * Clears notification sent history.
 */
function drush_notification_clean_sent() {
  module_load_include('inc', 'notifications', 'notifications.admin');
  _notifications_clean_sent_history();
  drush_log(dt('Notifications sent history cleared.'));
}
