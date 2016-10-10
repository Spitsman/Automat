#include "Command.h"
#include "Automat.h"

Command::Command(States currentState, char symbol, States nextState)
{
	this->currentState = currentState;
	this->symbol = symbol;
	this->nextState = nextState;
}

Command::~Command()
{}

bool Command::matchState(States state, char symbol)
{
	return (state == this->currentState && symbol == this->symbol);
}

States Command::getNextState()
{
	return nextState;
}