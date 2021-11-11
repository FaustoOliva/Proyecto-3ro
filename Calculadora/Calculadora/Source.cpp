#include<iostream>
using namespace std;

void main() {
	float num1;
	float num2;
	float suma;
	float resta;
	float producto;
	float division;

	cout << "Ingrese un numero que le guste:" << endl;
	cin >> num1;

	cout << "Ingrese otro numero que le guste:" << endl;
	cin >> num2;

	suma = num1 + num2;
	resta = num1 - num2;
	producto = num1 * num2;

	cout << "La suma de los dos numeros da:" << suma << endl;
	cout << "La resta de los dos numeros da:" << resta << endl;
	cout << "El producto de los dos numeros da:" << producto << endl;
	
	if (num2 == 0) {

	 cout << "Error, no se puede dividir por 0" << endl;
	}
	else {
     division = num1 / num2;
	 cout << "La division de los dos numeros da: " << division << endl;
	}

	system("pause");

}