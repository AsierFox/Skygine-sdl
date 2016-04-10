#include "WinMain.h"

#if defined(DEBUG) | defined(_DEBUG)

int _tmain(int argc, char* argv[]) {
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	Engine* engine = new Engine();
	int errors = engine->loop();
	SAFE_DELETE(engine);
	
	return WinMain((HINSTANCE) GetModuleHandle(NULL), 0, 0, SW_SHOW);
}

#else

int main(int argc, char* argv[]) {
	Engine* engine = new Engine();
	int errors = engine->loop();
	SAFE_DELETE(engine);

	getchar();

	return 0;
}

#endif

/*
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreviousInstance, LPSTR lpCmdLine, int cmdShow) {
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPreviousInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Avoid memory leaks on debug builds
#if defined(DEBUG) | defined(_DEBUG)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	// Enable runtime memory leak for debug builds
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(0);
#endif

	Engine* engine = new Engine();
	int errors = engine->loop();
	SAFE_DELETE(engine);

	return errors;
}
*/
