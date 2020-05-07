#pragma once
#include "Resource.h"
typedef struct Data
{
	int roomNo = 0;

	//좌상단 X,Y
	int UX = 0;
	int UY = 0;

	//우하단 X,Y
	int DX = 0;
	int DY = 0;

	//중심점
	int CX = 0;
	int CY = 0;

	//가로,세로 길이
	int width = 0;
	int height = 0;

	bool onData = false;

}Data;