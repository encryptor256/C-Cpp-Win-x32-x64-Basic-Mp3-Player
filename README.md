C-Cpp-Win-x32-x64-Basic-Mp3-Player
==================================

C / C++ Win x32, x64 Basic Mp3 Player

https://www.youtube.com/watch?v=F9ZYor7WnvA

<table>
<tr><td><b>Description:</b></td><td></td></tr>
<tr><td></td><td>Create program soundplayer.exe, which plays mp3 file.</td></tr>
<tr><td></td><td>Plays local file named: cashregister.mp3</td></tr>
<tr><td></td><td>Im building Win64 version, so x64 dll files are needed.</td></tr>
</table>

<table>
<tr><td><b>Using:</b></td><td></td></tr>
<tr><td>1.</td><td>MinGW: GCC, x64.</td></tr>
<tr><td></td><td>Mingw-w64 delivers runtime, headers and libs fordeveloping both 64 bit (x64) and 32 bit (x86)windows applications using GCC and otherfree software compilers.
</td></tr>
<tr><td></td><td>http://mingw-w64.sourceforge.net/</td></tr>
<tr><td>2.</td><td>SDL2, x64.</td></tr>
<tr><td></td><td>Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.
</td></tr>
<tr><td></td><td>http://www.libsdl.org/release/SDL2-2.0.3-win32-x64.zip</td></tr>
<tr><td></td><td>http://www.libsdl.org/release/SDL2-devel-2.0.3-mingw.tar.gz</td></tr>
<tr><td></td><td>http://www.libsdl.org/</td></tr>
<tr><td>3.</td><td>mpg123, x64.</td></tr>
<tr><td></td><td>Fast console MPEG Audio Player and decoder library.</td></tr>
<tr><td></td><td>www.mpg123.de/download/win64/mpg123-1.19.0-x86-64.zip</td></tr>
<tr><td></td><td>http://www.mpg123.de/</td></tr>
</table>

<table>
<tr><td><b>Compile and Build:</b></td><td></td><td></td><td></td></tr>
<tr><td></td><td><b>Current directory content:</b></td><td></td></tr>
<tr><td></td><td>1.</td><td>libmpg123-0.dll</td></tr>
<tr><td></td><td>2.</td><td>SDL2.dll</td></tr>
<tr><td></td><td>3.</td><td>soundplayer.c</td></tr>
<tr><td></td><td>4.</td><td>cashregister.mp3</td></tr>
<tr><td></td><td>5.</td><td>Folder of sdl header files "./SDL2-2.0.3/*"</td></tr>
<tr><td></td><td>6.</td><td>mpg123.h</td></tr>
<tr><td></td><td></td><td></td></tr>
<tr><td></td><td><b>Mp3 obtained from:</b></td><td>http://eng.universal-soundbank.com/money.htm</td></tr>
<tr><td></td><td></td><td></td></tr>
<tr><td></td><td><b>Build, Command line:</b></td><td>gcc.exe -L"." -lsdl2 -llibmpg123-0 -o soundplayer.exe soundplayer.c</td></tr>
</table>
