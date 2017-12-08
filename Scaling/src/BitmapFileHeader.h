/*
 * BitmapFileHeader.h
 *
 *  Created on: Jun 21, 2015
 *      Author: johnpurcell
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

namespace caveofprogramming {

#pragma pack(push, 2)

struct BitmapFileHeader {
	char header[2] { 'B', 'M' };
	int32_t fileSize;
	int32_t reserved { 0 };
	int32_t dataOffset;
};

#pragma pack(pop)

}

#endif /* BITMAPFILEHEADER_H_ */
