#include "stdafx.h"
#include "TasksScene.h"


TasksScene::TasksScene() : index(0)
{
}


TasksScene::~TasksScene()
{
}


void TasksScene::init() {
	text.setText("TASKS:\n");
	text.setColor(DEFAULT_COLOR);
	toolsText.setText("1.Add    2.Delete    3.Done    4.Not Done    5.Save    6.Menu    7.Exit");
	toolsBox.setWidth(toolsText.getTextLength());
}


void TasksScene::draw(HANDLE* _handle) {
	toolsBox.drawSingleBox(&toolsText, _handle);
	std::cout << std::endl;
	text.draw(_handle);

	for (auto it : tasks) {
		it.draw(_handle);
		std::cout << std::endl;
	}			
}


void TasksScene::update(Key* _key, State* _state, InputMenu* _inputMenu) {
	_key->turnOn();

	if (tasks.size() > 0 && index != tasks.size()) {
		tasks.at(index).setColor(224);
	}

	if (_key->isPressed('1')) {
		_state->setState(State::STATE::INPUT_TASK);
	}
	else if (tasks.size() > 0 && _key->isPressed('2')) {
		tasks.erase(tasks.begin() + index);
	}
	else if (tasks.size() > 0 && _key->isPressed('3')) {
		tasks.at(index).setDone();
		tasks.at(index).getText().at(0) = 'V';
	}
	else if (tasks.size() > 0 && _key->isPressed('4')) {
		tasks.at(index).setNotDone();
		tasks.at(index).getText().at(0) = 'X';
	}
	else if (tasks.size() > 0 && _key->isPressed('5')) {
		fileManager.saveToFile(_inputMenu->getFileName(), &tasks);
	}
	else if (_key->isPressed('6')) {
		fileManager.saveToFile(_inputMenu->getFileName(), &tasks);
		tasks.clear();
		_state->setState(State::STATE::MAIN_MENU);
	}
	else if (_key->isPressed('7')) {
		_key->turnOff();
		fileManager.saveToFile(_inputMenu->getFileName(), &tasks);
		_state->setState(State::STATE::EXIT);
	}

	if (tasks.size() != 0 && index < tasks.size() - 1 && _key->isPressed(static_cast<char>(KEY_DOWN))) {
		index++;
		tasks.at(index).setColor(224);
		tasks.at(index - 1).isDone() ? tasks.at(index - 1).setColor(10) : tasks.at(index - 1).setColor(12);
	}
	else if (index > 0 && _key->isPressed(static_cast<char>(KEY_UP))) {
		index--;
		tasks.at(index).setColor(224);

		if(index != tasks.size() - 1)
			tasks.at(index + 1).isDone() ? tasks.at(index + 1).setColor(10) : tasks.at(index + 1).setColor(12);
	}

}


std::vector<TextLine>& TasksScene::getTasks() {
	return tasks;
}
