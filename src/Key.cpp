#include "stdafx.h"
#include "Key.h"


Key::Key() : working(false)
{
}


Key::~Key()
{
}


void Key::listenKey() {
	key = _getch();
}


bool Key::isPressed(char value) {
	return key == value;
}


void Key::turnOn() {
	working = true;
}


void Key::turnOff() {
	working = false;
}


bool Key::isWorking() const {
	return working;
}
