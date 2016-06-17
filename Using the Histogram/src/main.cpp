//============================================================================
// Name        : Fractal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdint>
#include <memory>
#include "Mandelbrot.h"
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {

	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = -999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS] { 0 });
	unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT] { 0 });

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y * WIDTH + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}

		}
	}

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			int iterations = fractal[y * WIDTH + x];

			double hue = 0.0;

			for (int i = 0; i <= iterations; i++) {
				hue += ((double) histogram[i]) / total;
			}

			uint8_t red=0;
			uint8_t green=hue*255;
			uint8_t blue=0;

			bitmap.setPixel(x, y, red, green, blue);

		}
	}

	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
