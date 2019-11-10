#include "RoomData.h"
//(MakeRooms) -> Room 생성 -> addRooms 호출 -> addRooms 내부에서 CheckIntersection.

RoomData::RoomData() {

}
bool RoomData::MakeRooms() {
	int check = 0;
	while (Roomlist.size() != MAX_Rooms) {
		Room* tempRoom = new Room;

		tempRoom->Maker();
		try {
			while (addRooms(tempRoom) == false) {
				tempRoom->Maker();


				if (check++ > MAX_TRY) {
					cout << "과도한 중복 체크로 인한 생성 중지" << endl;
					return false;
				}
			}
		}
		catch (exception e) {
			cout << "생성 오류!!" << endl;
			return false;
		}
	}
	return true;
}
bool RoomData::MakeRooms(int max) {
	int check = 0;
	while (Roomlist.size() != max) {
		Room* tempRoom = new Room;

		tempRoom->Maker();
		try {
			while (addRooms(tempRoom) == false) {
				tempRoom->Maker();

				if (check++ > MAX_TRY) {
					cout << "과도한 중복 체크로 인한 생성 중지" << endl;
					return false;
				}
			}
		}
		catch (exception e) {
			cout << "생성 오류!!" << endl;
			return false;
		}
	}
	return true;
}
bool RoomData::addRooms(Room* tempRoom) {
	if (CheckIntersection(tempRoom) == true)
	{
		Roomlist.insert(*tempRoom);
		return true;
	}
	else
		return false;
}
bool RoomData::CheckIntersection(Room *testRoom) {		//분명 문제 터질거같으니 주의
	if (Roomlist.empty() == true)
		return true;

	set<Room>::iterator iter;
	Room temp;
	Data tempData;
	Data testData;
	testData = testRoom->getData();
	
	for (iter = Roomlist.begin(); iter != Roomlist.end(); ++iter) {
		temp = *iter;
		tempData=temp.getData();

		if (tempData.UX <= testData.DX && tempData.DX >= testData.UX && tempData.UY <= testData.DY && tempData.DY >= testData.UY)
			return false;

	}	
	return true;

	//return (x1 <= room.x2 && x2 >= room.x1 && y1 <= room.y2 && room.y2 >= room.y1);
	//1. x1 <= room.x2 == 현재 방의 좌상단 x좌표가 비교 방 우하단 x보다 좌측에 있는가
	//2. x2 >= room.x1 == 현재 방의 우하단 x좌표가 비교 방 좌상단 x보다 우측에 있는가
	//3. y1 <= room.y2 == 현재 방의 좌상단 y좌표가 비교 방 우하단 y보다 위에 있는가
	//4. y2 >= room.y1 == 현재 방의 우하단 y좌표가 비교 방 좌상단 y보다 아래에 있는가
	//https://bit.ly/33AybDU	
}
set<Room> RoomData::getlist() {
	return Roomlist;
}