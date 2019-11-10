#pragma once
#include "Resource.h"
#include "Room.h"
//Tree's node

//Space �� �ʿ��� ����
//1. �κа��� ũ��
//2. leaf ���� (leaf�� ������ �̿��Ұ�)
//3. ���ο� ������ Room ����
//4. leaf�� �ƴ϶� �߰� ����� ��� : �� ��带 �������ִ� '��' ���� ����������

//���... �̰� �ʿ��Ѱ�? <- '����' ������ ���ؼ��� �ʿ��ϱ� �ѵ� �ʼ��� �ƴѵ�.




class Space {
	public :
		Space();
		Space(Space* parent);
		~Space();
		Data getData();			//Data ���� ����		
		bool setData(Data);		//Data set (����)

		Room getRoomData();
		bool setRoomData();
		bool setRoomData(Room room);

		shared_ptr<Space> parent;
		shared_ptr<Space> left;
		shared_ptr<Space> right;


	private:
		Data SpaceData;
		Room *roomData;		//�� ���� ��������.
		//Road roadData;		//�� ���� ���� ����.

};

