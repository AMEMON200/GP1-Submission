#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

// SDL2 Headers
#include <SDL.h>
#include <Windows.h>
#include "cSDL2WNDManager.h"
#include "cGame.h"
#include <dinput.h>
#include <mmsystem.h>
#pragma(lib,"winmm.lib")
#include "SDL_timer.h"
#include "stdlib.h"
#include "SDL_joystick.h"

using namespace std;

//This is the SDL window
static cSDL2WNDManager* pgmWNDMgr = cSDL2WNDManager::getInstance();

//This is the our Game
static cGame* theGame = cGame::getInstance();

int main(int argc, char *argv[])
{
	{if (!pgmWNDMgr->initWND(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT))
		return -1;

	theGame->initialise(pgmWNDMgr->getSDLWindow(), pgmWNDMgr->getSDLRenderer());

	theGame->run(pgmWNDMgr->getSDLWindow(), pgmWNDMgr->getSDLRenderer());

	theGame->cleanUp(pgmWNDMgr->getSDLWindow());

	return 0; }


	//When the game is over this will be shown in the end
	std::cout << "Game Over" << std::endl;
	return 0;

	//This piece of code will exit the code if the user presses 1, if any other button is pressed, it will replay the program
	int exit;
	while (1 == 1)
	{
		cout << "Replay" << endl;
		cout << "Would you want to exit" << endl;
		cin >> exit;
		if (exit == 1)
		{
			break;
		}
	}
	return 0;


	/*
	struct _SDL_GameController;
	typedef struct _SDL_GameController SDL_GameController;


	typedef enum
	{
		SDL_CONTROLLER_BINDTYPE_NONE = 0,
		SDL_CONTROLLER_BINDTYPE_BUTTON,
		SDL_CONTROLLER_BINDTYPE_AXIS,
		SDL_CONTROLLER_BINDTYPE_HAT
	} SDL_GameControllerBindType;


	typedef struct SDL_GameControllerButtonBind
	{
		SDL_GameControllerBindType bindType;
		union
		{
			int buttons;
			int axis;
			struct {
				int hat;
				int hat_mask;
			} hat;
		} value;

	} SDL_GameControllerButtonBind;


	
	


	//Instead of using Xbox 360 controller, i tried using a joystick gamepad but there is an error coming for JOYINFOEX
	
	int i;
	JOYINFOEX pji;
	DWORD axis[6] = { 0 };
	UINT buttons[13] = { 0 };
	ZeroMemory(&pji, sizeof(pji));
	pji.dwSize = sizeof(pji);
	pji.dwFlags = JOY_RETURNBUTTONS | JOY_RETURNX | JOY_RETURNY
	| JOY_RETURNZ | JOY_RETURNR | JOY_RETURNU | JOY_RETURNV;

	if (JOYERR_NOERROR == joyGetPosEx(0, &pji))
	{
	// Axis
	for (i = 0; i < 6; i++)
	{
	DWORD axis = ((DWORD*) &(pji.dwXpos))[i];
	axis[i] = axis;
	}
	// Buttons
	for (i = 0; i < 13; i++)
	{
	int button = (pji.dwButtons & (1 << i)) != 0;
	buttons[i] = button;
	}
	// Output
	printf("Axis:", pji.dwButtons);
	for (i = 0; i < 6; i++)
	printf("  %d: %5d", i, axis[i] + 32767);
	printf(" Buttons:  ", pji.dwButtonNumber);
	for (i = 0; i < 13; i++)
	printf("%d:%s  ", i, buttons[i] ? "on " : "off");
	printf("\n");
	}
	else
	{
	printf("Error!\n");
	}
	return 0;
	*/


	char repeat = 'y';
	if (repeat == 'y')
	{
		//code for space invaders to replay
	}
	cout << "Replay" << endl;
	cin >> repeat;
	
		
		if (repeat == 'n')
		{
			cout << "Close the Program" << endl;
			
		}
	

}