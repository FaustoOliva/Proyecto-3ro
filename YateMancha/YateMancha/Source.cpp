#include<iostream>
using namespace std;

void bienvenida() { cout << "Bienvenidos a nuestra tienda de yates.\nActualmente estamos comerciando unos 5 tipos de yates. Megayate, Catamaran, Velero, Grande, Pequeño." << endl; }

int ingresarEntero(string mensaje) {
	int DNI;
	
	do {
		cout << mensaje;
		cin >> DNI;
	} while ((DNI < 9999999 || DNI >100000000) && (DNI !=0));
	return DNI;
}

int ingresarEnteroValidado(string mensaje) {
	int empleado;
	
	do {
		cout << mensaje;
		cin >> empleado;
	} while (empleado < 0 || empleado > 11);
	return empleado;
}

float ingresarCadenaValidada(string mensaje, int tope, string vectYates[]) {
	string yate;
	int i = 0;
	float posicionYate = -1;
	
	cout << mensaje;
	cin >> yate;

	while (i < tope && posicionYate == -1) {
		if (vectYates[i] == yate) { posicionYate = i; }
		else { i++; }
	}
	return posicionYate;
}

bool recorrerVectInt(int posicion, int vectStocks[]) {
	bool hayStock = false;

	if (vectStocks[posicion] > 0) { hayStock = true;}
	return hayStock;
}

char ingresarChar(string mensaje) {
	char formaPago;
	do {
		cout << mensaje;
		cin >> formaPago;
	} while (formaPago != 'E' && formaPago != 'T');
	return formaPago;
}

void mostrarCompra(int DNI, int monto) { cout << "El DNI del cliente es: " << DNI << "\nEl monto a pagar es: " << monto << endl; }

void mostrarInfoDia(int vectContadorYates[], string vectYates[], int tope, int mejorEmpleado, float contadorEfectivo, float contadorTarjeta) {
	for (int i = 0; i < tope; i++) {
		cout << vectYates[i] << ":" << vectContadorYates[i] << endl;
	}

	cout << "El empleado del día: " << mejorEmpleado << endl;
	cout << "La recaudacion por tarjeta: " << contadorTarjeta << "\nEl contador por efectivo: " << contadorEfectivo << endl;
}

void main() {
	setlocale(LC_ALL, "spanish");
	system("color f9");
	const string INGRESAR_DNI = "Ingrese el DNI del cliente, recuerde que son 8 digitos: ";
	const string INGRESAR_YATE = "Ingrese el yate que desea. Si no esta disponible o si no hay stock, le avisaremos: ";
	const string INGRESAR_FORMA_PAGO = "Actualmente si usted compra con efectivo el total a pagar, tiene un 10% de descuento.\Ingrese 'E' si desea efectivo, ingrese 'T' si es tarjeta su forma de pago: ";
	const string INGRESAR_EMPLEADO = "Recuerde que solo hay 10 numeros. Ingrese el numero de empleado que le atendio: ";
	const string INGRESAR_YATE_VALIDADO = "El nombre del yate que usted ingresó, no se encuentra en nuestro negocio actualmente.\nIngrese nuevamente un nombre. Recuerde 'Megayate' 'Cataraman' 'Velero' 'Grande' 'Pequeño': ";

	const int CANT_YATES = 5;
	const int FIN_DE_DATOS = 0; 
	const int CANT_EMPLEADOS = 10;

	string vectYates[CANT_YATES]{"Megayate", "Catamaran", "Velero", "Grande", "Pequeño"};
	int vectStocks[CANT_YATES]{ 1, 3, 5, 7, 12 };
	int vectPrecios[CANT_YATES]{1000000, 750000, 200000, 125000, 50000};
	int vectEmpleados[CANT_EMPLEADOS]{0};
	int vectContadorYates[CANT_YATES]{0};

	int DNI, empleado;
	float aPagar, recaudacionTarjeta= 0, recaudacionEfectivo= 0, posicionYate;
	char formaPago;
    
	int posicionInt, mejorEmpleado = 0;
	bool hayStock;

	bienvenida();

	DNI = ingresarEntero(INGRESAR_DNI);
	while(DNI!=FIN_DE_DATOS) {
		posicionYate = ingresarCadenaValidada(INGRESAR_YATE, CANT_YATES, vectYates);
		while (posicionYate == -1) { posicionYate = ingresarCadenaValidada(INGRESAR_YATE_VALIDADO, CANT_YATES, vectYates); }
		posicionInt = posicionYate;
		hayStock = recorrerVectInt(posicionYate, vectStocks);
		if (!hayStock) { posicionYate = ingresarCadenaValidada(INGRESAR_YATE_VALIDADO, CANT_YATES, vectYates); hayStock = recorrerVectInt(posicionYate, vectStocks); }
		vectStocks[posicionInt]--;
		formaPago = ingresarChar(INGRESAR_FORMA_PAGO);
		empleado = ingresarEnteroValidado(INGRESAR_EMPLEADO);
		
		vectContadorYates[posicionInt]++;

		vectEmpleados[empleado - 1]++;
		if (vectEmpleados[empleado - 1] > mejorEmpleado) { mejorEmpleado = empleado; }

		aPagar = vectPrecios[posicionInt];
		if (formaPago == 'E') {  aPagar =(float)aPagar * 0.9; recaudacionEfectivo = recaudacionEfectivo + aPagar;}
		else { recaudacionTarjeta = recaudacionTarjeta + aPagar; }

		mostrarCompra(DNI, aPagar);
		DNI = ingresarEntero(INGRESAR_DNI);
	}
	mostrarInfoDia(vectContadorYates, vectYates, CANT_YATES, mejorEmpleado, recaudacionEfectivo, recaudacionTarjeta);
}