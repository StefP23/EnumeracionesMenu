#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// Enumeraciones solicitadas: Meses, días y estaciones
enum Meses { ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE };
enum Dias { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
enum Estaciones { PRIMAVERA, VERANO, OTONO, INVIERNO };

// Arreglos de nombres de meses, días y estaciones
string nombresMeses[] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
string nombresDias[] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo" };
string nombresEstaciones[] = { "Primavera", "Verano", "Otoño", "Invierno" };

// Funciones para mostrar en orden o inverso
void mostrarMeses(bool inverso) {
    if (!inverso) {
        for (int i = ENERO; i <= DICIEMBRE; i++) // Mostrar meses en orden
            cout << nombresMeses[i] << endl;
    } else {
        for (int i = DICIEMBRE; i >= ENERO; i--) // Mostrar meses en orden inverso
            cout << nombresMeses[i] << endl;
    }
}
// Función para mostrar días
void mostrarDias(bool inverso) {
    //Estructura de control para mostrar los días de la semana en orden o inverso
    if (!inverso) {
        for (int i = LUNES; i <= DOMINGO; i++) // Muestra días en orden
            cout << nombresDias[i] << endl;
    } else {
        for (int i = DOMINGO; i >= LUNES; i--) // Muestra días en orden inverso
            cout << nombresDias[i] << endl;
    }
}

// Función para mostrar estaciones
void mostrarEstaciones(bool inverso) {
    //Estructura de control para mostrar las estaciones en orden o inverso
    if (!inverso) {
        for (int i = PRIMAVERA; i <= INVIERNO; i++) // Muestra estaciones en orden 
            cout << nombresEstaciones[i] << endl;
    } else {
        for (int i = INVIERNO; i >= PRIMAVERA; i--) // Muestra estaciones en orden inverso
            cout << nombresEstaciones[i] << endl;
    }
}

// Función para mostrar el menú
int main() {
    SetConsoleOutputCP(65001); 

    // Variables para la opción seleccionada y el orden
    int opcion, orden;
    bool inverso = false;

    // Bucle para mostrar el menú y procesar la opción seleccionada
    do {
        // Se muestra el menú
        cout << "\n======= MENÚ =======\n";
        cout << "1. Mostrar meses del año\n";
        cout << "2. Mostrar días de la semana\n";
        cout << "3. Mostrar estaciones\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Validación de la opción seleccionada
        cout << "\n==== SELECCIONE EL MODO A MOSTRAR ====\n";
        if (opcion >= 1 && opcion <= 3) {
            cout << "1. Mostrar en orden\n";
            cout << "2. Mostrar en orden inverso\n";
            cout << "Seleccione el modo de ordenamiento: ";
            cin >> orden;
            // Validación del modo de ordenamiento
            inverso = (orden == 2);
            cout << "\n";
        }
        
        // Se utiliza una estructura de control switch para mostrar los meses, días o estaciones
        switch (opcion) {
            case 1:
                mostrarMeses(inverso);              // Mostrar meses
                break;
            case 2:
                mostrarDias(inverso);               // Mostrar días
                break;
            case 3:
                mostrarEstaciones(inverso);         // Mostrar estaciones
                break;
            case 4:
                cout << "Saliendo...\n";
                Sleep(1000);                        // Espera de 1 segundo antes de salir
                break;
            default:
                cout << "Opción inválida.\n";       // Mensaje de error si la opción no es válida
        }
    } while (opcion != 4);                          // Bucle hasta que el usuario seleccione salir

    return 0;                                       // Fin del programa
}