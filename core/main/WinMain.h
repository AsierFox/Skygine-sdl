#ifndef _WIN_MAIN_H_
#define _WIN_MAIN_H_

#ifndef _WINDOW_
	#include <Windows.h>
#endif // _WINDOW_

#include <string>

#include "../../defines/deletemacros.h"
#include "../engine/Engine.h"

/**
 * Method for Debug mode
 */
int _tmain(int argc, char* argv[]);

//int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreviousInstance, LPSTR lpCmdLine, int cmdShow);

/**
* Method for Release mode
*/
int main(int argc, char* argv[]);

#endif // !_WIN_MAIN_H_
