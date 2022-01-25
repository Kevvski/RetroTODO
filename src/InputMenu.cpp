#include "stdafx.h"
#include "InputMenu.h"


InputMenu::InputMenu() : menuType(InputMenu::MenuType::NONE)
{
}


InputMenu::~InputMenu()
{
}


void InputMenu::setMenuType(const InputMenu::MenuType& _menuType) {
	menuType = _menuType;
}


void InputMenu::setQuestion(const std::string& text) {
	question = text;
}


void InputMenu::draw() {
	std::cout << question;
}


void InputMenu::update(Key* _key, State* _state, std::vector<TextLine>* tab) {
	_key->turnOff();

	if (!_key->isWorking()) {
		std::getline(std::cin, fileName);
		if (getMenuType() == InputMenu::MenuType::LOAD_FILE) {
			if (fileManager.loadFromFile(fileName, tab)) {
				_state->setState(State::STATE::TODO_LIST);
			}
			else {
				_state->setState(State::STATE::MAIN_MENU);
			}
		}
		else {
			_state->setState(State::STATE::TODO_LIST);
		}
	}
}


const InputMenu::MenuType& InputMenu::getMenuType() const {
	return menuType;
}


std::string& InputMenu::getFileName() {
	return fileName;
}

