#include "stdafx.h"
#include "InputTask.h"


InputTask::InputTask()
{
}


InputTask::~InputTask()
{
}


void InputTask::update(Key* _key, State* _state, std::vector<TextLine>* tab) {
	_key->turnOff();

	TextLine* localText = new TextLine();
	localText->setColor(12);

	if (!_key->isWorking()) {
		std::getline(std::cin, getFileName());

		if (getFileName().empty()) {
			std::cout << "Please input something :)" << std::endl;
		}
		else {
			localText->setText("X " + getFileName());
			tab->push_back(*localText);
		}
	}

	if (!getFileName().empty()){
		getFileName().clear();
		_state->setState(State::STATE::TODO_LIST);
	}
}
