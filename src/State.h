#pragma once
#ifndef STATE_H
#define STATE_H
#include <iostream>

class State
{
public:
	State();
	~State();

	enum STATE { MAIN_MENU, INPUT_MENU, TODO_LIST, INPUT_TASK, EXIT };

	void setState(const State::STATE& _state);
	const State::STATE& getState();

private:
	STATE state;
};

#endif // !STATE_H

