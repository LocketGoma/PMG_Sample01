#pragma once
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "Data.h"


#define BREAK
#define MIN_AXIS 0					//��ǥ �ּҰ�
#define MAX_AXIS 50					//��ǥ �ִ밪
#define MIN_LENGTH 3				//���� �ּҰ�
#define MAX_LENGTH 7				//���� �ִ밪
#define MAX_Rooms 51				//�ִ� �� ����
#define MAX_TRY MAX_AXIS*MAX_AXIS	//�ִ� �õ� ȸ�� (= ��ǥ �ִ� ũ���� ����)

using namespace std;



/*
1. ���� : 0~xx
2. ���� : 1~xx
3. �浹�˻� ���� : Ȯ����
*/

/* �����Ұ�
1. �� ���� �� ���� Node�� ��� Tree������ ���ġ
2. Tree������ ��ġ�� �����Ͽ� �� ����
3. 'JSON ���'���� ��½�Ű��.

*/

/*
https://github.com/Microsoft/vcpkg/
https://github.com/open-source-parsers/jsoncpp

*/