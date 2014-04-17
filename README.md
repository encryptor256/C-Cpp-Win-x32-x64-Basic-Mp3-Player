C-Cpp-Win-x32-x64-Basic-Mp3-Player
==================================

C / C++ Win x32, x64 Basic Mp3 Player

https://www.youtube.com/watch?v=F9ZYor7WnvA

/*
; ------------------------------------- ----------------------- ;
; This is: C / C++ Win x32, x64 Basic Mp3 Player                ;
; Author: J.K. Encryptor256                                     ;
; Date: March 29, 2014                                          ;
;                                                               ;
; ------------------------------------- ----------------------- ;
; Description:                                                  ;
;  Create program soundplayer.exe, which plays mp3 file.        ;
;  Plays local file named: cashregister.mp3                     ;
;																;
;  Im building Win64 version, so x64 dll files are needed.		;
;                                                               ;
; ------------------------------------- ----------------------- ;
; Using:                                                        ;
;                                                               ;
;  1. MinGW: GCC, x64.                                          ;
;     Mingw-w64 delivers runtime, headers and libs for          ;
;     developing both 64 bit (x64) and 32 bit (x86)             ;
;     windows applications using GCC and other                  ;
;     free software compilers.                                  ;
;     (Web: http://mingw-w64.sourceforge.net/)                  ;
;																;	
;                                                               ;
;  2. SDL2, x64.                                                ;
;     Simple DirectMedia Layer is a cross-platform              ;
;     development library designed to provide low level         ;
;     access to audio, keyboard, mouse, joystick, and           ;
;     graphics hardware via OpenGL and Direct3D.                ;
;     (Web: http://www.libsdl.org/)                             ;
;																;
;     "http://www.libsdl.org/release/SDL2-2.0.3-win32-x64.zip"	;
;     ".............../release/SDL2-devel-2.0.3-mingw.tar.gz"   ;
;																;
;                                                               ;
;  3. mpg123, x64.                                              ;
;     Fast console MPEG Audio Player and decoder library.       ;
;     (Web: http://www.mpg123.de/)                              ;
;																;
;     "www.mpg123.de/download/win64/mpg123-1.19.0-x86-64.zip"	;
;																;
;                                                               ;
; ------------------------------------- ----------------------- ;
; Compile and Build:                                            ;
;                                                               ;
;     Current directory content:                                ;
;           1. libmpg123-0.dll                                  ;
;           2. SDL2.dll                                         ;
;           3. soundplayer.c                                    ;
;           4. cashregister.mp3                                 ;
;			5. Folder of sdl header files "./SDL2-2.0.3/*"		;
;			6. mpg123.h											;
;                                                               ;
; * Mp3 obtained from:                                          ;
;     "http://eng.universal-soundbank.com/money.htm"            ;
;                                                               ;
;  1. Build, GCC, one command line[2.1 - 2.4]:                  ;
;     2.1. gcc.exe                                              ;
;     2.2. -L"."                                                ;
;     2.3. -lsdl2 -llibmpg123-0                                 ;
;     2.4. -o soundplayer.exe soundplayer.c                     ;
;                                                               ;
;                                                               ;
*/
