#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

string ingresarNombre(string mensaje) {
	string nombre;
	cout << mensaje << endl;
	cin >> nombre;
	return nombre;
}

bool decidirModo(string mensaje, string nombre) {
	const string error = "Ingrese 'SI' si quiere jugar al modo de juego, o 'NO' si no lo quiere jugar";
	bool modo = false;
	string decidir;
	cout << nombre << mensaje << endl,
	cin >> decidir;

	while (decidir != "SI" && decidir != "NO") {
		cout << error << endl,
		cin >> decidir;
		
		if (decidir == "SI") modo = true;
		else if (decidir == "NO") modo = false;
	
	}
	

	return modo;
}

int pedirNumero(string mensaje) {
	int num;
	cout << mensaje << endl;
	cin >> num;
	return num;
}


//1VS1


int ingresarNumero(string mensaje, string nombre) {
	int num;
	cout << mensaje << nombre << endl;
	cin >> num;
	system("cls");
	return num;
}

int calcularIntentos(int numAdvinar, int num, string menor, string mayor) {
	int intentos = 1;

	while (numAdvinar != num) {
		if (numAdvinar < num) num = pedirNumero(menor);
		else if (numAdvinar > num) num = pedirNumero(mayor);

		intentos++;
	}
	cout << "Lo lograste en: " << intentos << " intento/s" << endl;
	return intentos;
}

void quienGano(int intentos, int intentos2, string empataron, string nombre, string amigo) {
	string ganador;

	if (intentos < intentos2) {
		cout << "Ganó " << nombre << ". Felicidades lo hiciste en  " << intentos << "intentos. En vez de los intentos de su amigo " << intentos2 << endl;
	}
	else if (intentos > intentos2) {
		cout << "Ganó" << amigo << ". Felicidades lo hiciste en  " << intentos2 << "intentos. En vez de los intentos de su amigo " << intentos << endl;
	}
	else if (intentos == intentos2) cout << empataron << intentos << endl;



}


//Solitario


string elegirDificultad(string mensaje) {
	const string ERROR = "Ingreso mal la dificultad. Ingrese PRINCIPIANTE, AVANZADO O MAESTRO. La dificultad que prefiera.";
	string dificultad;
	cout << mensaje << endl;
	cin >> dificultad;

	while (dificultad != "PRINCIPIANTE" && dificultad != "AVANZADO" && dificultad != "MAESTRO") {
		cout << ERROR << endl;
		cin >> dificultad;
	}

	return dificultad;
}

int asignarVidas(string dificultad, int vidas) {

	if (dificultad == "PRINCIPIANTE") vidas = 15;
	else if (dificultad == "AVANZADO") vidas = 12;
	else if (dificultad == "MAESTRO") vidas = 8;

	return vidas;
}

int elegirNumero(int num, int inferior, int superior) {
	srand(time(NULL));

	num = inferior + rand() % (superior - inferior);

	return num;
}

int validarNumeros(int aleatorio, int usuario, int vidas, string MENSAJE_MENOR, string MENSAJE_MAYOR) {
	int intentos = 1; 

	while (usuario != aleatorio && intentos < vidas) {
		cout << "Te queda/n " << vidas - intentos << " intento/s" << endl;
		if (aleatorio < usuario) usuario = pedirNumero(MENSAJE_MENOR);
		else if (aleatorio > usuario) usuario = pedirNumero(MENSAJE_MAYOR);
		intentos++;
	}
	return intentos;
}

bool resultadoJuego(int intentos, int vidas) {
	bool ganar = false;

	if (intentos < vidas) ganar = true;
    else ganar = false;
	return ganar;
}

void darResultado(bool ganar, string msjGano, string msjPerdio, string nombre, int intentos) {
	const string MENSAJE_GRACIAS = "Gracias por jugar ";

	if (ganar) cout << msjGano << intentos << " intento/s." << endl;
	else cout << msjPerdio << endl;

	cout << MENSAJE_GRACIAS << nombre << endl;
}


void main() {
	const string INTRODUCCION = "Bienvenido al juego Guess The Number, donde tendras que adivinar un numero random entre 1 y 1000.\nTendras x intentos segun la dificultad que elijas.";
	const string INGRESAR_NOMBRE = "Ingrese su nombre por favor: ";
	const string INGRESAR_MODO = " tenemos otro modo de juego que te podemos ofrecer, que es el 1vs1.\nEn el 1vs1 jugas contra tu amigo en donde cada uno tiene que adivinar el numero del otro.\nGana el que adivina en menos intentos. Quiere jugarlo con un amigo? 'SI' 'NO'  ";
	const string MENSAJE_MENOR = "Es MENOR al que ingresaste";
	const string MENSAJE_MAYOR = "Es MAYOR al que ingresaste";
	string nombre;
	bool modo;
	int numUsuario = 0;
	int intentos = 0;

	
	cout << INTRODUCCION << endl;
	nombre = ingresarNombre(INGRESAR_NOMBRE);
	modo = decidirModo(INGRESAR_MODO, nombre);
	system("cls");
	if (modo) {
		const string INGRESAR_AMIGO = "Ingrese el nombre de su amigo por favor: ";
		const string INGRESAR_NUMERO = "Ingrese un numero para que lo adivine su amigo ";
		const string MENSAJE_NUMERO = "Ingrese un numero entre 1 y 1000 para adivinar el numero de su amigo";
		const string MENSAJE_EMPATADOS = "Empataron en igualdad de intentos, van a tener que seguir siendo amigos. Ambos intentos en: ";
		string nombreAmigo;
		int numAdivinar;
		int intentosAmigo;

		system("color 4F");

		nombreAmigo = ingresarNombre(INGRESAR_AMIGO);
		numAdivinar = ingresarNumero(INGRESAR_NUMERO, nombreAmigo);
		numUsuario = pedirNumero(MENSAJE_NUMERO);
		intentos = calcularIntentos(numAdivinar, numUsuario, MENSAJE_MENOR, MENSAJE_MAYOR);
		//Segundo numero	
		numAdivinar = ingresarNumero(INGRESAR_NUMERO, nombre);
		numUsuario = pedirNumero(MENSAJE_NUMERO);
		intentosAmigo = calcularIntentos(numAdivinar, numUsuario, MENSAJE_MENOR, MENSAJE_MAYOR);
		quienGano(intentos, intentosAmigo, MENSAJE_EMPATADOS, nombre, nombreAmigo);

	}
	else if (!modo) {
		const string MENSAJE_DIFICULTAD = "Elija la dificultad a la que quiere jugar, elija entre 'PRINCIPIANTE' o 'AVANZADO' o 'MAESTRO'";
		const string MENSAJE_NUMERO = "Ingrese un numero entre 1 y 1000 para adivinar el numero aleatorio: ";
		const string MENSAJE_GANO = "Felicitaciones has ganado el juego en: ";
		const string MENSAJE_PERDIO = "No lograste adivinar el numero en la cantidad de intentos. !Suerte en la proxima!";
		const int LIMITE_INFERIOR = 1;
		const int LIMITE_SUPERIOR = 1001;
		string dificultad;
		bool ganar = false;
		int vidas = 0;
		int numAleatorio = 0;
		
		system("color f1");
		
		dificultad = elegirDificultad(MENSAJE_DIFICULTAD);
		vidas = asignarVidas(dificultad, vidas);
		numAleatorio = elegirNumero(numAleatorio, LIMITE_INFERIOR, LIMITE_SUPERIOR);
		numUsuario = pedirNumero(MENSAJE_NUMERO);

		intentos = validarNumeros(numAleatorio, numUsuario, vidas, MENSAJE_MENOR, MENSAJE_MAYOR);
		ganar = resultadoJuego(intentos, vidas);
		system("cls");
		darResultado(ganar, MENSAJE_GANO, MENSAJE_PERDIO, nombre, intentos);
	}	
}