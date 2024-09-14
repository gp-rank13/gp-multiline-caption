# Multiline Caption Extension for Gig Performer

## Overview

An extension for [Gig Performer](https://gigperformer.com) that allows widget captions/labels to be converted to multiline text. Refer to the _Usage_ section below for details.

> _Disclaimer: This is a user-created extension and is not supported by Deskew Technologies._

## Installation

Download the extension (library) files for either MacOS or Windows from the [Releases](https://github.com/gp-rank13/gp-multiline-caption/releases) page.  

Mac users will need to move the _libMultilineCaptions.dylib_ file into this folder and then restart Gig Performer:
```
/Users/Shared/Gig Performer/Extensions
```
Mac users will also need to authorize the extension via _System Settings > 
_Privacy & Security_. Scroll down until you locate an entry that references the extension. Allow it to be loaded and then restart Gig Performer.

Windows users will need to move the _MultilineCaptions.dll_ file into this folder and then restart Gig Performer:
```
C:\Users\Public\Documents\Gig Performer\Extensions
```

When opening Gig Performer, a prompt will appear asking to confirm whether to install the extension.

## Usage

1. Add a _Text Label_ widget and a custom caption. Use a semicolon ";" at the point where you want to add a line break. 

    <img width="636" alt="gp-multiline-caption-1" src="https://github.com/user-attachments/assets/3db0c6f4-f0b5-4c86-aa91-28803308cd4f">
<br />

2. Add a widget handle (_Advanced_ tab of the Widget Properties) called "MULTILINE". If you are converting multiple widget captions, then each handle must be unique. Add numbers to the end if required.

    <img width="634" alt="gp-multiline-caption-2" src="https://github.com/user-attachments/assets/554d7292-3cdc-4ee2-9242-d485c9b8bf25">
<br />

3. Use Gig Performer's _Extensions_ menu and select the menu item for _Convert Captions to Multiline_. The caption text will have the semicolon replaced with a proper line break.

    <img width="636" alt="gp-multiline-caption-3" src="https://github.com/user-attachments/assets/e4f8bb24-df0e-4dff-b388-65e31df9003a">


## Building the Extension

To customize/build the extension, refer to the [Gig Performer SDK](https://github.com/gigperformer/gp-sdk) GitHub page.