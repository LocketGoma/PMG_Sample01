#pragma once



class Room {						//������ ���� ������ ������ �ִ� Ŭ����
	public :
		Room();
		//void RoomBreak();			//�� �ı�, ���ο��� �ı��� ȣ����.

		bool is_interaction;		//��ġ���� ���� �˻�

		void Maker();
		void Maker(int, int);				//���� ��ǥ���� �޾ƿ��� ��� (�߾���)
		void Maker(int, int, int, int);		//4�� ��ǥ���� �� �޾ƿ��� ���

		void data_printer();

		Data getData();

		friend bool operator == (const Room& rm1, const Room& rm2) {
			Data tp1 = const_cast<Room &>(rm1).getData();
			Data tp2 = const_cast<Room &>(rm2).getData();
			return (tp1.CX == tp2.CX && tp1.CY == tp2.CY && tp1.height == tp2.height && tp1.width == tp2.width);
		}
		friend bool operator < (const Room& rm1, const Room& rm2) {
			Data tp1 = const_cast<Room&>(rm1).getData();
			Data tp2 = const_cast<Room&>(rm2).getData();
			return (tp1.CX < tp2.CX && tp1.CY < tp2.CY);
		}
		//~Room();

	private :
		
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
