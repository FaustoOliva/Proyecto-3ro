#include<iostream>
using namespace std;

float pedirRadio(string mensaje) {
	float radio;
	cout << mensaje << endl;
	cin >> radio;
	return radio;
}

string pedirTipoAlfajor(string mensaje) {
	string tipo;
	cout << mensaje << endl;
	cin >> tipo;
	return tipo;
}

bool validarRango(float radio, int maxima, int minima) {
	bool validez;
	if (radio >= minima && radio <= maxima) {
		validez = true;
	}
	else {
		validez = false;
	}
	return validez;
}

float calcularPrecio(float diametro, string tipo, int multi, int valorFijoS, int valorFijoD, int valorFijoT) {
	float precioVenta = 0;
	if (tipo == "SIMPLE") {
		precioVenta = valorFijoS + (diametro * multi);
	}
	else if (tipo == "DOBLE") {
		precioVenta = valorFijoD + (diametro * multi);
	}
	else if (tipo == "TRIPLE") {
		precioVenta = valorFijoT + (diametro * multi);
	}
	return precioVenta;
}

void mostrarError(string mensaje) {
	cout << mensaje << endl;
}

void mostrarPrecio(string mensaje, float precio) {
	cout << mensaje << precio << endl;
}

void main() {
	const int MINIMO_RANGO = 3;
	const int MAXIMO_RANGO = 5;
	const int VALOR_FIJO_S = 10;
	const int VALOR_FIJO_D = 15;
	const int VALOR_FIJO_T = 20;
	const int MULTIPLICACION = 5;
	const string MENSAJE_PEDIR_RADIO = "Ingrese el radio del alfajor: ";
	const string MENSAJE_TIPO = "Ingrese el tipo de alfajor(SIMPLE, DOBLE O TRIPLE): ";
	const string MENSAJE_DESECHADO = "La medida del radio no es aceptada. ALFAJOR DESECHADO.";
	const string MENSAJE_TIPO_ERROR = "ERROR DE TIPO DE ALFAJOR.";
	const string MENSAJE_PRECIO = "El precio del alfajor es: $";
	float radio;
	float diametro;
	string tipoAlfajor;
	bool estaEnRango;
	float precioVenta;

	radio = pedirRadio(MENSAJE_PEDIR_RADIO);
	estaEnRango = validarRango(radio, MAXIMO_RANGO, MINIMO_RANGO);

	if (estaEnRango) {
		diametro = radio * 2;
		tipoAlfajor = pedirTipoAlfajor(MENSAJE_TIPO);

		if (tipoAlfajor == "SIMPLE" || tipoAlfajor == "DOBLE" || tipoAlfajor == "TRIPLE") {
			precioVenta = calcularPrecio(diametro, tipoAlfajor, MULTIPLICACION, VALOR_FIJO_S, VALOR_FIJO_D, VALOR_FIJO_T);
			mostrarPrecio(MENSAJE_PRECIO, precioVenta);
		}
		else mostrarError(MENSAJE_TIPO_ERROR);
	}
	 else mostrarError(MENSAJE_DESECHADO);
     

}