#include "stdafx.h"
#include "State.h"


State::State() : state(State::STATE::MAIN_MENU)
{
}


State::~State()
{
}


void State::setState(const State::STATE& _state) {
	state = _state;
}


const State::STATE& State::getState(){
	return state;
}
