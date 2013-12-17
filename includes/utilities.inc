<?php

/**
 * @file
 * Utility functions.
 */
function islandora_jodconverter_get_formats($family = NULL, $from = NULL, $to = NULL) {
  $all_formats = array();
  $formats = array();
  $all_formats['odt'] = array(
    'family' => 'Text',
    'name' => 'OpenDocument',
  );
  return $formats;
}

function islandora_jodconverter_get_familis($family = NULL){
  $families = array(
    'Text' => array(
      'from' => array(
        'odt',
        'sxw',
        'rtf',
        'doc',
        'wpd',
        'txt',
        'html',
      ),
      'to'=> array(
        'pdf',
        'odt',
        'sxw',
        'rtf',
        'doc',
        'txt',
        'html',
        'wiki'
      ),
    ),
    'Spreadsheet' => array(
      'from' => array(
        'ods',
        'sxc',
        'xls',
        'csv',
        'tsv',
      ),
      'to' => array(
        'pdf',
        'ods',
        'sxc',
        'xls',
        'csv',
        'tsv',
        'html',
      ),
    ),
    'Presentation' => array(
      'from' => array(
        'odp',
        'sxi',
        'ppt',
      ),
      'to'=> array(
        'pdf',
        'swf',
        'odp',
        'sxi',
        'ppt',
        'html'
      ),
    ),
    'Drawing' => array(
      'from' => array(
        'odg',
      ),
      'to' => array(
        'svg',
        'swf',
      ),
    ),
  );
  
  $return_array = array();
  if($family && !is_array($family)){
    $family = array($family);
  }
  
  if ($family) {
    foreach ($family as $value) {
      if (isset($value)) {
        $return_array[$value] = $families[$value];
      }
    }
    return $return_array;
  }
  else{
    return $families;
  }
}

function islandora_jodconverter_exec_convert($command) {
  $conv_path = drupal_realpath(libraries_get_path('jodconverter-2.2.2') . '/lib/jodconverter-cli-2.2.2.jar');
  $output = array();
  exec("java -jar $conv_path $command  2>&1", $output, $return_var);
  return $output;
}