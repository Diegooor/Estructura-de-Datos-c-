#include <iostream>
#include <string>
using namespace std;

// Importar las funciones y estructuras desde funciones.h
#include "funciones.h"

// --- Función Principal (main) ---
int main()
{
    cout << "Bienvenido al sistema de gestion de notas" << endl;
    cout << "Actualmente no existen estudiantes registrados." << endl;
    cout << "Ingrese la cantidad de estudiantes que desea registrar" << endl;
    int cantidadEstudiantes;
    cin >> cantidadEstudiantes;
    // Valido que la cantidad de estudiantes sea positiva
    if (cantidadEstudiantes > 0)
    {
        // Creo un arreglo de estudiantes
        Estudiante estudiantes[cantidadEstudiantes];

        // Registro los estudiantes llamando a la función registrar
        registrar(estudiantes, cantidadEstudiantes);

        int opcion;

        // creo estructura de control para el menú
        do
        {
            cout << "\nMenu Principal" << endl;
            cout << "1. Actualizar datos de un estudiante" << endl;
            cout << "2. Eliminar estudiante" << endl;
            cout << "3. Buscar estudiante por codigo" << endl;
            cout << "4. Mostrar estadisticas (mejor y peor promedio)" << endl;
            cout << "5. Mostrar reporte de estudiantes" << endl;
            cout << "6. Salir" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                actualizar(estudiantes, cantidadEstudiantes);
                break;
            case 2:
                eliminar(estudiantes, cantidadEstudiantes);
                break;
            case 3:
                buscarPorCodigo(estudiantes, cantidadEstudiantes);
                break;
            case 4:
                mostrarEstadisticas(estudiantes, cantidadEstudiantes);
                break;
            case 5:
                mostrarReporte(estudiantes, cantidadEstudiantes);
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
            }
        } while (opcion != 6);
    }
    else
    {
        cout << "La cantidad de estudiantes debe ser mayor a 0" << endl;
    }
    return 0;
}
