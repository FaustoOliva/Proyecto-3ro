#include<iostream>
using namespace std;

float pedirHora(string mensaje) {
    float hora;
    cout << mensaje << endl;
    cin >> hora;
    return hora;
}

bool validezHorario(float horario, int apertura, int cerrado) {
    bool estado;

    if (horario >= apertura && horario <= cerrado) {
        estado = true;
    }
    else{
        estado = false;

    }
    return estado;
}

void avisarEstadoEstacionamiento(string mensaje) {
    cout << mensaje << endl;
}

void definirEstado(string mensaje, float hora, string mensajeAbierto, string mensajeCerrado, bool estaAbierto) {

    if(hora <= 0 || hora > 24){
        cout << mensaje;

    } else if(estaAbierto) {
            avisarEstadoEstacionamiento(mensajeAbierto);

        }
        else if (!estaAbierto) {
            avisarEstadoEstacionamiento(mensajeCerrado);
        }
}


void main() {
    float hora;
    bool estaAbierto;
    const int HORA_APERTURA= 10;
    const int HORA_CERRADO = 18;
    const string MENSAJE_HORA = "Ingrese la hora en tiempo real: ";
    const string MENSAJE_ABIERTO = "El estacionamiento Bruselas se encuentra abierto. Su vehiculo esta seguro con nosotros.";
    const string MENSAJE_CERRADO = "El estacionamiento Bruselas esta cerrado. Vuelva entre las 10am a 18pm inclusive.";
    const string MENSAJE_HORA_INCORRECTO = "Ha ingresado una hora incorrecta, debe ser mayor a 0 y menor a 24. - estacionamiento Bruselas";

    hora = pedirHora(MENSAJE_HORA);
    estaAbierto = validezHorario(hora, HORA_APERTURA, HORA_CERRADO); 
    definirEstado(MENSAJE_HORA_INCORRECTO, hora, MENSAJE_ABIERTO, MENSAJE_CERRADO, estaAbierto);
   

}