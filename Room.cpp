#include "Resource.h"
#include "Room.h"
//Room Class

//���� ����/�����õ� ������



//1. ���� ��Ʈ
int Room::room_no = 0;

Room::Room() {		//��ǥ�� ����, ������ ����
	is_interaction = false;
	room_no++;
	Generator();
}


Room::Room(int center_x, int center_y) {	//�߽���ǥ �־��
	room_no++;
	pair<int, int> center;
	center = make_pair(center_x,center_y);
	
	is_interaction = false;

	Generator(center);
}

Room::Room(int tp_LX, int tp_LY, int tp_RX, int tp_RY) {	//���� �̻��ѵ�
	room_no++;
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
bool Room::Generator() {		//���� 1 : ���� ����
	int tp_LX;
	int tp_LY;
	int tp_RX;
	int tp_RY;
	pair<int, int> temp_L;
	pair<int, int> temp_R;

	tp_LX = rand() % MAX_AXIS + 1;
	tp_LY = rand() % MAX_AXIS + 1;
	tp_RX = tp_LX + (rand() % MAX_LENGTH + 1);		//��� ��ǥ ������ �ƴ϶�
	tp_RY = tp_LY + (rand() % MAX_LENGTH + 1);		//��ǥ + ������ ����

	temp_L = make_pair(tp_LX, tp_LY);
	temp_R = make_pair(tp_RX, tp_RY);


	if (Valid_Generate(temp_L, temp_R) == true) {
		cout << "Hi" << endl;
		this->Axis_LX = tp_LX;
		this->Axis_LY = tp_LY;
		this->Axis_RX = tp_RX;
		this->Axis_RY = tp_RY;

		this->Center_X = (Axis_RX + Axis_LX) / 2;
		this->Center_Y = (Axis_RY + Axis_LY) / 2;

		this->width = Axis_RX - Axis_LX;
		this->height = Axis_RY - Axis_LY;
	}
	else
		return false;
		
	return true;

}
bool Room::Generator(pair<int,int> center) {	//���� 2 : �߽���ǥ����, ����,���� ����
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


//2. �˻� ��Ʈ (���� �߻��� 1�� ���ư�)
bool Room::Valid_Length() {
	if (width < 1 || height < 1) {
		//���� �޼��� ȣ��

		return false;
	}
	return true;
}
bool Room::Valid_Generate(pair<int, int> axis_L, pair<int, int> axis_R) {			//�������� �������� �˻�

	if (!(Valid_Axis(axis_L) && Valid_Axis(axis_R) && true)) 	//=���� �ϳ��� false�� ��
#ifdef BREAK			//Break Ȱ��ȭ ��
	{
		//���� ���� �����޼��� ���
		RoomBreak();
		return false;
	}
#endif // BREAK
#ifndef BREAK			//Break �� Ȱ��ȭ ��
	{
		//Re-Generate
		return false;
	}
#endif // !BREAK

	return true;
}
bool Room::Valid_Axis(pair<int,int> axis) {			//���� ������ �Ѿ����� �˻�.
	return axis.first > 0 && axis.second > 0 ? true : false;
}
void Room::Axis_changer() {		//��� ��Ʈ���� vector �Ἥ ���°� �������� �� >.��
	int temp_x;
	int temp_y;

	temp_x = Axis_LX;
	Axis_LX = Axis_RX;
	Axis_RX = temp_x;

	temp_y = Axis_LY;
	Axis_LY = Axis_RY;
	Axis_RY = temp_y;
}
//3. ��� ��Ʈ
void Room::data_printer() {
	cout << "---------------" << endl;
	cout << "Room No :: " + room_no << endl;
	cout << endl;
	cout << "( " + this->Axis_LX << "," << this->Axis_LY + " )\t\t\t";
	cout << "( " + this->Axis_RX << "," << this->Axis_LY + " )"<<endl;
	cout << "( " + this->Axis_LX << "," << this->Axis_RY + " )\t\t\t";
	cout << "( " + this->Axis_RX << "," << this->Axis_RY + " )" << endl;
	//cout << "���� : " + width << "���� : " + height << endl;
	cout << "---------------" << endl;
}
//4. �ı� ��Ʈ
void Room::RoomBreak() {
	

	delete(this);
}
Room::~Room() {
	try {
		free(this);
	}
	catch (exception e) {
		printf("���! ������ ���� ���ŵ��� ������ �߻��Ͽ����ϴ�!");
		cout << e.what() << endl;		// <<- �׷� ��� ����
	}
}