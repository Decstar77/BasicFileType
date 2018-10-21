#pragma once

#include <cstdint>

#pragma(2)

struct FileHeader
{
	char Header[2]{ 'D', 'M' }; // 2Bytes
	int32_t fileSize;			// 4Bytes
	int32_t headersSize;		// 4Bytes
	int32_t dataOffset;			// 4Bytes	
};