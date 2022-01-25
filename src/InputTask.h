#pragma once
#ifndef INPUTTASK_H
#define INPUTTASK_H
#include "InputMenu.h"
#include "TextLine.h"
#include <vector>


class InputTask : public InputMenu
{
public:
	InputTask();
	~InputTask();


	virtual void update(Key* _key, State* _state, std::vector<TextLine>* tab);
};

#endif // !INPUTTASK_H

