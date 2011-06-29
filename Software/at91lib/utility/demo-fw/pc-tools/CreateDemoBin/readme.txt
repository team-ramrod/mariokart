1> directory info:

|-bin          [dir]compile executive binary
|-include      [dir]header files
|-lib          [dir]libraries
|-PPT          [dir]directory containing example PPT, demo bin file and vs script
|-src          [dir]source files
|-Makefile     [file]project file to make. use gnu/g++ as compiler.
|-Module1.bas  [file]vb script source of macro 'ExportPPTInfo'
|-readme.txt   [file]this file



2> usage instructions:

Suppose that demo is for at91sam3u-ek, and power point file is Sam3Demo.ppt. 

Sam3Demo.bin and SamDemoV.bin under ./PPT are created bin files with CreateDemoBin.exe, you can use it directly or use CreateDemoBin.exe to recreate it.

Follow these instructions to create a bin from starting(use sam3demo.ppt as example):

[step 1]: 
   Open Sam3DEMO.ppt, when a window pops up, select 'enable macros'. If no this window or you made  wrong selection, please check Powerpoint menu 'tools->macro->security...', set it to medium, then close the program and reopen it.(Powerpoint 2003)

[step 2]:
   Select 'tools->macro->macros...', then run the macro named as 'ExportPPTInfo'. After running, there should be 'Sam3DEMO.txt' and dir 'Sam3DEMO' created. Inside dir 'Sam3DEMO', there should be bmp files named as 'slide1.bmp... slide10.bmp...' If macro 'ExportPPTInfo' is not available, please import content of 'Module1.bas' into VB script edit window, save it to file, then rerun it.

[step 3]:
   Run CreateDemoBin.bat (or CreateDemoBin sam3demo)under dir same as Sam3DEMO.ppt. If success, Sam3Demo.bin should be created. 
   
   [Please NOTE]: 
a:> Defaultly this bat will generate horizontal view demo binary for sdcard and nandflash(contained slide pics are 320*240 16bit bmp with 270 degree clockwise rotation). For vertical view demo binary, please use CreateDemoBinV.bat to generate sam3demo.bin, then RENAME it to SamDemoV.bin. Before Converting vertical view demo binary, previous generated horizontal view demo binary Sam3Demo.bin must be BACKUPed. Or converting vertical one and renaming it first, then converting horizontal one. Key word sam3demo could be replaced with any actual name of PPT.

b:>This batch files are only for sam3u demo(assuming that PPT name is sam3demo.ppt). For other boards and PPT file, please replace conversion parameters and PPT name. In following section 3, more details about conversion tools with examples are given.



[step 4]:
   Copy the bin file into root dir of a SDCARD or using sam-ba to download it into flash1, the program will search the SDcard -> Nandflash -> Internal flash for the demo binary file.(you can use the default binary file Sam3DEMO.bin for SDcard and Nandflash, and DEMOBINFLASH1.bin for the internal flash)

[step 5]:
   Compile the gshell projects, and load it into sam3u4 flash0 to run.(if DEMOBININFLASH1 is defined, then program will read demo bin data from FLASH1, otherwise, it will read demo bin data with search order of sdcard->nandflash->flash1. Auto run in the init entry will try to read "sam3demo.bin" by default. You can use other demo bin file name under GShell console)




3> CreateDemoBin.exe options and examples:


Usage: CreateDemoBin.exe [options] <PPTpathAndnameWithoutExtName>
  For example, sam3demo.ppt, after running VBS macro in PowerPoint,
  copy this file under the same directory, then Run:

                            CreateDemoBin.exe sam3demo
  Options:
  --help, show this information
  -profile <EK-board-name>, build-in option sets, default board name is at91sam3u-ek
  -profile help, display all build-in profile details
  -width <resizedwith>, default is 320 pixel
  -height <resizedheight>, default is 240 pixel
  -bitdepth <bitdepth>, default is 16 bit
  -rotate <clockwise_angel>, times of 90 degree within 360, default is 270 degre
e
  -noreversebitmaporder, keep bitmap data original order, default reverse the order for at91sam3u-ek



[Example 1:Generating demo binary of horizontal view]:

 For demo bin of default horizontal view(based on long side of LCD SCREEN) in sdcard or nandflash of at91sam3u-ek(sam3demo.ppt, and generated txt file and slide bitmap with macro):

createdemobin sam3demo
or
createdemobin -profile at91sam3u-ek
or
createdemobin -width 320 -height 240 -bitdepth 16 -rotate 270 sam3demo

The built-in default options are for Sam3u demo horizontal view, so you can convert it as first one to use default options.

[Example 2:Generating demo binary of vertical view]:

 For demo bin of vertical view(based on long side of LCD SCREEN) in sdcard or nandflash of at91sam3u-ek(sam3demo.ppt, and generated txt file and slide bitmap with macro):

CreateDemoBin -width 240 -height 320 -bitdepth 16 -rotate 0 sam3demo

*NOTE: after generation, must RENAME sam3demo.bin to samdemov.bin for vertical view.


[Example 3:Merge two PPTs to generate a binary]:

For example, PPT file Pa.ppt has 18 pages, PPT file Pb.ppt has 30 pages. It is required that all
Pb.ppt slide pages should be inserted after the16th page into Pa.ppt:
Steps:
? Insert 30 empty pages after the 16th page of Pa.ppt
? Enable macro security level to medium, and then import vb script macro Module1.bas
? Run macro ExportPPTInfo, when proceeding to popup window for prompting conversion
parameters, press cancel to ignore conversion step.
? Insert 16 pages before the 1st page of Pb.ppt
? Do steps 2 and 3 for Pb.ppt.
? Delete slide information file Pa.txt section from slide 17 to slide 46, then copy slide
information file Pb.txt section from slide 17 to slide 46 at the same position in Pa.txt
? Copy picture files from slide17.bmp to slide46.bmp in Pb directory to Pa directory to
overwrite them.
? Use command sequences above to generate horizontal or vertical binary file.





