<?php
/**
 * @file
 * rebild_search.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function rebild_search_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'core_search_0';
  $searcher->label = 'Primary search';
  $searcher->description = 'This is the primary sitewide search';
  $searcher->search_path = 'soeg';
  $searcher->page_title = 'Søgeresultater';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(),
    'apachesolr_search_custom_enable' => 0,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 0,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'none',
  );
  $export['core_search_0'] = $searcher;

  return $export;
}
