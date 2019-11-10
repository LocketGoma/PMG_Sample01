#pragma once



class Room {						//생성된 방의 정보를 가지고 있는 클래스
	public :
		Room();

		
		//void RoomBreak();			//방 파괴, 내부에서 파괴자 호출함.

		bool is_interaction;		//겹치는지 여부 검사

		void Maker();
		void Maker(int, int);				//기준 좌표값만 받아오는 경우 (중앙점)
		void Maker(int, int, int, int);	//4개 좌표값을 다 받아오는 경우

		void data_printer();
		void map_printor();


	private :
		//~Room();
		static int room_no;

		bool Generator();
		bool Generator(pair<int, int>);

		bool Valid_Generate(pair<int, int>, pair<int, int>);
		bool Valid_Length();		//가로, 세로 길이가 정상적인지 검사
		bool Valid_Axis(pair<int, int>);			//축 위치가 정상적인지 검사
		
		void Axis_changer();		//축 위치 뒤집힌 경우 둘을 교체

		int Axis_LX;				//좌측 상단 X
		int Axis_LY;				//좌측 상단 Y
		int Axis_RX;				//우측 하단 X
		int Axis_RY;				//우측 하단 Y
		int Center_X;				//중심 X
		int Center_Y;				//중심 Y

			
		int width;					//가로 길이
		int height;					//세로 길이

};
