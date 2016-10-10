#pragma once
#include "Automat.h"

class Command
{
private:
	States currentState;
	char symbol;
	States nextState;

public:
	Command(States currentState, char symbol, States nextState);
	~Command();
	bool matchState(States state, char symbol);
	States getNextState();
};
