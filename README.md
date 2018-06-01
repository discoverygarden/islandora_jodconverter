# JODConverter

## Introduction

Utilizes OpenOffice / JODCoverter as a service to convert documents between
various formats.

### Supported formats

#### PDF format
* Portable Document Format (.pdf)

#### Text Formats
* OpenDocument Text (.odt)
* OpenOffice.org 1.0 Text (.sxw)
* Rich Text Format (.rtf)
* Microsoft Word (.doc)
* WordPerfect (.wpd)
* Plain Text (.txt)
* HTML1 (.html)

#### Spreadsheet Formats
* OpenDocument Spreadsheet (.ods)
* OpenOffice.org 1.0 Spreadsheet (.sxc)
* Microsoft Excel (.xls)
* Comma-Separated Values (.csv)
* Tab-Separated Values (.tsv)

#### Presentation Formats
* OpenDocument Presentation (.odp)
* OpenOffice.org 1.0 Presentation (.sxi)
* Microsoft PowerPoint (.ppt)

## Requirements

This module requires the following modules/libraries:

* [Open Office](https://www.openoffice.org/)
* [JODConverter] (http://sourceforge.net/projects/jodconverter/)
* [libraries](https://drupal.org/project/libraries)

## Installation

### Open Office (Under Ubuntu 13.04)

Install Open Office and the required dependencies.
```sh
sudo add-apt-repository ppa:upubuntu-com/office
sudo apt-get update
sudo apt-get install openoffice
sudo apt-get install openoffice.org-writer
sudo apt-get install openoffice.org-draw
sudo apt-get install openoffice.org-calc
sudo apt-get install openoffice.org-impress
```

Start OpenOffice service:

Make sure you start OpenOffice as the same user that apache is running as.
```sh
soffice --headless --accept=socket,host=127.0.0.1,port=8100;urp;
```
or, If you are using an older version:
```sh
soffice -headless -accept="socket,host=127.0.0.1,port=8100;urp;"
-nofirststartwizard
```

### JODConverter

Download from [here](http://sourceforge.net/projects/jodconverter/files/JODConverter/2.2.2/jodconverter-2.2.2.zip/download)
Unzip it and place into Drupal/base/path/sites/all/libraries

## Configuration

Configure the OpenOffice port in
Configuration > Islandora Utility Modules > JODConverter
(admin/config/islandora/tools/jodconverter). The port number here should match
the port number used in starting OpenOffice.

## Troubleshooting/Issues

Having problems or solved one? Create an issue, check out the Islandora Google
groups.

* [Users](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Devs](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

or contact [discoverygarden](http://support.discoverygarden.ca).

## Maintainers/Sponsors

Current maintainers:

* [discoverygarden](http://www.discoverygarden.ca)

## Development

If you would like to contribute to this module, please check out the helpful
[Documentation](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers),
[Developers](http://islandora.ca/developers) section on Islandora.ca and create
an issue, pull request and or contact
[discoverygarden](http://support.discoverygarden.ca).

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
