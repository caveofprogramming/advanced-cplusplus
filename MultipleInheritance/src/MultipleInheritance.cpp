//============================================================================
// Name        : Multiple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class MusicalInstrument {
public:
	virtual void play(){ cout << "Playing instrument ..." << endl; }
	virtual void reset(){ cout << "Resetting instrument ..." << endl; }
	virtual ~MusicalInstrument(){};
};

class Machine {
public:
	virtual void start(){ cout << "Starting machine ..." << endl; }
	virtual void reset(){ cout << "Resetting machine ..." << endl; }
	virtual ~Machine(){};
};

class Synthesizer: public Machine, public MusicalInstrument {
public:
	virtual ~Synthesizer(){};
};

int main() {

	Synthesizer *pSynth = new Synthesizer();

	pSynth->play();
	pSynth->start();
	pSynth->Machine::reset();

	delete pSynth;
	return 0;
}
