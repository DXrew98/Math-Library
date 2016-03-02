#include "Input.h"
#include "Window.h"
#include <cstring>

Input::Input() : isInit(false) 
{
	
}

bool Input::init()
{
	memset(keyRelease,	 0, 400);
	memset(keyPress,	 0, 400);
	memset(mouseRelease, 0, 10);
	memset(mousePress,	 0, 10);
	mouseX = mouseY =	 0;

	return isInit = Window::instance().init;
}

bool Input::step()
{
	//for (unsigned i = 0; i < 400; ++i) {
	//	keyState[i] = keyPress[i] > keyRelease[i];
	//	if (/*sfw::getKey();*/) { keyPress[i] = /*sfw::getTime();*/ }
	//	else{ keyRelease[i] = /*sfw::getTime();*/ }

	//for (unsigned i = 0; i < 400; ++i) {
	//	if (/*mouseState[i] = sfw::getKey();*/) { mousePress[i] = /*sfw::getTime();*/ }
	//	else { mouseRelease[i] = /*sfw::getTime();*/ }

	//}
	//mouseX = //sfw::getMouseX();
	//mouseY = //sfw::getMouseY();
	return false;
}

bool Input::getKey(unsigned key)		{ return keyPress[key] > keyRelease[key]; }
bool Input::getKeyPress(unsigned key)	{ return getKey(key)  && !keyState[key]; }
bool Input::getKeyRelease(unsigned key) { return !getKey(key) && keyState[key]; }

bool Input::getMosueButton(unsigned key)		{ return keyPress[key] > keyRelease[key]; }
bool Input::getMouseButtonPress(unsigned key)	{ return getKey(key)  && !keyState[key]; }
bool Input::getMouseButtonRelease(unsigned key) { return !getKey(key) && keyState[key]; }