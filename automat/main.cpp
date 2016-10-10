#include "Automat.h"
#include "Command.h"
#include <vector>
#include <iostream>

int main()
{
	vector<Command> program;
	program.push_back(Command(q0, '0', q1));
	program.push_back(Command(q0, '1', q0));
	program.push_back(Command(q1, '0', q0));
	program.push_back(Command(q1, '1', q2));
	program.push_back(Command(q2, '0', q0));
	program.push_back(Command(q2, '1', q3));
	program.push_back(Command(q3, '0', q0));
	program.push_back(Command(q3, '1', q4));
	program.push_back(Command(q4, '0', q0));
	program.push_back(Command(q4, '1', q4));

	vector<States> finalStates;
	finalStates.push_back(q4);

	Automat a(program, q0, finalStates);
	bool result = a.run("data.txt");
	cout << (result ? "yes" : "no") << endl;

	return 0;
}