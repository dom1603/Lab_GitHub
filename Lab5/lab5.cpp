#include <iostream>
using namespace std;

//Inicio
int main() {
    //Declarar variable
    int num;
    
    //Peticion de numero
    cout << "Ingresa un numero entero: ";
    cin >> num;
    cout << "Tabla de multiplicar del " << num << ":" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }

    return 0;
}