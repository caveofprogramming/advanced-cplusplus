/*
 * FractalCreator.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: johnpurcell
 */

#include "FractalCreator.h"

using namespace std;

namespace caveofprogramming {

void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);

	if (m_bGotFirstRange) {
		m_rangeTotals.push_back(0);
	}

	m_bGotFirstRange = true;
}

int FractalCreator::getRange(int iterations) const {
	int range = 0;

	for (int i = 1; i < m_ranges.size(); i++) {

		if (m_ranges[i] > iterations) {
			break;
		}

		range = i;
	}

	return range;
}

void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::run(string name) {
	calculateIteration();
	calculateTotalIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmap("test.bmp");

}

FractalCreator::FractalCreator(int width, int height) :
		m_width(width), m_height(height), m_histogram(
				new int[Mandelbrot::MAX_ITERATIONS] { 0 }), m_fractal(
				new int[m_width * m_height] { 0 }), m_bitmap(m_width, m_height), m_zoomList(
				m_width, m_height) {
	// TODO Auto-generated constructor stub
	m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

FractalCreator::~FractalCreator() {
}

void FractalCreator::calculateIteration() {

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first,
					coords.second);

			m_fractal[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				m_histogram[iterations]++;
			}

		}
	}
}

void FractalCreator::calculateRangeTotals() {

	int rangeIndex = 0;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		int pixels = m_histogram[i];

		if (i >= m_ranges[rangeIndex + 1]) {
			rangeIndex++;
		}

		m_rangeTotals[rangeIndex] += pixels;
	}
}

void FractalCreator::calculateTotalIterations() {

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		m_total += m_histogram[i];
	}
}

void FractalCreator::drawFractal() {

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {

			int iterations = m_fractal[y * m_width + x];

			int range = getRange(iterations);
			int rangeTotal = m_rangeTotals[range];
			int rangeStart = m_ranges[range];

			RGB& startColor = m_colors[range];
			RGB& endColor = m_colors[range + 1];
			RGB colorDiff = endColor - startColor;

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				int totalPixels = 0;

				for (int i = rangeStart; i <= iterations; i++) {
					totalPixels += m_histogram[i];
				}

				red = startColor.r
						+ colorDiff.r * (double) totalPixels / rangeTotal;
				green = startColor.g
						+ colorDiff.g * (double) totalPixels / rangeTotal;
				blue = startColor.b
						+ colorDiff.b * (double) totalPixels / rangeTotal;

			}

			m_bitmap.setPixel(x, y, red, green, blue);

		}
	}

}

void FractalCreator::writeBitmap(string name) {
	m_bitmap.write(name);
}

} /* namespace caveofprogramming */
