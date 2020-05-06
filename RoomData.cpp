#include "RoomData.h"
//(MakeRooms) -> Room 생성 -> addRooms 호출 -> addRooms 내부에서 CheckIntersection.

RoomData::RoomData() {

}
bool RoomData::MakeRooms(int max) {
	if (max < 1)
		max = MAX_Rooms;

	auto result = (MakeRoomsRun(max));

	Write_RoomNo();

	return result;
}
bool RoomData::MakeRoomsRun(int runs) {
	int check = 0;
	while (Roomlist.size() != runs) {
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
// https://elldeekei.tistory.com/entry/STL-stdset-에-저장된-엘리먼트의-값을-바꿔보자

void RoomData::Write_RoomNo() {
	set<Room>::iterator iter;

	for (iter = Roomlist.begin(); iter != Roomlist.end(); ++iter) {
		const_cast<Room&>(*iter).Confirm_Room();
	}
	//1. iter로 접근하고
	//2. iter 포인터의 내용물을 받아온 후에
	//3. 이를 Room 포인터 타입으로 인지하고
	//4. 3의 상수성을 깨트린다. (접근 및 수정 가능)
	//5. 값 수정

}