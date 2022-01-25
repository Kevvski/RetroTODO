#pragma once
#ifndef TASKSSCENE_H
#define TASKSSCENE_H
#include "TextLine.h"
#include "TextBox.h"
#include "Key.h"
#include "InputMenu.h"
#include "FileManager.h"
#include <vector>

class TasksScene
{
public:
	TasksScene();
	~TasksScene();

	void init();
	void draw(HANDLE* _handle);
	void update(Key* _key, State* _state, InputMenu* _inputMenu);
	std::vector<TextLine>& getTasks();

private:
	TextLine text;
	TextLine toolsText;
	TextBox toolsBox;
	std::vector<TextLine> tasks;
	int index;
	FileManager fileManager;
};

#endif // !TASKSSCENE_H

