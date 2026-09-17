#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "ListaEstudiantes.h"

using namespace std;

int main()
{
    ListaEstudiantes estudiantes;

    ifstream archivo("datos/estudiantes.txt");

    if(!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string nombre;

    while(getline(archivo, nombre))
    {
        if(!nombre.empty())
        {
            Estudiante estudiante(nombre);

            // Punto 6.2:
            estudiantes.insertOrdenado(estudiante);
        }
    }

    archivo.close();

    cout << "Estudiantes cargados: "
         << estudiantes.size() << endl;

    for(int i = 0; i < estudiantes.size(); i++)
    {
        Estudiante& estudiante = estudiantes.get(i);

        int cantidad;

        cout << "\nEstudiante: "
             << estudiante.getNombre() << endl;

        while(true)
        {
            cout << "Cantidad de calificaciones (0-4): ";

            string entrada;
            if(!getline(cin, entrada))
            {
                cout << "\nEntrada finalizada." << endl;
                return 1;
            }

            // Leer la linea completa evita dejar letras pendientes en cin.
            istringstream lectura(entrada);
            char sobrante;

            if(lectura >> cantidad && !(lectura >> sobrante) &&
               cantidad >= 0 && cantidad <= 4)
            {
                break;
            }

            cout << "Ingrese un numero entero entre 0 y 4." << endl;
        }

        for(int j = 0; j < cantidad; j++)
        {
            double nota;

            while(true)
            {
                cout << "Calificacion " << j + 1 << ": ";

                string entrada;
                if(!getline(cin, entrada))
                {
                    cout << "\nEntrada finalizada." << endl;
                    return 1;
                }

                istringstream lectura(entrada);
                char sobrante;

                if(lectura >> nota && !(lectura >> sobrante) &&
                   isfinite(nota) && nota >= 0)
                {
                    break;
                }

                cout << "Ingrese una calificacion numerica no negativa." << endl;
            }

            estudiante.agregarCalificacion(nota);
        }
    }

    cout << "\n===== RESULTADOS =====\n" << endl;

    estudiantes.print();

    return 0;
}
