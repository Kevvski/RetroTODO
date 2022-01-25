#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H
#include <Windows.h>
#include <conio.h>
#include "State.h"
#include "Key.h"
#include "MainMenu.h"
#include "InputMenu.h"
#include "TasksScene.h"
#include "InputTask.h"

class Application
{
public:
	Application();
	~Application();

	void run();
	void draw();
	void update();
	bool isRunning() const;

private:
	bool running;

	HANDLE consoleHandle;
	Key key;

	//Application state
	State appState;

	//Main menu
	MainMenu mainMenu;

	//New file and load file input
	InputMenu inputMenu;

	//Todo list 
	TasksScene tasksScene;

	//Input tasks
	InputTask inputTaskScene;
};

#endif // !APPLICATION_H

