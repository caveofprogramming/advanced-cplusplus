/*
 * ZoomList.cpp
 *
 *  Created on: Sep 20, 2015
 *      Author: johnpurcell
 */

#include "ZoomList.h"

namespace caveofprogramming {

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {
	// TODO Auto-generated constructor stub

}

void ZoomList::add(const Zoom& zoom) {
	zooms.push_back(zoom);
}

pair<double, double> ZoomList::doZoom(int x, int y) {
	return pair<double, double>(0, 0);
}

} /* namespace caveofprogramming */
