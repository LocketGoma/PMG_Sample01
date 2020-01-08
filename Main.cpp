#pragma once

#include "Resource.h"
#include "RoomData.h"
#include "InterfaceRoom.h"

void Set_Random_Generator() {
	srand((unsigned int)time(NULL));
}

int main() {
	Set_Random_Generator();	

	//����ٰ��� interfaceroom �� �����Լ��� ����� �� �����.

	InterfaceRoom* ifr = new InterfaceRoom();
	RoomData* rm = new RoomData();

	cout << "������ ���ϴ� �� ������ �Է��ϼ���" << endl;
	int temp;
	cin >> temp;
	rm->MakeRooms(temp);
	set<Room> rooms = rm->getlist();
	set<Room>::iterator iter;
	
	

	for (iter = rooms.begin(); iter != rooms.end(); ++iter) {		
		Room temp = *iter;
		temp.data_printer();
	}

	cout << rooms.size() << "Rooms" << endl;

	
	ifr->mapprint(&rooms);		

	


	system("pause");
	return 0;
}


