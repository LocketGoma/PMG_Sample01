#pragma once
#include <set>
#include "Resource.h"
#include "Room.h"

//Space & Tree Ŭ���� ��ü?

class RoomData {
	public :
		RoomData();
		bool MakeRooms();	//�ִ밪���� ����
		bool MakeRooms(int);//���������� ����
		bool addRooms(Room *);
		set <Room> getlist();
		set <Room> Roomlist;
	
	private :				
		bool CheckIntersection(Room *);
};