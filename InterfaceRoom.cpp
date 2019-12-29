#include "InterfaceRoom.h"



void InterfaceRoom::mapprint(set<Room>* rooms) {
	set<Room>::iterator iter;
	Room rm;
	Data temp;
	int ar = 1;
	for (iter = rooms->begin(); iter != rooms->end(); ++iter) {
		rm = *iter;
		temp = rm.getData();
		

		for (int i = temp.UY; i < temp.DY; i++) {
			for (int j = temp.UX; j < temp.DX; j++) {
				//if (i == temp.CY && j == temp.CX) {
				//	printedmap[i][j] = ar + 48;					
				//}
				//else
					printedmap[i][j] = '*';
			}
		}
		//ar++;
	}
	for (int j = 0; j < MAX_AXIS + 1; j++) {
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < MAX_AXIS + 15; i++) {
		for (int j = 0; j < MAX_AXIS + 15; j++) {
			cout << printedmap[i][j];
		}
		cout << endl;
	}

	for (int j = 0; j < MAX_AXIS + 1; j++) {
		cout << "-";
	}
	cout << endl;

}

bool InterfaceRoom::export_mapdata(set<Room>* rooms) {
	try { //json 양식으로 뽑아내야하는데...
		if (rooms->empty() == true) {
			cout << "파일이 정상적이지 않습니다." << endl;
			make_exception_ptr(bad_exception());
		}




	}
	catch (exception e) {
		cout << e.what() << endl;
		
		return false;
	}

}