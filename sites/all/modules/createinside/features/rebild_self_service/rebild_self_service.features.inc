<?php
/**
 * @file
 * rebild_self_service.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rebild_self_service_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rebild_self_service_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rebild_self_service_node_info() {
  $items = array(
    'self_service' => array(
      'name' => t('Selvbetjeningsløsning'),
      'base' => 'node_content',
      'description' => t('Brug denne indholdstype til at oprette en selvbetjeningsløsning.'),
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
  );
  return $items;
}
