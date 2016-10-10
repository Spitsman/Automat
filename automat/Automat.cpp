// automat.cpp : Defines the entry point for the console application.
//

#include "Automat.h"
#include "Command.h"
#include "stdafx.h"

#include <fstream>
#include <iostream>

using namespace std;

Automat::Automat(const vector<Command>& program, States startState, const vector<States>& finalStates)
{
	this->program = program;
	this->startState = startState;
	this->finalStates = finalStates;
}

Automat::~Automat()
{}

bool Automat::run(string filename)
{
	currentState = startState;

	ifstream file(filename);
	while (!file.eof())
	{
		char c = file.get();
		processCommand(c);
	}
	file.close();

	return std::find(finalStates.begin(), finalStates.end(), currentState) != finalStates.end();
}

void Automat::processCommand(char c)
{
	for each (Command cmd in program)
	{
		if (cmd.matchState(currentState, c))
		{
			currentState = cmd.getNextState();
			return;
		}
	}
}
