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
	try { //json ������� �̾Ƴ����ϴµ�...
		if (rooms->empty() == true) {
			cout << "�� ���� ������ ���������� �ʽ��ϴ�." << endl;
			throw make_exception_ptr(bad_exception());
		}
		//chrono time -> string
		//std::chrono::system_clock::now();
		//stringstream stm;
		//stm << std::put_time(std::localtime(&tt),"%YY%mm%dd%H%M%S") << ".json";
		
		std::unique_ptr<std::ofstream> outputFile;
		outputFile = std::make_unique<std::ofstream>("result.json");

		if (outputFile->is_open()) {
			*outputFile << "{\n  \"RoomCount\" : \"" << rooms->size() << "\"," << endl;
			*outputFile << "  \"Room\":[" << endl;
			for (auto room : *rooms) {
				auto roomdata = room.getData();
				*outputFile << "    {" << endl;
				*outputFile << "    \"RoomNo\" : \"" << roomdata.roomNo << "\"," << endl;
				*outputFile << "    \"Axis_LX\" : \"" << roomdata.UX << "\"," << endl;
				*outputFile << "    \"Axis_LY\" : \"" << roomdata.UY << "\"," << endl;
				*outputFile << "    \"Axis_RX\" : \"" << roomdata.DX << "\"," << endl;
				*outputFile << "    \"Axis_RY\" : \"" << roomdata.DY << "\"" << endl;
				if (roomdata.roomNo != rooms->size())
					*outputFile << "    },"<<endl;				
				else 
					*outputFile << "    }" << endl;
			}
			*outputFile << "  ]\n}" << endl;

			outputFile->close();
		}
		return true;

		/*
		https://subscription.packtpub.com/book/application_development/9781785286902/1/ch01lvl1sec12/reading-and-writing-json-in-c
		https://ongamedev.tistory.com/entry/jsoncpp-%EC%82%AC%EC%9A%A9%EB%B2%95-%EC%A0%95%EB%A6%AC

		int Axis_LX;				//���� ��� X
		int Axis_LY;				//���� ��� Y
		int Axis_RX;				//���� �ϴ� X
		int Axis_RY;				//���� �ϴ� Y
		int Center_X;				//�߽� X
		int Center_Y;				//�߽� Y

			
		int width;					//���� ����
		int height;					//���� ����

		*/




	}
	catch (exception e) {
		cout << e.what() << endl;
		
		return false;
	}

}