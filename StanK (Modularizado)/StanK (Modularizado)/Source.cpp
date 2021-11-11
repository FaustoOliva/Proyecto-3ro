#include<iostream>
using namespace std;

float pedirPrecioUnidad(string mensaje1) {
	float precioUnitario;
	cout << mensaje1 << endl;
	cin >> precioUnitario;
	return precioUnitario;

}

int pedirCantidad(string mensaje2) {
	float cantidad;
	cout << mensaje2 << endl;
	cin >> cantidad;
	return cantidad;

}

char pedirFormaPago(string mensaje3) {
	char formaPago;
	cout << mensaje3 << endl;
	cin >> formaPago;
	return formaPago;

}

float PRECIO_TOTAL(int cant, float precioUnidad) {
	float total;
	total = precioUnidad * cant;

	return total;
}


float calcularPrecio(int cant,char formaPago, float pagototal, int precioUnidad) {
	const float efectivo1 = 0.9;
	const float efectivo2 = 0.95;
	const float tarjeta = 0.85;

	if (cant > 5 && formaPago == 'E') {

		pagototal = pagototal * efectivo1;
	}

	else if (cant <= 5 && formaPago == 'E') {

		pagototal = pagototal * efectivo2;
	}

	else if (precioUnidad >= 1000 && formaPago == 'T') {

		pagototal = pagototal * tarjeta;
	}

	return pagototal;
}

void mostrarPrecio(string mensaje, float pagoTotal) {
	
	cout << mensaje << pagoTotal << endl;

}


void main() {
	float precioUnitario;
	float cantidad;
	char formaPago;
	float pagoTotal;
	const string mensaje1 = "Ingrese el precio unitario del producto: ";
	const string mensaje2 = "Ingrese la cantidad del producto que desee: ";
	const string mensaje3 = "Ingrese el modo de pago. Si es efectivo con 'E' y si es tarjeta 'T': ";
	const string mensajePrecio = "El precio total a pagar es : $";
	
	precioUnitario = pedirPrecioUnidad(mensaje1);
	cantidad = pedirCantidad(mensaje2);
	formaPago = pedirFormaPago(mensaje3);

	pagoTotal = PRECIO_TOTAL(cantidad, precioUnitario);
	pagoTotal = calcularPrecio(cantidad, formaPago, pagoTotal, precioUnitario);
	
	mostrarPrecio(mensajePrecio, pagoTotal);

}