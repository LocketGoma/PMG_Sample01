#pragma once
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "Data.h"


#define BREAK
#define MIN_AXIS 0					//��ǥ �ּҰ�
#define MAX_AXIS 60					//��ǥ �ִ밪
#define MIN_LENGTH 3				//���� �ּҰ�
#define MAX_LENGTH 7				//���� �ִ밪
#define MAX_Rooms 11				//�ִ� �� ����
#define MAX_TRY MAX_AXIS*(MIN_AXIS+1)

using namespace std;





/*
1. ���� : 0~xx
2. ���� : 1~xx
3. �浹�˻� ���� : Ȯ����
*/

/* �����Ұ�
1. �� ���� �� ���� Node�� ��� Tree������ ���ġ
2. Tree������ ��ġ�� �����Ͽ� �� ����


*/