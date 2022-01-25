#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MainMenu() : option(0)
{
}


MainMenu::~MainMenu()
{
}


void MainMenu::init() {
	logo.setText("RetroTODO App\n");
	logo.setColor(10);

	newFile.setText("1.New File ");
	newFile.setColor(160);

	loadFile.setText("2.Load File");

	exit.setText("3.Exit     ");

	box.setWidth(11);
}


void MainMenu::draw(HANDLE* _handle) {
	logo.draw(_handle);
	box.drawBeginBox(&newFile, _handle);
	box.drawMiddleBox(&loadFile, _handle);
	box.drawEndBox(&exit, _handle);
}


void MainMenu::update(Key* _key, State* _state, InputMenu* _inputMenu) {
	_key->turnOn();

	if(_key->isPressed(static_cast<char>(KEY_DOWN))) option++;
	else if (_key->isPressed(static_cast<char>(KEY_UP))) option--;


	if (option == 0) {
		newFile.setColor(160);
		loadFile.setColor(DEFAULT_COLOR);
		exit.setColor(DEFAULT_COLOR);
		_inputMenu->setMenuType(InputMenu::MenuType::NEW_FILE);
	}
	else if (option == 1) {
		newFile.setColor(DEFAULT_COLOR);
		loadFile.setColor(160);
		exit.setColor(DEFAULT_COLOR);
		_inputMenu->setMenuType(InputMenu::MenuType::LOAD_FILE);
	}
	else if (option == 2) {
		newFile.setColor(DEFAULT_COLOR);
		loadFile.setColor(DEFAULT_COLOR);
		exit.setColor(160);
	}

	if (option > 2) option = 2;
	else if (option < 0) option = 0;

	if ((option == 0 || option == 1) && _key->isPressed(static_cast<char>(RETURN_KEY))) {
		_key->turnOff();
		_state->setState(State::STATE::INPUT_MENU);
	}
	else if (option == 2 && _key->isPressed(static_cast<char>(RETURN_KEY))) {
		_key->turnOff();
		_state->setState(State::STATE::EXIT);
	}
}
