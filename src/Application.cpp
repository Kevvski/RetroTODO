#include "stdafx.h"
#include "Application.h"


Application::Application() : running(false)
{
}


Application::~Application()
{
}


void Application::run() {
	running = true;
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(L"RetroTODO");
	

	key.turnOn();
	mainMenu.init();
	inputMenu.setQuestion("Please input a file name: ");
	tasksScene.init();
	inputTaskScene.setQuestion("Add task: ");

	while (isRunning()) {
		draw();
		update();
	}
}


void Application::draw() {
	system("cls");
	switch (appState.getState())
	{
	case State::STATE::MAIN_MENU: mainMenu.draw(&consoleHandle); break;
	case State::STATE::INPUT_MENU: inputMenu.draw(); break;
	case State::STATE::TODO_LIST: tasksScene.draw(&consoleHandle); break;
	case State::STATE::INPUT_TASK: inputTaskScene.draw(); break;
	}
}


void Application::update() {
	if(key.isWorking()) key.listenKey();

	switch (appState.getState())
	{
	case State::STATE::MAIN_MENU: mainMenu.update(&key, &appState, &inputMenu); break;
	case State::STATE::INPUT_MENU: inputMenu.update(&key, &appState, &tasksScene.getTasks()); break;
	case State::STATE::TODO_LIST: tasksScene.update(&key, &appState, &inputMenu); break;
	case State::STATE::INPUT_TASK: inputTaskScene.update(&key, &appState, &tasksScene.getTasks()); break;
	case State::STATE::EXIT:
		std::cout << "Thank you for use me :)! Bye!" << std::endl;
		Sleep(1500);
		running = false; 
		break;
	}
}


bool Application::isRunning() const {
	return running;
}