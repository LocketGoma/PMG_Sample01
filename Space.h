#pragma once
#include "Resource.h"
#include "Room.h"
//Tree's node

//Space 에 필요한 정보
//1. 부분공간 크기
//2. leaf 여부 (leaf만 실제로 이용할것)
//3. 내부에 생성된 Room 정보
//4. leaf가 아니라 중간 노드일 경우 : 각 노드를 연결해주는 '길' 정보 갖고있을것

//잠깐... 이거 필요한가? <- '범위' 지정을 위해서면 필요하긴 한데 필수는 아닌듯.




class Space {
	public :
		Space();
		Space(Space* parent);
		~Space();
		Data getData();			//Data 정보 리턴		
		bool setData(Data);		//Data set (지정)

		Room getRoomData();
		bool setRoomData();
		bool setRoomData(Room room);

		shared_ptr<Space> parent;
		shared_ptr<Space> left;
		shared_ptr<Space> right;


	private:
		Data SpaceData;
		Room *roomData;		//방 정보 갖고있음.
		//Road roadData;		//길 정보 갖고 있음.

};

