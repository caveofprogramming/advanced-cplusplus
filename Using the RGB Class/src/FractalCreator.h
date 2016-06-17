/*
 * FractalCreator.h
 *
 *  Created on: Sep 21, 2015
 *      Author: johnpurcell
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace caveofprogramming {

class FractalCreator {
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total { 0 };

private:
	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();
	void writeBitmap(string name);

public:
	FractalCreator(int width, int height);
	void addZoom(const Zoom& zoom);
	virtual ~FractalCreator();
	void run(string name);
};

} /* namespace caveofprogramming */

#endif /* FRACTALCREATOR_H_ */
