#pragma once

#include "stdafx.h"
#include <string>

class Automat;

typedef void(Automat::*func)(char c);

using namespace std;

class Automat
{

private:

	void q0(char c);

	void q1(char c);

	void q2(char c);

	void qf(char c);

	func state;

	bool result;

public:

	Automat();

	~Automat();

	void run(string filename);
};