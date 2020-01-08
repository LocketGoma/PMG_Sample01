#pragma once

#include "Resource.h"
#include "RoomData.h"
#include "InterfaceRoom.h"

void Set_Random_Generator() {
	srand((unsigned int)time(NULL));
}

int main() {
	Set_Random_Generator();	

	//여기다가는 interfaceroom 의 내부함수만 남기고 싹 지우기.

	InterfaceRoom* ifr = new InterfaceRoom();
	RoomData* rm = new RoomData();

	cout << "생성을 윈하는 방 개수를 입력하세요" << endl;
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


