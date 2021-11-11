#include <iostream>
#include<conio.h> // Libreria para incluir el _getch
using namespace std;

string pedirClave(string mensaje) {
    string clave;
    cout << mensaje << endl;
    cin >> clave;
    return clave;
}

bool validarClave(string clave, string msj_Correcta, string msj_Error, string msj_Pista, string respuesta, bool vivo) {
    const string PEDIR_PISTA = "PISTA";
    int errores = 0;
    bool respondidoBien = false;

    while (!respondidoBien && errores != 2) {
       

        if (clave == PEDIR_PISTA) {
            cout << msj_Pista << endl;
            cin >> clave;
        }

        else if (clave == respuesta) {
            cout << msj_Correcta << endl;
            respondidoBien = true;
        }

        else {
            clave = pedirClave(msj_Error);
            errores++;
        }

    }
    if (errores == 2) vivo = false;
    return vivo;
}



bool resolverSala1(string mensaje, string error, string correcta, bool vivo) {
    const string MENSAJE_PISTA = "Ha solicitado la pista de esta habitacion, que es la siguiente. La verdad no me puedo creer que haya solicitado esta pista, pero bueno es mi trabajo. El lugar es un pais de Sudamerica.";
    const string RESPUESTA_CLAVE = "ARGENTINA";
    string clave;
    system("color 71");
    clave = pedirClave(mensaje);
    vivo = validarClave(clave, correcta, error, MENSAJE_PISTA, RESPUESTA_CLAVE, vivo);

    return vivo;
}


bool resolverSala2(string mensaje, string error, string correcta, bool vivo) {
    const string MENSAJE_PISTA = " Ha solicitado la pista de esta habitacion, que es la siguiente. Que poco de historia que enseñan en las escuelas de ahora, un poco de respeto a las figuras de este pais. La mujer fue la esposa de un presidente de Argentina.";
    const string RESPUESTA_CLAVE = "EVITA";
    string clave;
    system("color f0");
    clave = pedirClave(mensaje);
    vivo = validarClave(clave, correcta, error, MENSAJE_PISTA, RESPUESTA_CLAVE, vivo);
   

    return vivo;
}

bool resolverSala3(string mensaje, string error, string correcta, bool vivo) {
    const string MENSAJE_PISTA = "Ha solicitado la pista de esta habitacion, que es la siguiente. Perdonamos, pero no olvidamos… parece que vos hiciste lo que quisiste. El año es de una guerra ocurrida en unas islas. ";
    const string RESPUESTA_CLAVE = "1982";
    string clave;
    system("color 81");
    clave = pedirClave(mensaje);
    vivo = validarClave(clave, correcta, error, MENSAJE_PISTA, RESPUESTA_CLAVE, vivo);

    return vivo;
}

bool resolverSala4(string mensaje, string error, string correcta, bool vivo) {
    const string MENSAJE_PISTA = "Ha solicitado la pista de esta habitacion, que es la siguiente. Esta es difícil, asi que te la perdono, pero cuidado, la pista esta en la ultima palabra de la descripción de la habitacion, suerte. ";
    const string RESPUESTA_CLAVE = "PATO";
    string clave;
    system("color 6A");
    clave = pedirClave(mensaje);
    vivo = validarClave(clave, correcta, error, MENSAJE_PISTA, RESPUESTA_CLAVE, vivo);

    return vivo;
}



void main() {
    setlocale(LC_ALL, "spanish");
    const string MENSAJE_INICIO = "Bienvenidos al juego de escape que organizo el museo de historia para esta cuarentena. Trata de 4 habitaciones que tenes que encontrar la clave para pasar hacia la siguiente, asi pasar por todas y ganar el juego. Tendras que analizar lo que hay en cada habitacion y asi llegar a la clave. Se evaluara el conocimiento que tenes sobre la historia del pais y tu \ncapacidad de razonamiento con lo que tendras disponible en cada habitacion.\nAntes de comenzar algunas especificaciones. La clave consta de una sola palabra y se tendra que escribir en mayusculas\npara que este correcta, en cada habitacion tendras la posibilidad de acceder a una pista; tendras que escribir (PISTA)\npara recibirla. Eso es todo, ¡Mucha suerte!";
    const string MENSAJE_ERRONEA = "Ha ingresado una respuesta incorrecta. Recuerde usar las mayusculas en la clave y si tiene disponible y se\nle complica la respuesta, use la pista; ingresando PISTA";
    const string MENSAJE_CORRECTA = "¡Respondiste correctamente! Presione enter para pasar a la siguiente habitacion y seguir con el juego";
    const string MENSAJE_SALA1 = "En esta primera habitacion, te encontras que hay una mesa ni bien entras, con algunos objetos sobre ella. Sobre la mesa hay un colectivo pequeño de coleccion, una birome negra sin usar y un sifon de soda con el contenido por la mitad. Des\npues la habitacion no tiene nada mas de interesante, no hay ventanas, hay manchas de humedad en una de las esquinas del techo y una estufa de colegio en una de las paredes. Tenes que ingresar la clave en una puerta, para pasar hacia la si\nguiente sala. La clave esta en que lugar se inventaron estos objetos: ";
    const string MENSAJE_SALA2 = "Esta segunda habitacion es igual a la anterior; sin ventanas, con manchas de humedad en el techo y con una estufa con\nperdida de gas. En la pared a tu derecha hay colgado un cuadro de una mujer a que cuya cara te suena familiar, con el pelo en forma de rodete, la foto parece vieja. En esta habitacion también hay una mesa con objetos. Sobre ella hay una ca\nja de carton con una apertura en el frente, que te parece que simula a una urna, y al lado hay 3 papeles de diferentes\ncolores. Uno azul clarito, otro amarillo y el ultimo rojo pasion. Para esta clave necesitaras el nombre de la mujer del cuadro: ";
    const string MENSAJE_SALA3 = "Pero esta sera mas complicada y a diferencia a las anteriores; en esta no hay humedad en el techo… ah me olvidaba la clave es un numero en vez de una palabra. Hay varios fusiles apoyados sobre una pared; no tenes conocimiento de armas y no tenes ni idea de que calibre son y de que año. Hay un abrigo colgado en un ganchito en una de las paredes, se ve bastan\nte abrigable, pero la estufa esta prendida y tenes alto calor. Miras hacia arriba y en el techo hay colgados dos aviones en escala de juguete. Como te dije anteriormente la clave es un numero y se te ocurre que puede ser un año, pero año de que: ";
    const string MENSAJE_SALA4 = " Wow! Tenes bastante conocimiento de nuestro pais por lo que veo, o usaste todas las pistas en las habitaciones je. Lle\ngaste a la ultima sala, es igual a las anteriores, siguen sin haber ventanas, el plomero no vino y la estufa sigue estando en la misma pared, pero esta vez apagada. Esta es la ultima clave que tendras que descubir para ganar el juego. Lo\nprimero que notas es que hay plumas por todos lados, como si hubiera pasado una guerra de almohadas 5 minutos antes o habían desplumado a un pollo. Ves diferentes herraduras de caballos colgadas en las paredes y monturas. En medio de la ha\nbitacion, sobre el piso yace una boina de color rojo con olor a campo. No tenes idea como estas cosas pueden estar rela\ncionadas, pero se te ocurre pensar en una actividad o deporte: ";
    const string MENSAJE_FINAL = "¡Felicitaciones has pasado exitosamente el juego! Ya puedes salir de la habitacion. El premio de haber ganado el juego es el conocimiento sobre estos datos. ¡Nos vemos en la proxima!";
    const string MENSAJE_PERDISTE = "Has superado los 3 errores en la habitacion. Salgase del juego.";
    bool sigueVivo = true;

    cout << MENSAJE_INICIO << endl;
    _getch();  //Funciona igual que el cin.get, pero este ultimo no me funciona 
    system("cls");
    sigueVivo = resolverSala1(MENSAJE_SALA1, MENSAJE_ERRONEA, MENSAJE_CORRECTA, sigueVivo);
    _getch();
    system("cls");
    if (sigueVivo) {
        sigueVivo = resolverSala2(MENSAJE_SALA2, MENSAJE_ERRONEA, MENSAJE_CORRECTA, sigueVivo);
        _getch();
        system("cls");
    }
    if (sigueVivo) {
        sigueVivo = resolverSala3(MENSAJE_SALA3, MENSAJE_ERRONEA, MENSAJE_CORRECTA, sigueVivo);
        _getch();
        system("cls");
    }
    if (sigueVivo) {
        sigueVivo = resolverSala4(MENSAJE_SALA4, MENSAJE_ERRONEA, MENSAJE_FINAL, sigueVivo);
 
    }
    else cout << MENSAJE_PERDISTE << endl;

}