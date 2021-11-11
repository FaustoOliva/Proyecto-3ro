#include<iostream>
using namespace std;

void main() {

	float precioUnitario;
	int cantidad;
	char formaPago;
	float pagoTotal;
	const float efectivo1 = 0.9;
	const float efectivo2 = 0.95;
	const float tarjeta = 0.85;
	
	cout << "Ingrese el precio del producto: " << endl;
	cin >> precioUnitario;

	cout << "Ingrese la cantidad del producto que desee: " << endl;
	cin >> cantidad;

	cout << "Ingrese el modo de pago. Si es efectivo con 'E' y si es tarjeta 'T': " << endl;
	cin >> formaPago;
	

	pagoTotal = precioUnitario * cantidad;
	

	if (cantidad > 5 && formaPago == 'E') {

	 pagoTotal= pagoTotal * efectivo1;
}
	
	else if (cantidad <= 5 && formaPago == 'E') {

		pagoTotal = pagoTotal * efectivo2;
	}
	
	else if (precioUnitario >= 1000 && formaPago == 'T') {

		pagoTotal = pagoTotal * tarjeta;
	}

	
	
	
	cout << "El precio total a pagar es : $" << pagoTotal << endl;


}