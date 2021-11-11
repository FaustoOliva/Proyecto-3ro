#include<iostream>
#include<string>
using namespace std;

void darLaBienvenida(string mensaje) { cout << mensaje << endl; }

int ingresarLugar(string mensaje) {
	int lugar;
	cout << mensaje << endl;
	cin >> lugar;
	return lugar;
}

int validarEntero(string mensaje,int maximoLugares, int fin) {
	const string ERROR = "ERROR. Ingreso mal el numero, tiene que ser menor a 20 y mayor a 0.\nIngreselo de nuevo: ";
	int lugarValido;

	lugarValido = ingresarLugar(mensaje);

	while (lugarValido > maximoLugares || lugarValido < fin) { lugarValido = ingresarLugar(ERROR); }
	return lugarValido;
}

void mostrarResultados(string msjOcupados, float porcGeneral, float porcVIP) {
	cout << "Los asientos ocupados son " << msjOcupados << endl;
	cout << "El porcentaje de los asientos generales ocupados es " << porcGeneral << "% de los asientos totales" << endl;
	cout << "El porcentaje de los asientos vip ocupados es " << porcVIP << "% de los asientos totales" << endl;

}

void main() {
	const string MENSAJE_BIENVENIDA = "Bienvenidos a Autocines Minski.\nA raiz de la pandemia decidimos empezar este emprendimiento para que disfruten.\nAhora solo contamos con 20 lugares, pero lo vamos a ir aumentando.\nGracias";
	const string INGRESAR_ASIENTO = "Por el momento tenemos disponible 20 lugares para disfrutar de nuestro autocine.\nIngrese un numero entre 20 y 0, de 0 a 10 son los lugares 'VIP' y de 10 a 20, los 'General': ";
	const string SEGUIR_INGRESANDO = "Ingrese un numero entre 20 y 0, de 0 a 10 son los lugares 'VIP' y de 10 a 20, los 'General':";
	const int LUGARES_AUTOCINE = 20;
	const int FIN_DE_DATOS = 0;
	int vectLugares[LUGARES_AUTOCINE]{ 0 };
	int ubicacionElegida, lugaresOcupados;
	float porcentajeOcupadoVIP, porcentajeOcupadoGeneral, ubicacionVip, ubicacionGeneral;
	string msjOcupados, str;
	
	lugaresOcupados = 0;
	porcentajeOcupadoVIP = 0;
	porcentajeOcupadoGeneral = 0;
	ubicacionGeneral = 0;
	ubicacionVip = 0;
	msjOcupados = " ";
	
	darLaBienvenida(MENSAJE_BIENVENIDA);

	ubicacionElegida = validarEntero(INGRESAR_ASIENTO, LUGARES_AUTOCINE, FIN_DE_DATOS);
	
	while (ubicacionElegida != FIN_DE_DATOS && lugaresOcupados <= LUGARES_AUTOCINE) {
		
		if (vectLugares[ubicacionElegida - 1] == 0){
			lugaresOcupados++;
			cout << "Perfecto! Asiento reservado." << endl;
			vectLugares[ubicacionElegida - 1] = 1;

			if (ubicacionElegida < 11){ubicacionVip++;}
			else{ubicacionGeneral++;}
		} else { cout << "El lugar que elegiste se encuentra ocupado" << endl; }
		
		//pide nuevo asiento
		ubicacionElegida = validarEntero(SEGUIR_INGRESANDO, LUGARES_AUTOCINE, FIN_DE_DATOS);
	} 

	if (lugaresOcupados == LUGARES_AUTOCINE) {
		cout << "El autocine esta completo, lo esperamos en la proxima!" << endl;
	} if(lugaresOcupados > 0) {
		for (int i = 0; i <= LUGARES_AUTOCINE; i++) {
			string str = to_string(i + 1);
			if (vectLugares[i] == 1) {
				if (msjOcupados == " ") {
					msjOcupados = str;
				}
				else { msjOcupados = msjOcupados + ", " + str;}
			}
		}
		porcentajeOcupadoGeneral = ubicacionGeneral / LUGARES_AUTOCINE * 200;
		porcentajeOcupadoVIP = ubicacionVip / LUGARES_AUTOCINE * 200;
		mostrarResultados(msjOcupados, porcentajeOcupadoGeneral, porcentajeOcupadoVIP);
	} else {cout << "El autocine esta vacio" << endl;}

	system("pause");
}