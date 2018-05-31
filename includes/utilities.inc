<?php

/**
 * @file
 * Utility functions.
 */

/**
 * To get all allowed format for JODConverter.
 *
 * @return array
 *   All allowed formats.
 */
function islandora_jodconverter_default_formats() {
  $all_formats = [];
  $all_formats['odt'] = [
    'name' => 'OpenDocument Text',
    'from' => [],
    'to' => [],
  ];
  $all_formats['sxw'] = [
    'name' => 'OpenOffice.org 1.0 Text',
    'from' => [],
    'to' => [],
  ];
  $all_formats['rtf'] = [
    'name' => 'OpenDocument',
    'from' => [],
    'to' => [],
  ];
  $all_formats['doc'] = [
    'name' => 'Rich Text Format',
    'from' => [],
    'to' => [],
  ];
  $all_formats['docx'] = [
    'name' => 'Rich Text Format',
    'from' => [],
    'to' => [],
  ];
  $all_formats['wpd'] = [
    'name' => 'WordPerfect',
    'from' => [],
    'to' => [],
  ];
  $all_formats['txt'] = [
    'name' => 'Plain Text',
    'from' => [],
    'to' => [],
  ];
  $all_formats['html'] = [
    'name' => 'HTML',
    'from' => [],
    'to' => [],
  ];
  $all_formats['pdf'] = [
    'name' => 'Portable Document',
    'from' => [],
    'to' => [],
  ];
  $all_formats['wiki'] = [
    'name' => 'MediaWiki wikitext',
    'from' => [],
    'to' => [],
  ];
  $all_formats['ods'] = [
    'name' => 'OpenDocument Spreadsheet',
    'from' => [],
    'to' => [],
  ];
  $all_formats['sxc'] = [
    'name' => 'OpenOffice.org 1.0 Spreadsheet',
    'from' => [],
    'to' => [],
  ];
  $all_formats['xls'] = [
    'name' => 'Microsoft Excel',
    'from' => [],
    'to' => [],
  ];
  $all_formats['xlsx'] = [
    'name' => 'Microsoft Excel',
    'from' => [],
    'to' => [],
  ];
  $all_formats['csv'] = [
    'name' => 'Comma-Separated Values',
    'from' => [],
    'to' => [],
  ];
  $all_formats['tsv'] = [
    'name' => 'Tab-Separated Values',
    'from' => [],
    'to' => [],
  ];
  $all_formats['odp'] = [
    'name' => 'OpenDocument Presentation',
    'from' => [],
    'to' => [],
  ];
  $all_formats['sxi'] = [
    'name' => 'OpenOffice.org 1.0 Presentation',
    'from' => [],
    'to' => [],
  ];
  $all_formats['ppt'] = [
    'name' => 'Microsoft PowerPoint',
    'from' => [],
    'to' => [],
  ];
  $all_formats['pptx'] = [
    'name' => 'Microsoft PowerPoint',
    'from' => [],
    'to' => [],
  ];
  $all_formats['swf'] = [
    'name' => 'Macromedia Flash',
    'from' => [],
    'to' => [],
  ];
  $all_formats['odg'] = [
    'name' => 'Microsoft PowerPoint',
    'from' => [],
    'to' => [],
  ];
  $all_formats['svg'] = [
    'name' => 'Macromedia Flash',
    'from' => [],
    'to' => [],
  ];

  $families = islandora_jodconverter_get_families();
  foreach ($families as $family) {
    foreach ($family['from'] as $from) {
      if (isset($all_formats[$from])) {
        $all_formats[$from]['to'] = array_merge($all_formats[$from]['to'], $family['to']);
      }
    }
  }

  foreach ($families as $family) {
    foreach ($family['to'] as $to) {
      if (isset($all_formats[$to])) {
        $all_formats[$to]['from'] = array_merge($all_formats[$to]['from'], $family['from']);
      }
    }
  }
  return $all_formats;
}

/**
 * To get a format information.
 *
 * @param string $ext
 *   The extension of a format type.
 *
 * @return array|bool
 *   The format type information.
 */
function islandora_jodconverter_get_format($ext) {
  $all_formats = islandora_jodconverter_default_formats();
  if (!isset($all_formats[$ext])) {
    \Drupal::logger('JODConverter')->error('Undefined type %format', ['%format' => $ext]);
    return FALSE;
  }
  return $all_formats[$ext];
}

/**
 * Get the Family information.
 *
 * @param string $family
 *   The family name.
 *
 * @return array
 *   The family information.
 */
function islandora_jodconverter_get_families($family = NULL) {
  $families = [
    'Text' => [
      'from' => [
        'odt',
        'sxw',
        'rtf',
        'doc',
        'docx',
        'wpd',
        'txt',
        'html',
      ],
      'to' => [
        'pdf',
        'odt',
        'sxw',
        'rtf',
        'doc',
        'docx',
        'txt',
        'html',
        'wiki',
      ],
    ],
    'Spreadsheet' => [
      'from' => [
        'ods',
        'sxc',
        'xls',
        'xlsx',
        'csv',
        'tsv',
      ],
      'to' => [
        'pdf',
        'ods',
        'sxc',
        'xls',
        'xlsx',
        'csv',
        'tsv',
        'html',
      ],
    ],
    'Presentation' => [
      'from' => [
        'odp',
        'sxi',
        'ppt',
        'pptx',
      ],
      'to' => [
        'pdf',
        'swf',
        'odp',
        'sxi',
        'ppt',
        'pptx',
        'html',
      ],
    ],
    'Drawing' => [
      'from' => [
        'odg',
      ],
      'to' => [
        'svg',
        'swf',
      ],
    ],
  ];

  $return_array = [];
  if ($family && !is_array($family)) {
    $family = [$family];
  }

  if ($family) {
    foreach ($family as $value) {
      if (isset($value)) {
        $return_array[$value] = $families[$value];
      }
    }
    return $return_array;
  }
  else {
    return $families;
  }
}

/**
 * Execute the convert command.
 *
 * @param string $command
 *   The commend after java -jar *.jar.
 *
 * @return array
 *   The out put of commend line. Return NULL if secusses executed.
 */
function islandora_jodconverter_exec_convert($command) {
  $conv_path = \Drupal::service("file_system")->realpath(libraries_get_path('jodconverter-2.2.2') . '/lib/jodconverter-cli-2.2.2.jar');
  $output = [];
  $exe_jar = "java -jar";
  $port = \Drupal::config('islandora_jodconverter.settings')->get('islandora_jodconverter_openoffice_port');
  if ($port != 8100) {
    $exe_jar .= "-p $port";
  }
  exec("$exe_jar $conv_path $command  2>&1", $output, $return_var);
  return $output;
}

/**
 * To get the extension of a file.
 *
 * @param string $filename
 *   The file name.
 *
 * @return bool|string
 *   Return the extension or false if not exist.
 */
function islandora_jodconverter_get_ext($filename) {
  $pos = strrpos($filename, ".");
  if ($pos === FALSE) {
    return FALSE;
  }
  else {
    return substr($filename, $pos + 1);
  }
}
