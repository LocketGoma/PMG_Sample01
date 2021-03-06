#include "Resource.h"
#include "Room.h"
//Room Class

//공용 랜덤/랜덤시드 생성기



//1. 생성 파트
//* 세부 노드 (노드 내부 데이터)
//이게 지금 '생성 시도 시' 숫자가 올라가는데...
int Room::room_count = 0;

Room::Room() {		//좌표값 랜덤, 사이즈 랜덤
	is_interaction = false;

	this->Axis_LX=0;				//좌측 상단 X
	this->Axis_LY=0;				//좌측 상단 Y
	this->Axis_RY=0;				//우측 하단 Y
	this->Axis_RX=0;				//우측 하단 X
	this->Center_X=0;				//중심 X
	this->Center_Y=0;				//중심 Y


	this->width=0;					//가로 길이
	this->height=0;					//세로 길이

	room_no = 0;
}
void Room::Maker() {							//1. 자동 생성
	Generator();
}

void Room::Maker(int center_x, int center_y) {	//2. 중심좌표 지정
	pair<int, int> center;
	center = make_pair(center_x,center_y);
	
	is_interaction = false;

	Generator(center);
}
//중심좌표 + 크기 지정도 있어야 하지 않을까?

void Room::Maker(int tp_LX, int tp_LY, int tp_RX, int tp_RY) {	//3. 전체 크기 지정
	is_interaction = false;
	this->Axis_LX = tp_LX;
	this->Axis_LY = tp_LY;
	this->Axis_RX = tp_RX;
	this->Axis_RY = tp_RY;

	pair<int, int> temp_L;
	pair<int, int> temp_R;
	temp_L = make_pair(tp_LX,tp_LY);
	temp_R = make_pair(tp_RX,tp_RY);

	Valid_Generate(temp_L,temp_R);

	this->Center_X = (Axis_RX + Axis_LX)/2;
	this->Center_Y = (Axis_RY + Axis_LY)/2;

	this->width = Axis_RX - Axis_LX;
	this->height = Axis_RY - Axis_LY;
}

bool Room::Generator() {		//생성 1 : 전부 랜덤
	int tp_LX;
	int tp_LY;
	int tp_RX;
	int tp_RY;
	pair<int, int> temp_L;
	pair<int, int> temp_R;

	tp_LX = rand() % MAX_AXIS + 1;
	tp_LY = rand() % MAX_AXIS + 1;
	tp_RX = tp_LX + (rand() % MAX_LENGTH + MIN_LENGTH);		//모든 좌표 랜덤이 아니라
	tp_RY = tp_LY + (rand() % MAX_LENGTH + MIN_LENGTH);		//좌표 + 사이즈 랜덤

	temp_L = make_pair(tp_LX, tp_LY);
	temp_R = make_pair(tp_RX, tp_RY);


	//if (Valid_Generate(temp_L, temp_R) == true) {
		//cout << "Hi" << endl;
		this->Axis_LX = tp_LX;
		this->Axis_LY = tp_LY;
		this->Axis_RX = tp_RX;
		this->Axis_RY = tp_RY;

		this->Center_X = (Axis_RX + Axis_LX) / 2;
		this->Center_Y = (Axis_RY + Axis_LY) / 2;

		this->width = Axis_RX - Axis_LX;
		this->height = Axis_RY - Axis_LY;
	//}
	//else
	//	return false;
		
	return true;

}
bool Room::Generator(pair<int,int> center) {	//생성 2 : 중심좌표기준, 길이,높이 랜덤
	int tp_width;
	int tp_height;
	pair<int, int> temp_L;
	pair<int, int> temp_R;

	tp_width = rand() % MAX_LENGTH + 1;
	tp_height = rand() % MAX_LENGTH + 1;

	temp_L = make_pair(center.first - (tp_width / 2), center.second - (tp_height / 2));
	temp_R = make_pair(center.first + (tp_width / 2), center.second + (tp_height / 2));

	if (Valid_Generate(temp_L, temp_R) == true) {
		this->Axis_LX = temp_L.first;
		this->Axis_LY = temp_L.second;
		this->Axis_RX = temp_R.first;
		this->Axis_RY = temp_R.second;

		this->Center_X = center.first;
		this->Center_Y = center.second;
		this->width = tp_width;
		this->height = tp_height;

	}
	else
		return false;
	
	return true;
}

//2. 검사 파트 (문제 발생시 1로 돌아감)
bool Room::Valid_Length() {
	if (width < 1 || height < 1) {
		//에러 메세지 호출

		return false;
	}
	return true;
}
bool Room::Valid_Generate(pair<int, int> axis_L, pair<int, int> axis_R) {			//정상적인 생성인지 검사

	if (!(Valid_Axis(axis_L) && Valid_Axis(axis_R) && true)) 	//=셋중 하나라도 false일 시
#ifdef BREAK			//Break 활성화 시
	{
		//생성 실패 에러메세지 출력
		//RoomBreak();
		return false;
	}
#endif // BREAK
#ifndef BREAK			//Break 비 활성화 시
	{
		//Re-Generate
		return false;
	}
#endif // !BREAK



	return true;
}
void Room::Confirm_Room() {
	room_count++;

	this->room_no = room_count;
}
bool Room::Valid_Axis(pair<int,int> axis) {			//축이 범위를 넘었는지 검사.
	return axis.first > 0 && axis.second > 0 ? true : false;
}
void Room::Axis_changer() {		//사실 세트값은 vector 써서 쓰는게 나을지도 모름 >.ㅇ
	int temp_x;
	int temp_y;

	temp_x = Axis_LX;
	Axis_LX = Axis_RX;
	Axis_RX = temp_x;

	temp_y = Axis_LY;
	Axis_LY = Axis_RY;
	Axis_RY = temp_y;
}
//3. 출력 파트
void Room::data_printer() {
	cout << "---------------" << endl;
	cout << "Room No :: " << room_no << endl;
	cout << endl;
	cout << "( " << this->Axis_LX << "," << this->Axis_LY << " )\t\t\t";
	cout << "( " << this->Axis_RX << "," << this->Axis_LY <<" )"<<endl;
	cout << "( " << this->Axis_LX << "," << this->Axis_RY <<" )\t\t\t";
	cout << "( " << this->Axis_RX << "," << this->Axis_RY <<" )" << endl;
	cout << "길이 : " << width << "\t높이 : " << height << endl;
	cout << "---------------" << endl;
}

Data Room::getData() {
	Data data;
	
	data.roomNo = room_no;

	data.UX = Axis_LX;
	data.UY = Axis_LY;

	data.DX = Axis_RX;
	data.DY = Axis_RY;


	data.CX = Center_X;
	data.CY = Center_Y;

	data.width = width;
	data.height = height;

	return data;
}

//4. 파괴 파트
/*
void Room::RoomBreak() {
	

	delete(this);
}

Room::~Room() {
	room_no--;
	try {
		free(this);
	}
	catch (exception e) {
		printf("경고! 생성된 방을 제거도중 오류가 발생하였습니다!");
		cout << e.what() << endl;		// <<- 그럼 얘는 뭔데
	}
}
*/
