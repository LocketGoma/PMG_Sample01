#pragma once

#include "Resource.h"
#include "RoomData.h"

void Set_Random_Generator() {
	srand((unsigned int)time(NULL));
}

int main() {
	Set_Random_Generator();

	/*
	Room *rm1 = new Room();
	rm1->Maker();
	rm1->data_printer();
	//rm1->data_printer();

	Room* rm2 = new Room();
	rm2->Maker();
	rm2->data_printer();
	*/
	
	RoomData* rm = new RoomData();
	rm->MakeRooms(7);
	set<Room> rooms = rm->getlist();
	set<Room>::iterator iter;
	
	for (iter = rooms.begin(); iter != rooms.end(); ++iter) {
		Room temp = *iter;
		temp.data_printer();
	}
	

	system("pause");
	return 0;
}


