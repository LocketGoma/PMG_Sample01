#pragma once

#include "Resource.h"
#include "Room.h"

void Set_Random_Generator() {
	srand((unsigned int)time(NULL));
}

int main() {
	Set_Random_Generator();

	Room *rm1 = new Room();
	rm1->data_printer();
	rm1->data_printer();


	system("pause");
	return 0;
}


