//============================================================================
// Name        : Fractal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "FractalCreator.h"
#include "Zoom.h"

using namespace caveofprogramming;

int main() {

	FractalCreator fractalCreator(800, 600);

	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.run("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}
