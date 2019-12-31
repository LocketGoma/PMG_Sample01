#pragma once
#include "Resource.h"
#include "RoomData.h"
#include "json/json.h"

//= Viewer

class InterfaceRoom {
	public:		
		char printedmap[MAX_AXIS+15][MAX_AXIS + 15];

		InterfaceRoom() {
			fill_n(&printedmap[0][0], sizeof(printedmap), ' ');		//시각화를 위한 "화면" 초기화
		}
		void mapprint(set<Room>* rooms);
		bool export_mapdata(set<Room>* rooms);

};

//https://subscription.packtpub.com/book/application_development/9781785286902/1/ch01lvl1sec12/reading-and-writing-json-in-c