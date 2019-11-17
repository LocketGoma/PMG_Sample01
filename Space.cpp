#include "Space.h"
//¾È¾¸


Space::~Space() {
	parent.reset();
	left.reset();
	right.reset();
}

Space::Space(Space* parent) {
	this->parent = make_shared<Space>(parent);

	roomData = new Room();
}

Data Space::getData() {
	return SpaceData;
}
bool Space::setData(Data inputData) {
	try {
		this->SpaceData = inputData;
	}
	catch (exception e)
	{
		return false;
	}
	return true;
}

bool Space::setRoomData() {
	try {
		roomData->Maker(SpaceData.UX, SpaceData.UY, SpaceData.DX, SpaceData.DY);
	}
	catch (exception e) {
		roomData->Maker();
		return false;
	}
	return true;
}