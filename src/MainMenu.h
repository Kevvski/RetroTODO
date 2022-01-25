#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include "TextLine.h"
#include "TextBox.h"
#include "Key.h"
#include "State.h"
#include "InputMenu.h"

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void init();
	void draw(HANDLE* _handle);
	void update(Key* _key, State* _state, InputMenu* _inputMenu);

private:
	TextLine logo;
	TextLine newFile;
	TextLine loadFile;
	TextLine exit;
	TextBox box;
	int option;
};

#endif MAINMENU_H

