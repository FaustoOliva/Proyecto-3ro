#include<iostream>
#include <time.h>
#include<conio.h>
using namespace std;

void bienvenida() { cout << "Bienvenidos al Bingo de la escuela Ort.\nEste bingo se centra en un 1vs1, entre vos y otra persona. Se juega con un tablero de 15 numeros, que son generados al azar. Con los tableros listos, se generaran numeros aleatoriamente; gana el que lo completa.\nBuena suerte, que se diviertan. " << endl; }

string ingresarCadena(string mensaje) {
	string cadena;
	cout << mensaje << endl;
	cin >> cadena;
	return cadena;
}

int generarNumRandom(int inferior, int superior) {
	int num;
	num = inferior + rand() % (superior);
	return num;
}

bool busquedaDelNumValido(int tope, int carton[], int inferior, int superior, int num) {
	bool validado = true;
	int i = 0;

	while(validado && i < tope){
		if(num == carton[i]){ validado = false; }
		else { i++; }
	}
	return validado;
}

void llenarCartones(int vectCarton[], int inferior, int numerosBolillero, int topeCarton) {
	int num;
	bool valido = true;
	for (int i = 0; i < topeCarton; i++) {
		do {
			num = generarNumRandom(inferior, numerosBolillero);
			valido = busquedaDelNumValido(i + 1, vectCarton, inferior, numerosBolillero, num);
		} while (!valido);
		vectCarton[i] = num;
	}
}

void mostrarCarton(string mensaje, string nombre, int carton[], int tope, int num){
    cout << mensaje << nombre << " es: " << endl;
	
	for (int i = 0; i < tope; i++) {
		if (i == tope - 1 && carton[i] == 0) { system("color f9"); cout << "XX" << ".\n" << endl; }
		else if (i == tope - 1) { system("color f9"); cout << carton[i] << ".\n" << endl; }
		else if (carton[i] == 0) { system("color f9"); cout << "XX" << ", "; }
		else { system("color f9"); cout << carton[i] << ", "; }
	}
}

int validarCarton(int carton[], int bolillero[], int tope, int bolilla, int contador) {
	for(int i = 0; i < tope; i++) {
		if(carton[i] == bolillero[bolilla - 1]) {
			contador++;
		}
	}
	return contador;
}

int validarCartonPosicion(int carton[], int bolillero[], int tope, int bolilla) {
	int i = 0;
	bool valido = true;
	while (i <= tope && valido){
		if(carton[i] == bolillero[bolilla - 1]) {
			valido = false;
		}else { i++; }
	}
	return i;
}

int igualdadNumeros(int vectCarton[], int vectBolillero[], int NUMEROS_CARTON, int contadorBolilla, string nombre, int num, int contador, int contadorAux) {
	int  posicionACambiar;
	const string NUMERO_COINCIDE = "El numero que se encontró en el carton de ";

	contador = validarCarton(vectCarton, vectBolillero, NUMEROS_CARTON, contadorBolilla, contador);
	posicionACambiar = validarCartonPosicion(vectCarton, vectBolillero, NUMEROS_CARTON, contadorBolilla);
	if (contador > contadorAux) {
		vectCarton[posicionACambiar] = 0;
		mostrarCarton(NUMERO_COINCIDE, nombre, vectCarton, NUMEROS_CARTON, num);
		contadorAux++;
	}
	return contador;
}

void main() {
	setlocale(LC_ALL, "spanish");
	srand(time(NULL));
	system("color f9");
	const string MENSAJE_AMIGO1 = "Ingrese tu nombre por favor: ";
	const string MENSAJE_AMIGO2 = "Ingrese el nombre del segundo jugador: ";
	const string MOSTRAR_CARTON = "El carton del jugador ";
	

	const int NUMEROS_CARTON = 3;
	const int NUMEROS_BOLILLO = 8;
	int inferior = 1, num, contadorBolilla = 0, contador1 = 0, contador2 = 0, contadorAux1 = 0, contadorAux2 = 0;
	bool valido = true;
	string nombre1, nombre2;

	int vectCarton1[NUMEROS_CARTON]{};
	int vectCarton2[NUMEROS_CARTON]{};
	int vectBolillero[NUMEROS_BOLILLO]{};

	bienvenida();

	nombre1 = ingresarCadena(MENSAJE_AMIGO1);
	nombre2 = ingresarCadena(MENSAJE_AMIGO2);

	llenarCartones(vectCarton1, inferior, NUMEROS_BOLILLO, NUMEROS_CARTON);
	llenarCartones(vectCarton2, inferior, NUMEROS_BOLILLO, NUMEROS_CARTON);
	
	num = 0;
	mostrarCarton(MOSTRAR_CARTON, nombre1, vectCarton1, NUMEROS_CARTON, num);
	mostrarCarton(MOSTRAR_CARTON, nombre2, vectCarton2, NUMEROS_CARTON, num);
	
	while(contador1 != NUMEROS_CARTON && contador2 != NUMEROS_CARTON) {
		cout << "Presiona enter para tirar del bolillero: " << endl;
		_getch();
		system("cls");
		do {
			num = generarNumRandom(inferior, NUMEROS_BOLILLO);
			valido = busquedaDelNumValido(contadorBolilla+1, vectBolillero, inferior, NUMEROS_BOLILLO, num);
		} while (!valido);
		vectBolillero[contadorBolilla] = num;
		contadorBolilla++;

		cout << "En el bolillero salio el numero: " << vectBolillero[contadorBolilla-1] << endl;

		contador1 = igualdadNumeros(vectCarton1, vectBolillero, NUMEROS_CARTON, contadorBolilla, nombre1, num, contador1, contadorAux1);
		contador2 = igualdadNumeros(vectCarton2, vectBolillero, NUMEROS_CARTON, contadorBolilla, nombre2, num, contador2, contadorAux2);
		
	}
	if (contador1 > contador2) { cout << "El ganador es: " << nombre1 << endl; }
	else if (contador2 > contador1) { cout << "El ganador es: " << nombre2 << endl; }
	else { cout << "Ambos cartones se completaron al mismo tiempo. Empataron. "; }
}