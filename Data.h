#pragma once
#include "Resource.h"
typedef struct Data
{
	int roomNo = 0;

	//�»�� X,Y
	int UX = 0;
	int UY = 0;

	//���ϴ� X,Y
	int DX = 0;
	int DY = 0;

	//�߽���
	int CX = 0;
	int CY = 0;

	//����,���� ����
	int width = 0;
	int height = 0;

	bool onData = false;

}Data;