#include <iostream>
#include <string>
using namespace std;

// Struct para la dirección
struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

// Struct para el estudiante
struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

// Funcion para ingresar estudiante
void ingresarEstudiantes(Estudiante* estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- Ingresando estudiante " << i + 1 << " ---\n";
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, estudiantes[i].nombre);

        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        cout << "Ingrese 5 calificaciones:\n";
        for (int j = 0; j < 5; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> estudiantes[i].calificaciones[j];
        }

        cout << "Direccion - Calle: ";
        cin.ignore();
        getline(cin, estudiantes[i].direccion.calle);

        cout << "Numero: ";
        cin >> estudiantes[i].direccion.numero;

        cout << "Ciudad: ";
        cin.ignore();
        getline(cin, estudiantes[i].direccion.ciudad);
    }
}

//Mostrar estudiante
void mostrarEstudiantes(Estudiante* estudiantes, int cantidad) {
    cout << "\n--- Lista de estudiantes ---\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 5; j++) {
            cout << estudiantes[i].calificaciones[j] << " ";
        }
        cout << "\nDireccion: " << estudiantes[i].direccion.calle << " #"
             << estudiantes[i].direccion.numero << ", "
             << estudiantes[i].direccion.ciudad << endl;
    }
}

// Buscar estudiante
void buscarEstudiante(Estudiante* estudiantes, int cantidad) {
    string nombreBuscado;
    cout << "Ingrese el nombre del estudiante a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "\n--- Estudiante encontrado ---\n";
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Calificaciones: ";
            for (int j = 0; j < 5; j++) {
                cout << estudiantes[i].calificaciones[j] << " ";
            }
            cout << "\nDireccion: " << estudiantes[i].direccion.calle << " #"
                 << estudiantes[i].direccion.numero << ", "
                 << estudiantes[i].direccion.ciudad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un estudiante con ese nombre.\n";
    }
}

// Modificar estudiante
void modificarEstudiante(Estudiante* estudiantes, int cantidad) {
    string nombreBuscado;
    cout << "Ingrese el nombre del estudiante a modificar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "\n--- Modificando datos de " << estudiantes[i].nombre << " ---\n";
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;

            cout << "Ingrese 5 nuevas calificaciones:\n";
            for (int j = 0; j < 5; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cout << "Nueva calle: ";
            cin.ignore();
            getline(cin, estudiantes[i].direccion.calle);

            cout << "Nuevo numero: ";
            cin >> estudiantes[i].direccion.numero;

            cout << "Nueva ciudad: ";
            cin.ignore();
            getline(cin, estudiantes[i].direccion.ciudad);

            encontrado = true;
            cout << "Datos actualizados correctamente.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro un estudiante con ese nombre.\n";
    }
}

//Funcion main
int main() {
    int opcion;
    int cantidad = 0;
    Estudiante* estudiantes = nullptr;

    do {
        cout << "\n===== MENU DE GESTION DE ESTUDIANTES =====\n";
        cout << "1. Ingresar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Modificar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Cuantos estudiantes desea ingresar?: ";
                cin >> cantidad;
                estudiantes = new Estudiante[cantidad];
                ingresarEstudiantes(estudiantes, cantidad);
                break;

            case 2:
                if (cantidad > 0)
                    mostrarEstudiantes(estudiantes, cantidad);
                else
                    cout << "No hay estudiantes registrados.\n";
                break;

            case 3:
                if (cantidad > 0)
                    buscarEstudiante(estudiantes, cantidad);
                else
                    cout << "No hay estudiantes registrados.\n";
                break;

            case 4:
                if (cantidad > 0)
                    modificarEstudiante(estudiantes, cantidad);
                else
                    cout << "No hay estudiantes registrados.\n";
                break;

            case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    delete[] estudiantes;
    return 0;
}