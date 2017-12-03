#pragma once
#include <windows.h>

static int nBufferIndex;
static HANDLE hBuffer[2];

class screenBuffer {
public:
	screenBuffer();
	~screenBuffer();

	void CreateBuffer();
	void BufferWrite(int, int, char*);
	void Flipping();
	void BufferClear();
	void Release();
};