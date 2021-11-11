#include<iostream>
#include<conio.h>
using namespace std;

int ingresarCantidadEquipos() {
	const string INGRESAR_CANTIDAD = "Bienvenido al sistema de Dream Team de la NBA.\nIngrese la cantidad total de equipos en ambas conferencias: ";
	const string ERROR = "Es inaceptable de que haya cantidad 0 o negativa de los equipos.\ningrese de nuevo la cantidad de equipos: ";
	int cantidad, menor = 0;
	cout << INGRESAR_CANTIDAD << endl;
	cin >> cantidad;
	while(cantidad <=menor) {
		cout << ERROR << endl;
		cin >> cantidad;
	}
	return cantidad;
}

string ingresarConferencia() {
	const string INGRESAR_CONFERENCIA = "Ingrese la conferencia que correspponda del equipo ya sea 'ESTE' o 'OESTE': ";
	const string ERROR = "No ingreso ninguna de las dos conferencias.\nIngrese 'ESTE' o 'OESTE' lo que corresponda al equipo: ";
	string conferencia;
	cout << INGRESAR_CONFERENCIA << endl;
	cin >> conferencia;

	while (conferencia !="ESTE" && conferencia !="OESTE") {
		cout << ERROR << endl;
		cin >> conferencia;
	}
	return conferencia;
}

string ingresarCadena(string mensaje) {
	string cadena;
	cout << mensaje << endl;
	cin >> cadena;
	return cadena;
}

int ingresarEnteroMayor15(string mensaje) {
	const string ERROR = "Error al ingresar la edad. Debe ser mayor a 15 años el jugador: ";
	int entero, edadMinima = 15;
	cout << mensaje << endl;
	cin >> entero;

	while(entero < edadMinima) {
		cout << ERROR << endl;
		cin >> entero;
	}
	return entero;
}

int ingresarEnteroconLimites(string mensaje, string error, int min, int max) {
	int entero;
	cout << mensaje << endl;
	cin >> entero; 

	while (entero > max || entero < min) {
		cout << error << endl;
		cin >> entero;
	}
	return entero;
}

float calcularPromedioJugador(int scoring, int firmeza, int rebotes) {
	const float CANTIDAD_ESTADISCTICAS = 3;
	float	suma, promedio;

	suma = scoring + firmeza + rebotes;
	promedio = (float)suma / CANTIDAD_ESTADISCTICAS;

	return promedio;
}


float calcularPromedioEstadistica(int suma) {
	const int CANTIDAD_MISMA_ESTADISTICA = 5;
	float promedio;

	promedio = (float)suma / CANTIDAD_MISMA_ESTADISTICA;
	return promedio;
}

float calcularConferencia(int suma, int cantidadEquipos) {
	float valoracion;
	int estadisticasXJugador = 3 * 5;

	valoracion = (float)suma / (estadisticasXJugador * cantidadEquipos);

	return valoracion;
}

void mostrarInformacionEquipo(string nombreEquipo, string conferencia, string apellido){
	const string DAR_EQUIPO = "Nombre del equipo: ";
	const string DAR_CONFERENCIA = "\nPertenece a la conferencia : ";
	const string DAR_MEJOR_JUGADOR = "\nEl mejor jugador por promedio : ";
	cout << DAR_EQUIPO << nombreEquipo << DAR_CONFERENCIA << conferencia << DAR_MEJOR_JUGADOR << apellido << endl;

}

void mostrarInformacionFinPrograma(string equipoMejorRebotes, string equipoMenorFirmeza, string apellidoAlturaMax, string apellidoMejorScoringEste, string promesaScoring, float valoracionOeste, float valoracionEste) {
	const string MOSTRAR_MEJOR_REBOTES = "El equipo con mejor promedio de rebotes: ";
	const string MOSTRAR_MENOR_FIRMEZA = "El equipo con menor promedio de firmeza: ";
	const string MOSTRAR_MAYOR_ALTURA = "El apellido del jugador más alto: ";
	const string MOSTRAR_MAYOR_SCORING_ESTE = "El apellido del jugador con mas Scoring de la conferencia Este: ";
	const string MOSTRAR_PROMESA_SCORING = "El apellido del jugador más joven con más de 3 de scoring: ";
	const string MOSTRAR_VALORACION_OESTE = "La valoracion de la conferencia Oeste: ";
	const string MOSTRAR_VALORACION_ESTE = "La valoracion de la conferencia Este: ";

	cout << MOSTRAR_MEJOR_REBOTES << equipoMejorRebotes << endl;
	cout << MOSTRAR_MENOR_FIRMEZA << equipoMenorFirmeza << endl; 
	cout << MOSTRAR_MAYOR_ALTURA<< apellidoAlturaMax << endl;
	cout << MOSTRAR_MAYOR_SCORING_ESTE << apellidoMejorScoringEste << endl;
	cout << MOSTRAR_PROMESA_SCORING << promesaScoring << endl;
	cout << MOSTRAR_VALORACION_OESTE << valoracionOeste << endl;
	cout << MOSTRAR_VALORACION_ESTE << valoracionEste << endl;
}

void main() {
	setlocale(LC_ALL, "spanish");
	system("color f9");
	const string INGRESAR_EQUIPO = "Ingrese el nombre del equipo: ";
	const string INGRESAR_APELLIDO = "Ingrese el apellido del jugador: ";
	const string INGRESAR_EDAD = "Ingrese la edad del jugador: ";
	const string INGRESAR_ALTURA = "Ingrese la altura del jugador: ";
	const string INGRESAR_SCORING = "Ingrese el scoring del jugador: ";
	const string INGRESAR_FIRMEZA = "Ingrese la firmeza del jugador: ";
	const string INGRESAR_REBOTES = "Ingrese los rebotes del jugador: ";
	const string ERROR_MENOR5 = "Error al ingresar las estadisticas. Deben ser mayor a 0 y menor o igual a 5: ";
	const string ERROR_ENTRE_120300 = "Error al ingresar altura. Debe ser entre 120 y 300: ";
	int cantEquipos, cantJugadoresxEquipo= 5, edad, altura, scoring, firmeza, rebotes, alturaMin=120, alturaMax=300, estadisticaMin=1, estadisticaMax=5, estadisticaXJugador = 3*5;
	float promedio, mejorPromedio, mejorPromedioRebotes = -1, menorPromedioFirmeza = 6, alturaMaxOeste = 119, mejorScoringEste = -1, edadJovenScoring = 99;
	int sumaRebotes, sumaFirmeza, sumaTodoOeste = 0, sumaTodoEste = 0, equiposOeste = 0, equiposEste= 0;
	float promedioRebotes, apellidoMasAlto, promedioFirmeza, valoracionEste, valoracionOeste;
	string mejorPromedioJugador, equipoMejorRebotes, equipoMenorFirmeza, apellidoPromedio, apellidoAlturaMax, apellidoMejorScoringEste, promesaScoring;
	string apellido, nombreEquipo, conferencia;
	cantEquipos = ingresarCantidadEquipos();



	for(int i = 0; i < cantEquipos; i++) {
		sumaRebotes = 0, sumaFirmeza = 0, mejorPromedio = -1;
		nombreEquipo = ingresarCadena(INGRESAR_EQUIPO);
		conferencia = ingresarConferencia();

		for (int j = 0; j < cantJugadoresxEquipo; j++) {
			apellido = ingresarCadena(INGRESAR_APELLIDO);
			edad = ingresarEnteroMayor15(INGRESAR_EDAD);
			altura = ingresarEnteroconLimites(INGRESAR_ALTURA, ERROR_ENTRE_120300, alturaMin, alturaMax);
			scoring = ingresarEnteroconLimites(INGRESAR_SCORING, ERROR_MENOR5, estadisticaMin, estadisticaMax);
			firmeza = ingresarEnteroconLimites(INGRESAR_FIRMEZA, ERROR_MENOR5, estadisticaMin, estadisticaMax);
			rebotes = ingresarEnteroconLimites(INGRESAR_REBOTES, ERROR_MENOR5, estadisticaMin, estadisticaMax);


			promedio = calcularPromedioJugador(scoring, firmeza, rebotes);
			if (promedio > mejorPromedio) { mejorPromedio = promedio; apellidoPromedio = apellido; }

			sumaRebotes = sumaRebotes + rebotes;
			sumaFirmeza = sumaFirmeza + firmeza;
			if(conferencia == "OESTE") sumaTodoOeste = sumaTodoOeste + firmeza + scoring + rebotes;
			else sumaTodoEste = sumaTodoEste + firmeza + scoring + rebotes;

			if (conferencia == "OESTE" && altura > alturaMaxOeste) { alturaMaxOeste = altura; apellidoAlturaMax = apellido; }
			if (edad < edadJovenScoring && scoring > 3) { edadJovenScoring = edad; promesaScoring = apellido; }
			if (conferencia == "ESTE" && scoring > mejorScoringEste) { mejorScoringEste = scoring; apellidoMejorScoringEste = apellido; }
	
		}
		if (conferencia == "OESTE") { equiposOeste++; }
		else { equiposEste++;  }

		mostrarInformacionEquipo(nombreEquipo, conferencia, apellidoPromedio);
		_getch();
		system("cls");
		promedioRebotes = calcularPromedioEstadistica(sumaRebotes);
		if (promedioRebotes > mejorPromedioRebotes) { mejorPromedioRebotes = promedioRebotes; equipoMejorRebotes = nombreEquipo; }
		promedioFirmeza = calcularPromedioEstadistica(sumaFirmeza);
		if (promedioFirmeza < menorPromedioFirmeza) { menorPromedioFirmeza = promedioFirmeza; equipoMenorFirmeza = nombreEquipo; }
	}
	valoracionOeste = calcularConferencia(sumaTodoOeste, equiposOeste);
	valoracionEste = calcularConferencia(sumaTodoEste, equiposEste);

	mostrarInformacionFinPrograma(equipoMejorRebotes, equipoMenorFirmeza, apellidoAlturaMax, apellidoMejorScoringEste, promesaScoring, valoracionOeste, valoracionEste);

}