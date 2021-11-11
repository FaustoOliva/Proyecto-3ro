#include<iostream>
using namespace std;

int pedirLado(string mensaje) {
	int medida;
	cout << mensaje << endl;
	cin >> medida;
	return medida;

}

bool validezFigura(int lado1, int lado2, int lado3) {
	bool validez;
	if ((lado1 + lado2 < lado3) || (lado2 + lado3 < lado1) || (lado2> lado1 + lado3)) {
		validez = false;
	}
	else{
		validez = true;
	}
	return validez;
}

string definirTipoPercha(int lado1, int lado2, int lado3) {
	string tipo;

	if((lado1 == lado2) && (lado2 == lado3)) {
		tipo = "Equilatero";
	}
	else if ((lado1 == lado2) || (lado2 == lado3) || (lado1 == lado3)) {
		tipo = "Isosceles";
	}
	else {
		tipo = "Escaleno";
	}
	return tipo;
}

void mostrarTipo(string mensaje, string tipoPercha) {
	cout << mensaje << tipoPercha << endl;
}

void main() {
	int lado1;
	int lado2;
	int lado3;
	bool valido;
	string tipoPercha;
	
	const string mensajePedir = "Ingrese un lado de la percha. Si ya ingreso uno, ingrese los demas";
	const string mensajeMostrarTipo = "El tipo de percha es: ";
	
	
	lado1 = pedirLado(mensajePedir);
	lado2 = pedirLado(mensajePedir);
	lado3 = pedirLado(mensajePedir);
	valido = validezFigura(lado1,lado2, lado3);
	
	if (valido) {
		tipoPercha = definirTipoPercha(lado1, lado2, lado3);
		mostrarTipo(mensajeMostrarTipo, tipoPercha);
 
	}
	else{
		
		 cout << "Los lados ingresados no son validos para una percha.";
	}

}