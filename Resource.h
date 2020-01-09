#pragma once
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "Data.h"


#define BREAK
#define MIN_AXIS 0					//좌표 최소값
#define MAX_AXIS 50					//좌표 최대값
#define MIN_LENGTH 3				//길이 최소값
#define MAX_LENGTH 7				//길이 최대값
#define MAX_Rooms 51				//최대 방 개수
#define MAX_TRY MAX_AXIS*MAX_AXIS	//최대 시도 회수 (= 좌표 최대 크기의 제곱)

using namespace std;



/*
1. 범위 : 0~xx
2. 개수 : 1~xx
3. 충돌검사 여부 : 확인함
*/

/* 구현할것
1. 방 생성 후 방을 Node로 삼아 Tree구조로 재배치
2. Tree구조로 배치된 기준하여 방 연결
3. 'JSON 양식'으로 출력시키기.

*/

/*
https://github.com/Microsoft/vcpkg/
https://github.com/open-source-parsers/jsoncpp

*/