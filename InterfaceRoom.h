#pragma once
#include "Resource.h"
#include "RoomData.h"
//= Viewer

class InterfaceRoom {
	public:		
		char printedmap[MAX_AXIS+15][MAX_AXIS + 15];

		InterfaceRoom() {
			fill_n(&printedmap[0][0], sizeof(printedmap), ' ');
		}
		void mapprint(set<Room>* rooms);
		bool export_mapdata();

};