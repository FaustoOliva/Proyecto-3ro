#include<iostream>
#include<time.h>
using namespace std;

int obtengoRandom(int inferior, int superior) {
	int num;

	num = inferior + rand() % (superior + 1 - inferior);
	return num;
}


void main() {
	int vect[10], num, i, limitI, limitS;
	srand(time(NULL));

	cout << "Ingrese el limite inferior" << endl;
	cin >> limitI;

	cout << "Ingrese el limite superior" << endl;
	cin >> limitS;

	for (i = 0; i < 10; i++) {

		num = obtengoRandom(limitI, limitS);
		vect[i] = num;

	}
	system("pause");
}