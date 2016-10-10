#pragma once

#include "stdafx.h"

#include <string>
#include <vector>

using namespace std;

class Command; 

enum States { q0, q1, q2, q3, q4 };

class Automat
{

private:
	
	vector<Command> program;
	States currentState;
	States startState;
	vector<States> finalStates;
	void processCommand(char c);

public:

	Automat(const vector<Command>& program, States startState, const vector<States>& finalStates);
	~Automat();
	bool run(string filename);
};