#pragma once
#include <set>
#include "Resource.h"
#include "Room.h"

//Space & Tree 클래스 대체?

class RoomData {
	public :
		RoomData();
		bool MakeRooms();	//최대값까지 생성
		bool MakeRooms(int);//지정값까지 생성
		bool addRooms(Room *);
		set <Room> getlist();
		set <Room> Roomlist;
	
	private :				
		bool CheckIntersection(Room *);
};