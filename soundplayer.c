#ifndef soundplayer_c
#define soundplayer_c
#include <stdio.h>
#include <stdlib.h>
#include "./mpg123.h"
#include "./SDL2-2.0.3/x86_64-w64-mingw32/include/SDL2/sdl.h"
//
//	Undef main, avoid SDL garbage
//
//
#undef main
//
//	Structure:	SdlMpg123, is used to pass data to SDL_AudioSpec.callback procedure
//	Function:	mainquit, C / C++ final quit procedure
//	Function:	sdl_audiobackstabprocedure, sdl audio callback procedure.
//
//
typedef struct tagSdlMpg123
{
	void * mpg123handle;
	char isplaying;
	char stopplaying;

}SdlMpg123, *SdlMpg123Pointer;
//
void mainquit(void);
//
void sdl_audiobackstabprocedure(void *userdata, Uint8* stream, int len);
//
//	Function: main, C / C++ entry procedure
//
//
int main(int argc, char* argv[])
{	
	//;
	//; atexit: Set C / C++ quit procedure.
	//; mpg123_init: initialise the mpg123 library. 
	//; SDL_Init: init audio subsystem.	
	//;

	atexit(mainquit);
	if(mpg123_init()!=0 || SDL_Init(SDL_INIT_AUDIO)!=0) return 0;

	//; ----------------------------- ;
    //;
    //; MPG123
    //; // Create new mpg123 handle and test for error, and save handle
    //; // RDX: Get music file argument
    //; // Open and prepare to decode the specified file by filesystem path
    //; // Get music file format and test for error
    //; // Check format error
    //; // Set new format
    //; // Scan file - mpg123 dll file displays some error if happens,
    //;      in case shitty mp3 was provided.
    //;

	const char 		* mp3namepointer = {"cashregister.mp3"};
	mpg123_handle	* handlepointer;
	int 			channels, encoding;
	long			rate;

	handlepointer = mpg123_new(0,0);

	if(handlepointer == NULL ||
	   mpg123_open(handlepointer,mp3namepointer) != 0 ||
	   mpg123_getformat(handlepointer,&rate,&channels,&encoding) != 0 ||
	   encoding != MPG123_ENC_SIGNED_16)
	{
		return 0;
	};

	mpg123_format_none(handlepointer);
	mpg123_format(handlepointer,rate,channels,encoding);
	mpg123_scan(handlepointer);

	//; ----------------------------- ;
    //;
    //; SDL2
    //; // Allocate sdlmpg123 structure
    //; // Fill sdlmpg123 structure
    //; // Allocate audiospecwant structure
    //; // Allocate audiospechave structure
    //; // Fill audiospecwant structure
    //;

	SdlMpg123 sdlmpg123; 

	sdlmpg123.mpg123handle = handlepointer;
	sdlmpg123.isplaying = 1;
	sdlmpg123.stopplaying = 0;
	
	SDL_AudioSpec audioswant;
	SDL_AudioSpec audioshave;

	audioswant.freq=rate;
	audioswant.format=AUDIO_S16;
	audioswant.channels=channels;
	audioswant.samples=4096;
	audioswant.callback=&sdl_audiobackstabprocedure;
	audioswant.userdata=&sdlmpg123;

	//; ----------------------------- ;
    //;
    //; SDL2 - audio
    //; // Open audio device and test for error
    //; // Check if specified format remains the same
    //; // Start audio play
    //; // Enter audio loop "audioloop"
    //; // Close audio
    //;
	//;

	if(SDL_OpenAudio(&audioswant,&audioshave)!=0 ||
	   audioswant.format!=audioshave.format)
	{
		return 0;
	};

	printf("\r\n!!! Starting to PLAY !!!\r\n");

	SDL_PauseAudio(0);

	while(sdlmpg123.isplaying!=0)
	{
		SDL_Delay(250);
	};

	mpg123_close(handlepointer);
	mpg123_delete(handlepointer);

	printf("\r\n\r\n!!! Playing DONE !!!\r\n");

	return 0;
};
//
//	Function: mainquit, C / C++ quit procedure
//
//
void mainquit(void)
{
	mpg123_exit();
	SDL_Quit();
};
//
//	Function: sdl_audiobackstabprocedure
//
//
void sdl_audiobackstabprocedure(void *userdata, Uint8 * stream, int len)
{
	//; ----------------------------- ;
	//; // Init stream
    //; // Check if still playing
	//; // Check if last read was the last one
    //; // Print info message
    //; // Read and decode audio data
    //; // Check if read is last one and update SDLMPG123.stopplaying
    //; // Check if bytes were read and if needed update SDLMPG123.isplaying
    //; //
    //; //
    //; //

	memset(stream,0,len);

	SdlMpg123Pointer sdlmpg123pointer = userdata;

	if(sdlmpg123pointer->isplaying==0) return;

	if(sdlmpg123pointer->stopplaying!=0)
	{
		sdlmpg123pointer->isplaying=0;
		return;
	};

	printf("\r\nMusic is playing...");

	size_t bytesread;

	if(mpg123_read(sdlmpg123pointer->mpg123handle,stream,len,&bytesread)!=0)
		sdlmpg123pointer->stopplaying=1;
	
	if(bytesread!=0) return;

	sdlmpg123pointer->isplaying=0;
};
//
#endif



