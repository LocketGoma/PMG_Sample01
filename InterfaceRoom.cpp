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
			throw make_exception_ptr(bad_exception());
		}
		//Json::Reader reader;		//C4996	'Json::Reader::Reader': Use CharReader and CharReaderBuilder instead	
		Json::CharReaderBuilder reader;		//CharReader = 순수 가상함수 호출 경고 = 인터페이스 or 추상 클래스
		//Json::Value root;
		string outJson = "{";
		set<Room>::iterator iter;
		Room rm;
		Data temp;

		for (iter = rooms->begin(); iter == rooms->end(); ++iter) {
			rm = *iter;
			temp = rm.getData();
			
			outJson += "Axis_LX" + temp.UX;
			//대충 이런식?


		}



		/*
		https://subscription.packtpub.com/book/application_development/9781785286902/1/ch01lvl1sec12/reading-and-writing-json-in-c

		int Axis_LX;				//좌측 상단 X
		int Axis_LY;				//좌측 상단 Y
		int Axis_RX;				//우측 하단 X
		int Axis_RY;				//우측 하단 Y
		int Center_X;				//중심 X
		int Center_Y;				//중심 Y

			
		int width;					//가로 길이
		int height;					//세로 길이

		*/




	}
	catch (exception e) {
		cout << e.what() << endl;
		
		return false;
	}

}