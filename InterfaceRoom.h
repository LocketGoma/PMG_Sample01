#pragma once
#include "Resource.h"
#include "RoomData.h"
//= Viewer

class InterfaceRoom {
	public:
		void mapprint(set<Room> * rooms);
		char printedmap[MAX_AXIS+15][MAX_AXIS + 15];

		InterfaceRoom() {
			fill_n(&printedmap[0][0], sizeof(printedmap), ' ');
		}

};