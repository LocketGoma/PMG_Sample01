#pragma once

#include "Resource.h"
#include "RoomData.h"
#include "InterfaceRoom.h"

void Set_Random_Generator() {
	srand((unsigned int)time(NULL));
}

int main() {
	Set_Random_Generator();
	
	RoomData* rm = new RoomData();
	rm->MakeRooms(14);
	set<Room> rooms = rm->getlist();
	set<Room>::iterator iter;
	
	for (iter = rooms.begin(); iter != rooms.end(); ++iter) {		
		Room temp = *iter;
		temp.data_printer();
	}
	InterfaceRoom *ifr = new InterfaceRoom();

	ifr->mapprint(&rooms);
		

	system("pause");
	return 0;
}


