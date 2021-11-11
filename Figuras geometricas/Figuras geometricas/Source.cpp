#include<iostream>;
using namespace std;

char pedirFigura(string mensaje) {
	char figura;
	cout << mensaje << endl;
	cin >> figura;
	return figura;
}

float pedirMedida(string mensaje) {
	float medida;
	cout << mensaje << endl,
	cin >> medida;
	return medida;
}

float perimetroTriangulo(float lados, float base) {
	float perimetro;
	perimetro = lados + base;
	return perimetro;
}

float areaTriangulo(float base, float altura) {
	float area;
	area = altura * base / 2;
	return area;
}

float perimetroCuadrado(float lado) {
	float perimetro;
	perimetro = lado * 4;
	return perimetro;
}

float areaCuadrado(float lado) {
	float area;
	area = lado * lado;
	return area;
}

float perimetroCirculo(float radio, float pi) {
	float perimetro;
	float const diametro = radio + radio;
	perimetro = diametro * pi;
	return perimetro;
}

float areaCirculo(float radio, float pi) {
	float area;
	area =  pi * radio * radio;
	return area;
}

void mostrarPerimetro(string mensaje, float perimetro) {
	cout << mensaje << perimetro << endl;
}

void mostrarArea(string mensaje, float area) {
	cout << mensaje << area << endl;
}

void main() {
	char figuraGeometrica;
	
	// variables 'Q'
	float ladoCuadrado;
	
	// variables 'C'
	float radioCirculo;
	const float PI = 3.14;

	// variables 'T'
	float base;
	float ladosSumados;
	float altura;

	// variables totales
	float perimetro;
	float area;
	
	// mensajes constantes
	const string MENSAJE_LADOQ = "Ingrese la medida del lado del cuadrado";
	const string MENSAJE_RADIO = "Ingrese el radio del circulo";
	const string MENSAJE_ALTURA = "Ingrese la altura del triangulo";
	const string MENSAJE_BASE = "Ingrese la base del triangulo";
	const string MENSAJE_LADOSSUMADOS = "Ingrese los dos lados que faltan del triangulo sumados";
	const string MENSAJE_FIGURA = "Ingrese la figura que que quiera calcular. Si quiere un triangulo 'T'; un cuadrado 'Q'; un circulo 'C'";
	const string MENSAJE_PERIMETRO = "El perimetro de la figura es: ";
	const string MENSAJE_AREA = "El area de la figura es: ";
	
	

	figuraGeometrica = pedirFigura(MENSAJE_FIGURA);

	if (figuraGeometrica == 'T') {
		altura = pedirMedida(MENSAJE_ALTURA);
		base = pedirMedida(MENSAJE_BASE);
		ladosSumados = pedirMedida(MENSAJE_LADOSSUMADOS);
		perimetro = perimetroTriangulo(ladosSumados, base);
		area = areaTriangulo(base, altura);
	}
	else if (figuraGeometrica == 'Q') {
		ladoCuadrado = pedirMedida(MENSAJE_LADOQ);
		perimetro = perimetroCuadrado(ladoCuadrado);
		area = areaCuadrado(ladoCuadrado);

	}
	else if (figuraGeometrica == 'C') {
		radioCirculo = pedirMedida(MENSAJE_RADIO);
		perimetro = perimetroCirculo(radioCirculo, PI);
		area = areaCirculo(radioCirculo, PI);
	}

	mostrarPerimetro(MENSAJE_PERIMETRO, perimetro);
	mostrarArea(MENSAJE_AREA, area);
}
