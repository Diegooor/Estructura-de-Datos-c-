#include <iostream>
using namespace std;

// Implementación de las funciones aquí...

// creo constantes globales para materias y notas, las mismas se usan en varias funciones
const int NUM_MATERIAS = 3;
const int NUM_NOTAS = 3;
string materias[NUM_MATERIAS] = {"Matematicas", "Fisica", "Quimica"};

// creo la estructura de datos para los estudiantes
struct Estudiante {
    string nombre;
    int codigo;
    float notas[NUM_MATERIAS][NUM_NOTAS];
    bool activo = true; 
};

// creo funcion para registrar estudiantes

void registrar(Estudiante estudiantes[], int cantidadEstudiantes) {
    for (int i = 0; i < cantidadEstudiantes; i++) {
        cout << "Ingrese el nombre del estudiante " << i+1 << endl;
        cin >> estudiantes[i].nombre;
        cout << "Ingrese el codigo del estudiante " << i+1 << endl;
        cin >> estudiantes[i].codigo;
        for (int m = 0; m < NUM_MATERIAS; m++) {
            for (int n = 0; n < NUM_NOTAS; n++) {
                cout << "Ingrese la nota numero " << n+1 << " de " << materias[m] << endl;
                cin >> estudiantes[i].notas[m][n];
            }
        }
        estudiantes[i].activo = true;
    }
}

// creo funcion para mostrar reporte de estudiantes

void mostrarReporte(Estudiante estudiantes[], int cantidadEstudiantes) {
    cout << "Reporte de estudiantes" << endl;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (!estudiantes[i].activo) continue;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Codigo: " << estudiantes[i].codigo << endl;
        for (int m = 0; m < NUM_MATERIAS; m++) {
            float sumaNotas = 0;
            cout << materias[m] << ": ";
            for (int n = 0; n < NUM_NOTAS; n++) {
                cout << estudiantes[i].notas[m][n] << " ";
                sumaNotas += estudiantes[i].notas[m][n];
            }
            cout << " | Promedio: " << sumaNotas / NUM_NOTAS << endl;
        }
        cout << "------------------------" << endl;
    }
}

// creo funcion para actualizar datos de un estudiante

void actualizar(Estudiante estudiantes[], int cantidadEstudiantes) {
    int codigoBuscado;
    cout << "Ingrese el codigo del estudiante a actualizar: ";
    cin >> codigoBuscado;
    bool encontrado = false;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].codigo == codigoBuscado && estudiantes[i].activo) {
            encontrado = true;
            cout << "Estudiante encontrado: " << estudiantes[i].nombre << endl;
            cout << "Ingrese el nuevo nombre (o el mismo para no cambiar): ";
            cin >> estudiantes[i].nombre;
            cout << "Ingrese el nuevo codigo (o el mismo para no cambiar): ";
            cin >> estudiantes[i].codigo;
            for (int m = 0; m < NUM_MATERIAS; m++) {
                for (int n = 0; n < NUM_NOTAS; n++) {
                    cout << "Ingrese la nueva nota numero " << n+1 << " de " << materias[m] << " (o la misma para no cambiar): ";
                    cin >> estudiantes[i].notas[m][n];
                }
            }
            cout << "Datos actualizados correctamente." << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante con codigo " << codigoBuscado << " no encontrado." << endl;
    }
}

//creo funcion para eliminar estudiantes

void eliminar(Estudiante estudiantes[], int cantidadEstudiantes) {
    int codigoBuscado;
    cout << "Ingrese el codigo del estudiante a eliminar: ";
    cin >> codigoBuscado;
    bool encontrado = false;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].codigo == codigoBuscado && estudiantes[i].activo) {
            estudiantes[i].activo = false;
            cout << "Estudiante eliminado correctamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante con codigo " << codigoBuscado << " no encontrado." << endl;
    }
}

// creo funcion para buscar estudiante por codigo

void buscarPorCodigo(Estudiante estudiantes[], int cantidadEstudiantes) {
    int codigoBuscado;
    cout << "Ingrese el codigo del estudiante a buscar: ";
    cin >> codigoBuscado;
    bool encontrado = false;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].codigo == codigoBuscado && estudiantes[i].activo) {
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Codigo: " << estudiantes[i].codigo << endl;
            for (int m = 0; m < NUM_MATERIAS; m++) {
                cout << materias[m] << ": ";
                for (int n = 0; n < NUM_NOTAS; n++) {
                    cout << estudiantes[i].notas[m][n] << " ";
                }
                cout << endl;
            }
            encontrado = true;
            break;
        }
    }

    // si el estudiante no fue encontrado, muestro mensaje
    if (!encontrado) {
        cout << "Estudiante con codigo " << codigoBuscado << " no encontrado." << endl;
    }
}


// creo funcion para mostrar estadisticas (mejor y peor promedio)

void mostrarEstadisticas(Estudiante estudiantes[], int cantidadEstudiantes) {
    float mejorPromedio = -1;
    float peorPromedio = 101;
    int idxMejor = -1, idxPeor = -1;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (!estudiantes[i].activo) continue;
        float sumaTotal = 0;
        int totalNotas = 0;
        for (int m = 0; m < NUM_MATERIAS; m++) {
            for (int n = 0; n < NUM_NOTAS; n++) {
                sumaTotal += estudiantes[i].notas[m][n];
                totalNotas++;
            }
        }

        // calculo el promedio del estudiante
        float promedio = sumaTotal / totalNotas;
        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            idxMejor = i;
        }
        // actualizo el indice del peor promedio
        if (promedio < peorPromedio) {
            peorPromedio = promedio;
            idxPeor = i;
        }
    }
    if (idxMejor != -1) {
        cout << "Estudiante con mejor promedio: " << estudiantes[idxMejor].nombre << " (" << mejorPromedio << ")" << endl;
    }
    if (idxPeor != -1) {
        cout << "Estudiante con peor promedio: " << estudiantes[idxPeor].nombre << " (" << peorPromedio << ")" << endl;
    }
}
