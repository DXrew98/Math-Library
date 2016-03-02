#pragma once

class Input {
	bool isInit;
	Input();

	float keyRelease	[400];
	float keyPress		[400];

	float mouseRelease	[400];
	float mousePress	[400];

	float mouseX, mouseY;
public:
	static Input &instance() { static Input instance; return instance; }

	bool init();
	bool step();
	void term();

	bool getKey			(unsigned key); //true if key is down
	bool getKeyPress	(unsigned key); //true on frame key is pressed
	bool getKeyRelease	(unsigned key); //true on frame key is released

	bool getMosueButton			(unsigned); //true if key is down
	bool getMouseButtonPress	(unsigned); //true on frame key is pressed
	bool getMouseButtonRelease	(unsigned); //true on frame key is released

	float getMouseX();
	float getMosueY();
};