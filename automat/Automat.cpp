// automat.cpp : Defines the entry point for the console application.
//

#include "Automat.h"
#include "stdafx.h"

#include <fstream>
#include <iostream>

using namespace std;

Automat::Automat()
{
	result = false;
	state = &Automat::q0;
}

Automat::~Automat()
{}

void Automat::q0(char c)
{
	result = false;
	switch (c)
	{
	case '0':
		state = &Automat::q1;
		break;
	case '1':
		state = &Automat::qf;
		break;
	default:
		break;
	}
}

void Automat::q1(char c)
{
	result = false;
	switch (c)
	{
	case '0':
		state = &Automat::q0;
		break;
	case '1':
		state = &Automat::q2;
		break;
	default:
		break;
	}
}

void Automat::q2(char c)
{
	result = false;
	switch (c)
	{
	case '0':
		state = &Automat::qf;
		break;
	case '1':
		state = &Automat::q1;
		break;
	default:
		break;
	}
}

void Automat::qf(char c)
{
	result = true;
	switch (c)
	{
	case '0':
		state = &Automat::q2;
		break;
	case '1':
		state = &Automat::q0;
		break;
	default:
		break;
	}
}


void Automat::run(string filename)
{
	ifstream file(filename);
	while (!file.eof())
	{
		char c = file.get();
		(this->*state)(c);
	}
	file.close();
	cout << (result ? "yes" : "no") << endl;
}


