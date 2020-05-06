#include "RoomData.h"
//(MakeRooms) -> Room ���� -> addRooms ȣ�� -> addRooms ���ο��� CheckIntersection.

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
					cout << "������ �ߺ� üũ�� ���� ���� ����" << endl;
					return false;
				}
			}
		}
		catch (exception e) {
			cout << "���� ����!!" << endl;
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
bool RoomData::CheckIntersection(Room *testRoom) {		//�и� ���� �����Ű����� ����
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
	//1. x1 <= room.x2 == ���� ���� �»�� x��ǥ�� �� �� ���ϴ� x���� ������ �ִ°�
	//2. x2 >= room.x1 == ���� ���� ���ϴ� x��ǥ�� �� �� �»�� x���� ������ �ִ°�
	//3. y1 <= room.y2 == ���� ���� �»�� y��ǥ�� �� �� ���ϴ� y���� ���� �ִ°�
	//4. y2 >= room.y1 == ���� ���� ���ϴ� y��ǥ�� �� �� �»�� y���� �Ʒ��� �ִ°�
	//https://bit.ly/33AybDU	
}
set<Room> RoomData::getlist() {
	return Roomlist;
}
// https://elldeekei.tistory.com/entry/STL-stdset-��-�����-������Ʈ��-����-�ٲ㺸��

void RoomData::Write_RoomNo() {
	set<Room>::iterator iter;

	for (iter = Roomlist.begin(); iter != Roomlist.end(); ++iter) {
		const_cast<Room&>(*iter).Confirm_Room();
	}
	//1. iter�� �����ϰ�
	//2. iter �������� ���빰�� �޾ƿ� �Ŀ�
	//3. �̸� Room ������ Ÿ������ �����ϰ�
	//4. 3�� ������� ��Ʈ����. (���� �� ���� ����)
	//5. �� ����

}