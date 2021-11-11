#include<iostream>
#include<conio.h>
using namespace std;

void darLaBienvenida() { cout << "Bienvenidos a Ako-Mer.\nPara almacenar la compra debera ingresar el DNI, apellido y forma de pago. Para terminar la compra debera ingresar 'FIN' y de todas las compras '0' en el DNI.\nGracias por confiar en nuestro Software =)." << endl; }

int ingresarEntero(string mensaje) {
	int entero;
	cout << mensaje;
	cin >> entero;
	return entero;
}

string ingresarCadena(string mensaje) {
	string cadena;
	cout << mensaje; 
	cin >> cadena;
	return cadena;
}

int validarEnteroMayorIgual0(string mensaje) {
	const string ERROR = "Error al ingresar DNI.\nNo puede ser menor a 0. Ingresalo de nuevo: ";
	int entero;
	entero = ingresarEntero(mensaje);

	while (entero < 0) entero = ingresarEntero(ERROR);
	return entero;
}

string validarCadenaPago(string mensaje) {
	const string ERROR = "Error al ingresar forma de pago.\nLas dos formas de pago es 'Tarjeta' o 'Efectivo'. Ingresalo de nuevo: ";
	string cadena;
	
	cadena = ingresarCadena(mensaje);
	while (cadena != "Efectivo" && cadena != "Tarjeta") cadena = ingresarCadena(ERROR);
	return cadena;
}

bool productoValido(string producto) {
	const string BARKITO = "Barkito";
	const string QUITAMANCHAS = "Quitamanchas";
	const string FIRMESANDWICH = "Firmesandwich";
	const string HARINADAPAN = "HarinaDapan";
	const string ACEITENOSEPEGA = "AceiteNosepega";
	const string MATEKOZI2 = "MateKozi2";
	const string PERCHA = "Percha";
	const string STANCAFE = "StanCafe";
	const string FIN_OPERACION = "FIN";
	return producto == BARKITO || producto == QUITAMANCHAS || producto == FIRMESANDWICH || producto == ACEITENOSEPEGA || producto == HARINADAPAN || producto == MATEKOZI2 || producto == PERCHA || producto == STANCAFE || producto == FIN_OPERACION;
}

string validarProducto(string mensaje) {
	const string ERROR = "El producto ingresado no esta disponible. Ingreselo de nuevo: ";
	string producto;
	producto = ingresarCadena(mensaje);

	while (!productoValido(producto)) { producto=ingresarCadena(ERROR);}
	return producto;
}

int reIngresarCantidad(int stock) {
	const string REINGRESO = "No hay suficiente stock de ese producto. Quedan: ";
	const string INGRESAR_CANTIDAD = "\nIngrese la nueva cantidad: ";
	int cantidad;
	cout << REINGRESO << stock << INGRESAR_CANTIDAD << endl;
	cin >> cantidad;
	return cantidad;
}

int validarStock(string mensaje, string producto, int barkitoStock, int quitamanchasStock, int firmesasandwichStock, int harinaDapanStock, int aceiteNosepegaStock, int mateKozi2Stock, int perchaStock, int stanCafeStock) {
	const string BARKITO = "Barkito";
	const string QUITAMANCHAS = "Quitamanchas";
	const string FIRMESANDWICH = "Firmesandwich";
	const string HARINADAPAN = "HarinaDapan";
	const string ACEITENOSEPEGA = "AceiteNosepega";
	const string MATEKOZI2 = "MateKozi2";
	const string PERCHA = "Percha";
	const string STANCAFE = "StanCafe";
	int cantidad;

	cantidad = ingresarEntero(mensaje);

	if (producto == BARKITO && cantidad > barkitoStock) { cantidad = reIngresarCantidad(barkitoStock); }
	else if (producto == QUITAMANCHAS && cantidad > quitamanchasStock) { cantidad = reIngresarCantidad(quitamanchasStock); }
	else if (producto == FIRMESANDWICH && cantidad > firmesasandwichStock) { cantidad = reIngresarCantidad(firmesasandwichStock); }
	else if (producto == HARINADAPAN && cantidad > harinaDapanStock) { cantidad = reIngresarCantidad(harinaDapanStock); }
	else if (producto == ACEITENOSEPEGA && cantidad > aceiteNosepegaStock) { cantidad = reIngresarCantidad(aceiteNosepegaStock); }
	else if (producto == MATEKOZI2 && cantidad > mateKozi2Stock) { cantidad = reIngresarCantidad(mateKozi2Stock); }
	else if (producto == PERCHA && cantidad > perchaStock) { cantidad = reIngresarCantidad(perchaStock); }
	else if (cantidad > stanCafeStock) { cantidad = reIngresarCantidad(stanCafeStock); }
	return cantidad;
}

int calcularImporte(int cantidad, string producto) {
	const string BARKITO = "Barkito";
	const string QUITAMANCHAS = "Quitamanchas";
	const string FIRMESANDWICH = "Firmesandwich";
	const string HARINADAPAN = "HarinaDapan";
	const string ACEITENOSEPEGA = "AceiteNosepega";
	const string MATEKOZI2 = "MateKozi2";
	const string PERCHA = "Percha";
	const string STANCAFE = "StanCafe";
	
	const int BARKITO_PRECIO = 3;
	const int QUITAMANCHAS_PRECIO = 2;
	const int FIRMESANDWICH_PRECIO = 5;
	const int HARINADAPAN_PRECIO = 1;
	const int ACEITENOSEPEGA_PRECIO = 1;
	const int MATEKOZI2_PRECIO = 3;
	const int PERCHA_PRECIO = 2;
	const int STANCAFE_PRECIO = 4;

	int importe = 0;

	if (producto == BARKITO) { importe = cantidad * BARKITO_PRECIO; }
	else if (producto == QUITAMANCHAS) { importe = cantidad * QUITAMANCHAS_PRECIO; }
	else if (producto == FIRMESANDWICH) { importe = cantidad * FIRMESANDWICH_PRECIO; }
	else if (producto == HARINADAPAN) { importe = cantidad * HARINADAPAN_PRECIO; }
	else if (producto == ACEITENOSEPEGA) { importe = cantidad * ACEITENOSEPEGA_PRECIO; }
	else if (producto == MATEKOZI2) { importe = cantidad * MATEKOZI2_PRECIO; }
	else if (producto == PERCHA) { importe = cantidad * PERCHA_PRECIO; }
	else if (producto == STANCAFE) { importe = cantidad * STANCAFE_PRECIO; }
	return importe;
}

void mostrarInformacionCompra(int DNI, string apellido, string formaPago, float importe) {
	cout << "Dni: " << DNI << "\nApellido: " << apellido << "\nForma de pago: " << formaPago << "\nImporte: " << importe << endl;
}

void mostrarInformacionFinal(string apellido, float maxAbonado, int cantidadEfectivo, int cantidadTarjeta, float recaudacionTotal) {
	cout << "EL importe mas alto: " << maxAbonado << "\nEl apellido quien efectuo la compra: " << apellido << "\nCantidad de compras con Efectivo: " << cantidadEfectivo << "\nCantidad de compras con Tarjeta: " << cantidadTarjeta << "\nLa recaudacion total del dia: " << recaudacionTotal << endl;
}

void mostrarStocks(int barkitoStock, int quitamanchasStock, int firmesasandwichStock, int harinaDapanStock, int aceiteNosepegaStock, int mateKozi2Stock, int perchaStock, int stanCafeStock) {
	cout << "El stock del producto Barkito: " << barkitoStock << "\nEl stock del producto Quitamanchas: " << quitamanchasStock << "\nEl stock del producto Firmesandwwich: " << firmesasandwichStock << "\nEl stock del producto HarinaDapan: " << harinaDapanStock << "\nEl stock del producto AceiteNosepega: " << aceiteNosepegaStock << "\nEl stock del producto MateKozi2: " << mateKozi2Stock << "\nEl stock del producto Percha: " << perchaStock << "\nEl stock del producto StanCafe: " << stanCafeStock << endl;
}

void main() {
	system("color f9");
	const string INGRESAR_DNI = "Ingrese el DNI del comprador. Recuerde que son 8 digitos: ";
	const string INGRESAR_APELLIDO = "Ingrese el apellido del comprador: ";
	const string INGRESAR_FORMA_PAGO = "Ingrese la forma de pago de la compra('Tarjeta' o 'Efectivo'): ";
	const string INGRESAR_PRODUCTO = "Ingrese el producto comprado: ";
	const string INGRESAR_CANTIDAD = "Ingrese la cantidad del producto: ";

	const string BARKITO = "Barkito";
	const string QUITAMANCHAS = "Quitamanchas";
	const string FIRMESANDWICH = "Firmesandwich";
	const string HARINADAPAN = "HarinaDapan";
	const string ACEITENOSEPEGA = "AceiteNosepega";
	const string MATEKOZI2 = "MateKozi2";
	const string PERCHA = "Percha";
	const string STANCAFE = "StanCafe";

	int barkitoStock = 3;
	int quitamanchasStock = 2;
	int firmesasandwichStock = 5;
	int harinaDapanStock = 1;
	int aceiteNosepegaStock = 1;
	int mateKozi2Stock = 3;
	int perchaStock = 2;
	int stanCafeStock = 4;


	int DNI, cantidad, cantidadEfectivo = 0, cantidadTarjeta = 0, importe;
	string formaPago, apellido, producto, apellidoMax;
	float totalAbonar, maxAbonado = -1, recaudacionTotal = 0;

	darLaBienvenida();
	DNI = validarEnteroMayorIgual0(INGRESAR_DNI);

	while (DNI != 0) {
		apellido = ingresarCadena(INGRESAR_APELLIDO);
		formaPago = validarCadenaPago(INGRESAR_FORMA_PAGO);
		importe = 0, totalAbonar = 0;
		if (formaPago == "Efectivo") cantidadEfectivo++;
		else cantidadTarjeta++;

		producto = validarProducto(INGRESAR_PRODUCTO);
		while (producto != "FIN") {
			cantidad = validarStock(INGRESAR_CANTIDAD, producto, barkitoStock, quitamanchasStock, firmesasandwichStock, harinaDapanStock, aceiteNosepegaStock, mateKozi2Stock, perchaStock, stanCafeStock);

			if (producto == BARKITO) { barkitoStock = barkitoStock - cantidad; }
			else if (producto == QUITAMANCHAS) { quitamanchasStock = quitamanchasStock - cantidad; }
			else if (producto == FIRMESANDWICH) { firmesasandwichStock = firmesasandwichStock - cantidad; }
			else if (producto == HARINADAPAN) { harinaDapanStock = harinaDapanStock - cantidad; }
			else if (producto == ACEITENOSEPEGA) { aceiteNosepegaStock = aceiteNosepegaStock - cantidad; }
			else if (producto == MATEKOZI2) { mateKozi2Stock = mateKozi2Stock - cantidad; }
			else if (producto == PERCHA) { perchaStock = perchaStock - cantidad; }
			else if (producto == STANCAFE) { stanCafeStock = stanCafeStock - cantidad; }

			importe = calcularImporte(cantidad, producto);
			totalAbonar = totalAbonar + importe;
			producto = validarProducto(INGRESAR_PRODUCTO);
		}

		if (formaPago == "Efectivo") { totalAbonar = (float)totalAbonar * 0.9; }
		mostrarInformacionCompra(DNI, apellido, formaPago, totalAbonar);
		_getch();
		system("cls");
		if (totalAbonar > maxAbonado) { maxAbonado = totalAbonar; apellidoMax = apellido; }

		recaudacionTotal = recaudacionTotal + totalAbonar;
		DNI = validarEnteroMayorIgual0(INGRESAR_DNI);
	}
	_getch();
	system("cls");
	mostrarInformacionFinal(apellidoMax, maxAbonado, cantidadEfectivo, cantidadTarjeta, recaudacionTotal);
	mostrarStocks(barkitoStock, quitamanchasStock, firmesasandwichStock, harinaDapanStock, aceiteNosepegaStock, mateKozi2Stock, perchaStock, stanCafeStock);
}