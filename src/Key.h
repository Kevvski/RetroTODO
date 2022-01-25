#pragma once
#ifndef KEY_H
#define KEY_H
#include <iostream>
#include <conio.h>

class Key
{
public:
	Key();
	~Key();

	void listenKey();
	bool isPressed(char value);
	void turnOn();
	void turnOff();
	bool isWorking() const;

private:
	bool working;
	char key;
};

#endif // !KEY_H

