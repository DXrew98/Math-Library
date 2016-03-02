#include <iostream>
#include "Window.h"
#include "Input.h"

int main() {
	
	//hidden by private class membership
	//Window myWindow;
	//use instance funtion created in public
	auto &window = Window::instance();
	auto &input = Input::instance();


	
	system("pause");
	return 0;
}