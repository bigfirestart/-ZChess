#include <iostream>
#include <string>
#include "Board.h"
#include "Primitives.h"

using namespace std;


int main() {
	Board field;
	while (true) {
	field.show();
	int n1, n2;
	char l1, l2;
	cin >> l1 >> n1 >> l2 >> n2;
	
	field.Move(l1, n1, l2, n2);
	
	
	system("pause");
	field.cls();

}



	system("pause");
	return 0;
}