#include<iostream>
using namespace std; 

void main() {
	const int precioInicial = 12;
	string tipo;
	float tamaño;
	float resu;
	

	cout << "Escriba el tipo de uva que quiera (A o b): " << endl;
	cin >> tipo;
    
	cout << "Escriba el tamaño que quiera (1 o 2): " << endl;
	cin >> tamaño;


	if (tipo=="A" && tamaño==1) {

		resu= precioInicial + 0.20;
	}
	else if (tipo=="A" && tamaño == 2) {

		resu= precioInicial + 0.30;
     }
	else if (tipo=="B" && tamaño == 1) {
	
		resu= precioInicial - 0.30;
	}
	else if (tipo=="B" && tamaño == 2) {
	
		resu= precioInicial - 0.50;
	}

	cout << "La recaudacion del productor es: $" << resu << endl;


 
}