#pragma once



class Room {						//������ ���� ������ ������ �ִ� Ŭ����
	public :
		Room();
		Room(int, int);				//���� ��ǥ���� �޾ƿ��� ��� (�߾���)
		Room(int, int, int, int);	//4�� ��ǥ���� �� �޾ƿ��� ���
		
		void RoomBreak();			//�� �ı�, ���ο��� �ı��� ȣ����.

		bool is_interaction;		//��ġ���� ���� �˻�

		void data_printer();
		void map_printor();


	private :
		~Room();
		static int room_no;

		bool Generator();
		bool Generator(pair<int, int>);

		bool Valid_Generate(pair<int, int>, pair<int, int>);
		bool Valid_Length();		//����, ���� ���̰� ���������� �˻�
		bool Valid_Axis(pair<int, int>);			//�� ��ġ�� ���������� �˻�
		
		void Axis_changer();		//�� ��ġ ������ ��� ���� ��ü

		int Axis_LX;				//���� ��� X
		int Axis_LY;				//���� ��� Y
		int Axis_RX;				//���� �ϴ� X
		int Axis_RY;				//���� �ϴ� Y
		int Center_X;				//�߽� X
		int Center_Y;				//�߽� Y

			
		int width;					//���� ����
		int height;					//���� ����

};
