#include <iostream>
#include <string>
#include "Board.h"
#include "Primitives.h"

using namespace std;


int main() {
	Board field;
	/*while (true) {
	field.show();
	int n1, n2;
	char l1, l2;
	cin >> l1 >> n1 >> l2 >> n2;
	
	field.Move(l1, n1, l2, n2);
	field.cls();

}*/
	field.show();
	field.getPossibleMoves( 'A', 2);
	cout << endl;

	/*for (int i = 0; i < 10; i++) {
		cout << field.matrix[6][1].vectors[i].x << " " << field.matrix[6][1].vectors[i].y << endl;
	}*/
	cout << 2 * 0;



	system("pause");
	return 0;
}