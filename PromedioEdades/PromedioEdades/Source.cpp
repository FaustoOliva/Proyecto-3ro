#include<iostream>
#include<conio.h>
using namespace std;

void darLaBienvenida(string mensaje) { 
	cout << mensaje << endl; 
	_getch(); 
}

int ingresarEdad(string mensaje) {
	int edad;
	cout << mensaje << endl;
	cin >> edad;
	return edad;
}

int validarSerMayor() {
	const string ERROR = "Ha ingresado una edad menor a 18, los menores no ingresan.\nPonga otra edad: ";
	const string PEDIR_EDAD = "Ingrese su edad por favor: ";
	int edad;
	edad = ingresarEdad(PEDIR_EDAD);
	while (edad < 18) edad=ingresarEdad(ERROR);
	return edad;
}

string ingresarApellido() {
	const string PEDIR_APELLIDO = "Ingrese su apellido por favor: ";
	string apellido;
	cout << PEDIR_APELLIDO << endl;
	cin >> apellido;
	return apellido;
}

int calcularPromedio(int suma, int cantidad) {
	int promedio;
	promedio = suma / cantidad;
	return promedio;
}
void mostrarPromedio(int promedio) { cout << "El promedio de todas las edades es: " << promedio << endl; }
void mostrarMayores30(int cantidad) { cout << "Las personas mayores a 30 son: " << cantidad << endl; }
void mostrarPersonaMayor(int edad, string apellido) { cout << "La edad de la persona más longeva es: " << edad << ". Y su apellido es: " << apellido << endl; }


bool finDeDatos(string apellido, string terminar) {return apellido != terminar;}
bool mayorA30(int edad) { return edad > 30; }
bool edadEsMayor(int edad, int edadMayor) { return edad > edadMayor; }


void main() {
	setlocale(LC_ALL, "spanish");
	system("color f9");
	const string BIENVENIDOS_SENIORS = "Bienvenido terciarios. Este es un sistema que ayuda a administracion.\nPermite saber el promedio de sus edades y algunos datos mas.\Como ya saben solo se permiten mayores de 18 años, y tienen que ingresar sus apellidos y edades.\n Presione enter para comenzar.";
	const string CUANDO_TERMINAR = "FIN";
	const string NO_INGRESARON_EDAD = "Se decidio cortar la entrada de datos al principio.\nNo hay edades ingresadas.";
	int edad, sumaEdades = 0, cantEdades = 0, promedio = 0, edadMayor = 0, contador30=0;
	string apellido, apellidoMayor;
	
	darLaBienvenida(BIENVENIDOS_SENIORS);

	apellido = ingresarApellido();
	if (finDeDatos(apellido, CUANDO_TERMINAR)) {
		edad = validarSerMayor();
		while (finDeDatos(apellido, CUANDO_TERMINAR)) {
			sumaEdades = sumaEdades + edad;
			cantEdades++;
			if (edadEsMayor(edad, edadMayor)) { edadMayor = edad; apellidoMayor = apellido; }
			if (mayorA30(edad)) contador30++;
			apellido = ingresarApellido();
			if (finDeDatos(apellido, CUANDO_TERMINAR)) edad = validarSerMayor();
		}
		promedio = calcularPromedio(sumaEdades, cantEdades);
		mostrarPromedio(promedio);
		mostrarMayores30(contador30);
		mostrarPersonaMayor(edadMayor, apellidoMayor);
	} else cout << NO_INGRESARON_EDAD << endl;
		
}