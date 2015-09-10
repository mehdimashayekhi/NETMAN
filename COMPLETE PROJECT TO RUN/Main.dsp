# Microsoft Developer Studio Project File - Name="Main" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Main - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Main.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Main.mak" CFG="Main - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Main - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Main - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Main - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Main - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "c:\netman\test"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Main - Win32 Release"
# Name "Main - Win32 Debug"
# Begin Source File

SOURCE=.\Arc.c
# End Source File
# Begin Source File

SOURCE=.\Color.c
# End Source File
# Begin Source File

SOURCE=.\define.c
# End Source File
# Begin Source File

SOURCE=.\define00.c
# End Source File
# Begin Source File

SOURCE=.\define01.c
# End Source File
# Begin Source File

SOURCE=.\define02.c
# End Source File
# Begin Source File

SOURCE=.\define03.c
# End Source File
# Begin Source File

SOURCE=.\define04.c
# End Source File
# Begin Source File

SOURCE=.\define05.c
# End Source File
# Begin Source File

SOURCE=.\define06.c
# End Source File
# Begin Source File

SOURCE=.\define07.c
# End Source File
# Begin Source File

SOURCE=.\define08.c
# End Source File
# Begin Source File

SOURCE=.\define09.c
# End Source File
# Begin Source File

SOURCE=.\define10.c
# End Source File
# Begin Source File

SOURCE=.\define11.c
# End Source File
# Begin Source File

SOURCE=.\define12.c
# End Source File
# Begin Source File

SOURCE=.\define13.c
# End Source File
# Begin Source File

SOURCE=.\define14.c
# End Source File
# Begin Source File

SOURCE=.\define15.c
# End Source File
# Begin Source File

SOURCE=.\define16.c
# End Source File
# Begin Source File

SOURCE=.\define17.c
# End Source File
# Begin Source File

SOURCE=.\define18.c
# End Source File
# Begin Source File

SOURCE=.\define19.c
# End Source File
# Begin Source File

SOURCE=.\define20.c
# End Source File
# Begin Source File

SOURCE=.\define21.c
# End Source File
# Begin Source File

SOURCE=.\define22.c
# End Source File
# Begin Source File

SOURCE=.\define23.c
# End Source File
# Begin Source File

SOURCE=.\define24.c
# End Source File
# Begin Source File

SOURCE=.\define25.c
# End Source File
# Begin Source File

SOURCE=.\define26.c
# End Source File
# Begin Source File

SOURCE=.\define27.c
# End Source File
# Begin Source File

SOURCE=.\define28.c
# End Source File
# Begin Source File

SOURCE=.\define29.c
# End Source File
# Begin Source File

SOURCE=.\define30.c
# End Source File
# Begin Source File

SOURCE=.\Dmac.c
# End Source File
# Begin Source File

SOURCE=.\Dplayer.c
# End Source File
# Begin Source File

SOURCE=.\Dplayer.h
# End Source File
# Begin Source File

SOURCE=.\Enabled.c
# End Source File
# Begin Source File

SOURCE=.\Expo.c
# End Source File
# Begin Source File

SOURCE=.\Fire.c
# End Source File
# Begin Source File

SOURCE=.\Init.c
# End Source File
# Begin Source File

SOURCE=.\Main.c
# End Source File
# Begin Source File

SOURCE=.\marking.c
# End Source File
# Begin Source File

SOURCE=.\Memlist.c
# End Source File
# Begin Source File

SOURCE=.\Memory.c
# End Source File
# Begin Source File

SOURCE=.\Mycode.h
# End Source File
# Begin Source File

SOURCE=.\Petri.h
# End Source File
# Begin Source File

SOURCE=.\Petriusr.c
# End Source File
# Begin Source File

SOURCE=.\Petriusr.h
# End Source File
# Begin Source File

SOURCE=.\Place.c
# End Source File
# Begin Source File

SOURCE=.\Player.c
# End Source File
# Begin Source File

SOURCE=.\Print.c
# End Source File
# Begin Source File

SOURCE=.\Stats.c
# End Source File
# Begin Source File

SOURCE=.\Superusr.h
# End Source File
# Begin Source File

SOURCE=.\Sysfunc.h
# End Source File
# Begin Source File

SOURCE=.\Token.c
# End Source File
# Begin Source File

SOURCE=.\Trans.c
# End Source File
# Begin Source File

SOURCE=.\userfunc.c
# End Source File
# Begin Source File

SOURCE=.\userfunc.h
# End Source File
# End Target
# End Project
