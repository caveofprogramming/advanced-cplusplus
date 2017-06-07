/*
 * FractalCreator.h
 *
 *  Created on: Sep 21, 2015
 *      Author: johnpurcell
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include "Zoom.h"

using namespace std;

namespace caveofprogramming {

class FractalCreator {
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(string name);
};

} /* namespace caveofprogramming */

#endif /* FRACTALCREATOR_H_ */
