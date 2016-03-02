#pragma once

#include <cassert>

#define INIT_ASSERT assert(isInit && "Window is not initialized!")

/*
	Only one window
	Make details about the window accessible

	Singleton Pattern:
		Private constructors
		Public Static Accessor
*/

template<typename T>
class IWindow {
	Window() : isInit(false) {}

	bool isInit;
	unsigned width, height;

public:
	static T &instance{ static T instance; return instance; }

	virtual bool init(unsigned Width = 800, unsigned Hight = 600, const char *Title = "Engine") = 0;
	virtual bool step() = 0;
	virtual void term() = 0;

	unsigned getWidth() { INIT_ASSERT; return width; }
	unsigned getHeight() { INIT_ASSERT; return height; }
	bool getIsInit() { return isInit; }
};


class Window : public IWindow<Window> {
private:
	friend class IWindow<Window>;
	Window() {}
	Window() : isInit(false) {}

	bool isInit;
	unsigned width, height;

public:
	
	static Window &instance() {
		static Window instance; return instance;
	}

	bool init(unsigned Width, unsigned Hight, const char *Title) {
		isInit = /*sfw::initContext(Width, Height, Title);*/;
		return isInit;
	}
	bool step() { INIT_ASSERT; /*sfw::initContext();*/ }
	void term() { INIT_ASSERT; /*sfw::initContext();*/ }
		//Step
		//Initialize
		//Terminate
		//Window width and height
};