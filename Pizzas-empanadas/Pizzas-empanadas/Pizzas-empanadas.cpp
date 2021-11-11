#include<iostream> //Con estas lineas me conecto a teclado y pantalla
using namespace std;

 //Definicion del programa principal
void main() {
    string nombreUsuario; //Estas lineas declaran las diferentes variables
    string contraseña;
    int pizzasMuzarella;
    int pizzasJamonyMorrones;
    int pizzasNapolitana;
    int pizzasFugazeta;
    int empCarne;
    int empPollo;
    int empJyQ;
    string Cocción;
    string masa;

    cout << "Ingrese nombre de usuario:" <<endl;
    cin >> nombreUsuario; //Ingresar valor para nombreUsuario
    cout << "Su nombre de usuario es:" <<nombreUsuario <<endl; 
    
    cout << "Ingrese su contraseña:" <<endl;
    cin >> contraseña;
    cout << "Su contraseña es:" << contraseña <<endl;
    
    cout << "Ingrese la cantidad de pizzas muzarella:" <<endl;
    cin >> pizzasMuzarella;
    
    cout << "Ingrese la cantidad de pizzas jamon y morrones:" <<endl;
    cin >> pizzasJamonyMorrones;
    
    cout << "Ingrese la cantidad de pizzas napolitanas:" <<endl;
    cin >> pizzasNapolitana;
    
    cout << "Ingrese la cantidad de pizzas fugazeta:" <<endl;
    cin >> pizzasFugazeta;
    
    cout << "Ingrese la cantidad de empanadas de carne:" <<endl;
    cin >> empCarne;

    cout << "Ingrese la cantidad de empanadas de pollo:" <<endl;
    cin >> empPollo;

    cout << "Ingrese la cantidad de empanadas de jamon y queso:" <<endl;
    cin >> empJyQ;
    
    
    cout << "Ingrese el tipo de masa de todas las pizzas:" <<endl;
    cin >> masa;

    cout << "Ingrese el tipo de coccion de las empanadas:" <<endl;
    cin >> Cocción;

    cout << "Pizzas muza:" << pizzasMuzarella << endl;
    cout << "Pizzas JYM:" << pizzasJamonyMorrones << endl;
    cout << "Pizzas napo:" << pizzasNapolitana << endl;
    cout << "Pizzas fugaza:" << pizzasFugazeta << endl;
    cout << "Empanadas C:" << empCarne << endl;
    cout << "Empanadas P:" << empPollo << endl;
    cout << "Empandas JYQ:" << empJyQ << endl;


    cout << "Cantidad de pizzas en total:" << pizzasMuzarella + pizzasJamonyMorrones + pizzasFugazeta + pizzasNapolitana << endl;
    cout << "Cantidad de empanadas en total:" << empCarne + empPollo + empJyQ << endl; 
    system("pause"); //Pausar la ejecución
}