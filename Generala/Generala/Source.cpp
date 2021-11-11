#include<iostream>
#include<time.h> // Numeros randoms
#include<conio.h> // Para usar el _getch(); (presionar enter) 
#include<windows.h> // Para usar el Sleep(); (pausar en milisegundos)
using namespace std;

void darLaBienvenida() {
	string nombre;
	const string BIENVENIDA = "Hola. Este es un juego que simula cuantas tiradas se necesitan para una generala servida.\nEs decir, cuantas veces se tienen q tirar los dados para que sean todos del mismo valor.\nYa sea 1-1-1-1-1 o 5-5-5-5-5 o 2-2-2-2-2 o etc. Puede desafiar a sus amigos a ver quien lo consigue en menos tiradas. ";

	cout << BIENVENIDA << endl;
	
}

int pedirCaras() {
	int caras;
	const string PEDIR_CARAS_ESCALERA = "Implementamos una nueva tegonologia en que puede elegir cuantas caras tienen los dados.\nLas disminuye si quiere que sea en menos intentos o las aumenta para que sean mas.\nLas caras que puede tener el dado es entre 3 y 10 inclusives.\nTambien implementamos que avise cada vez que salga escalera, es decir, '12345' o '23456' o '34561'.\nSi quiere que simule la escalera, debera ingresar '6'; si no quieres esto ingrese la cantidad que quiera.\nA continuacion ingresse la cantidad de caras: ";
	const string CARAS_ERROR = "Ingrteso mal la cantidad de caras. Recuerde que debe ser mayor o igual a 3 y menor o igual a 10.";

	cout << PEDIR_CARAS_ESCALERA << endl;
	cin >> caras;

	while (caras < 3 || caras >10) {
		cout << CARAS_ERROR << endl;
		cin >> caras;

	}
	return caras;
}

bool afirmarEscalera() {
	const string AVISAR_ESCALERA = "\n Ingrese 'SI' a escalera o 'NO' a escalera: ";
	bool afirmacion = false;
	string respuesta;

	cout << AVISAR_ESCALERA << endl;
	cin >> respuesta;

	if (respuesta == "SI") afirmacion = true;
	return afirmacion;
}

int obtenerDado(int inferior, int superior) {
	int num;
	
	num = inferior + rand() % (superior);
	return num;
}

bool esGenerala(int dado1, int dado2, int dado3, int dado4, int dado5) {
	return dado1 != dado2 || dado2 != dado3 || dado3 != dado4 || dado4 != dado5;
}

bool esDistinto(int dado1, int dado2, int dado3, int dado4, int dado5) {
	return dado1 != dado2 && dado1 != dado3 && dado1 != dado4 && dado1 != dado5 && dado2 != dado3 && dado2 != dado4 && dado2 != dado5 && dado3 != dado4 && dado3 != dado5 && dado4 != dado5;
}

bool esEscalera(int dado1, int dado2, int dado3, int dado4, int dado5) {
	return dado1 + dado2 + dado3 + dado4 + dado5 == 15 || dado1 + dado2 + dado3 + dado4 + dado5 == 19 || dado1 + dado2 + dado3 + dado4 + dado5 == 20;
}

void informarGenerala(int tiradas) {
	const string MENSAJE_TIRADAS = "Se consiguio generala servida en: ";

	cout << MENSAJE_TIRADAS << tiradas << " tiradas" << endl;
}

void main() {
	int dado1, dado2, dado3, dado4, dado5;
	int tiradas= 0;
	const string TIRAR_DADOS = "Apriete enter para tirar los dados...";
	const string NUMEROS_DISTINTOS = "Los 5 dados salieron todos con diferentes numeros. Los numeros son: ";
	const string ESCALERA = "Ha salido escalera. Son los de arriba.";
	srand(time(NULL));
	int inferior = 1, caras = 6;
	system("color f9");
	darLaBienvenida();
	
	caras = pedirCaras();
	cout << TIRAR_DADOS << endl;
	_getch();
	system("cls");
	
	
	do {
		dado1 = obtenerDado(inferior, caras);
		dado2 = obtenerDado(inferior, caras);
		dado3 = obtenerDado(inferior, caras);
		dado4 = obtenerDado(inferior, caras);
		dado5 = obtenerDado(inferior, caras);

		tiradas++;
	

		if (esDistinto(dado1, dado2, dado3, dado4, dado5)) {
			cout << NUMEROS_DISTINTOS << dado1 << dado2 << dado3 << dado4 << dado5 << endl;

			if (caras==6) {

				if (esEscalera(dado1, dado2, dado3, dado4, dado5)) cout << ESCALERA << endl;

			}
		}
		else cout << dado1 << dado2 << dado3 << dado4 << dado5 << endl;
		
	} while (esGenerala(dado1, dado2, dado3, dado4, dado5));


	informarGenerala(tiradas);
	
}