#include <iostream>
#include <string>
#include "King.h"
#include "Board.h"

using namespace std;


int main() {

	Board board;

	int n1, n2;
	char l1, l2;

	while (true) {
		board.Show();
		cin >> l1 >> n1 >> l2 >> n2;
		board.Move(l1 , n1 , l2 , n2);
		system("cls");

	}




	system("pause");
	return 0;
}