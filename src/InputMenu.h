#pragma once
#ifndef INPUTMENU_H
#define INPUTMENU_H
#include <iostream>
#include <string>
#include <Windows.h>
#include "Key.h"
#include "State.h"
#include "FileManager.h"

class InputMenu
{
public:
	InputMenu();
	~InputMenu();

	enum MenuType { NEW_FILE, LOAD_FILE, NONE};

	void setMenuType(const InputMenu::MenuType& _menuType);
	void setQuestion(const std::string& text);
	void draw();
	virtual void update(Key* _key, State* _state, std::vector<TextLine>* tab);

	const InputMenu::MenuType& getMenuType() const;
	std::string& getFileName();

private:
	MenuType menuType;
	FileManager fileManager;
	std::string question;
	std::string fileName;
};

#endif // !INPUTMENU_H

