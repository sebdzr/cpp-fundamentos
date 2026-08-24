#include "SistemaAerocivil.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// ============================================================
// ENTRADAS SEGURAS
// ============================================================

int leerEntero(const string& mensaje)
{
    int valor;

    while(true)
    {
        cout << mensaje;

        if (cin >> valor)
        {
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            return valor;
        }

        cout << "Entrada invalida. Intente nuevamente.\n";

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}

string leerTexto(const string& mensaje)
{
    string texto;

    do
    {
       cout << mensaje;
       getline(cin, texto);

       if(texto.empty())
       {
          cout << "El texto no puede estar vacio.\n";
       }

    } while (texto.empty());

    return texto;
    
}

int leerDia()
{
    int dia;

    do
    {
        dia = leerEntero(
            "Dia (1=Lunes, 2=Martes, 3=Miercoles, "
            "4=Jueves, 5=Viernes, 6=Sabado, 7=Domingo: "
        );

        if (dia < 1 || dia > 7)
        {
            cout << "Dia invalido.\n";
        }

    } while (dia < 1 || dia > 7);
    
    return dia - 1; 
}

string nombreDia(int dia)
{
    const string dias[7] =
    {
        "Lunes",
        "Martes",
        "Miercoles",
        "Jueves",
        "Viernes",
        "Sabado",
        "Domingo"
    };

    if (dia < 0 || dia >= 7)
    {
        return "Desconocido";
    }

    return dias[dia];
}


// ============================================================
// MOSTRAR INFORMACION
// ============================================================

void mostrarVuelo(const Vuelo& vuelo)
{
    cout << "Codigo: "
         << vuelo.getCodigo()
         << '\n';

    cout << "Ruta: "
         << vuelo.getOrigen()
         << " -> "
         << vuelo.getDestino()
         << '\n';
    
    cout << "Hora: "
         << vuelo.getHora()
         << '\n';

    cout << "Aeronave: "
         << vuelo.getAeronave().getModelo()
         << '\n';
        
    cout << "Capacidad / pasajeros: "
         << vuelo.getCantidadPasajeros()
         << '\n';

}

void mostrarAerolinea(const Aerolinea& aerolinea)
{
    cout << "\n========================================\n";
    cout << aerolinea.getNombre()
         << " ("
         << aerolinea.getCodigo()
         << ")\n";
    cout << "\n========================================\n";

    bool tieneVuelos = false;

    for (int dia = 0; dia < 7; dia++)
    {
        int cantidad =
            aerolinea.getCantidadVuelos(dia);
        
        cout << "\n"
             << nombreDia(dia)
             << " - "
             << cantidad
             << " vuelos(s)\n";
        
        for (int i = 0; i < cantidad; i++)
        {
            const Vuelo* vuelo =
                aerolinea.getVuelo(dia, i);
            
            if (vuelo != nullptr)
            {
                tieneVuelos = true;

                cout << "\n Vuelo "
                     << i + 1
                     << '\n';
                
                mostrarVuelo(*vuelo);
            }
        }
    }

    if (!tieneVuelos)
    {
        cout << "\nLa aerolinea no tiene vuelos registrados.\n";
    }
}

void mostrarSistema(const SistemaAerocivil& sistema)
{
    cout << "\n========== AEROCIVIL COLOMBIA ==========\n";
    cout << "Aeropuerto Vanguardia - Villavicencio\n";

    cout << "Aerolineas registradas: "
         << sistema.getCantidadAerolineas()
         << '\n';

    for (
        int i = 0;
        i < sistema.getCantidadAerolineas();
        i++
    )
    {
        const Aerolinea* aerolinea =
            sistema.getAerolinea(i);
        
        if (aerolinea != nullptr)
        {
            mostrarAerolinea(*aerolinea);
        }
    }
}

// ============================================================
// CRUD AEROLINEAS
// ============================================================

void registrarAerolinea(SistemaAerocivil& sistema)
{
    cout << "\n=== REGISTRAR AEROLINEA ===\n";

    string nombre =
        leerTexto("Nombre: ");

    string codigo =
        leerTexto("Codigo: ");
    
    Aerolinea nueva(nombre, codigo);

    if (sistema.agregarAerolinea(nueva))
    {
        cout << "Aerolinea registrada correctamente.\n";
    }
    else
    {
        cout << "No se pudo registrar. "
             << "El codigo ya existe.\n";
    }
}

void actualizarAerolinea(SistemaAerocivil& sistema)
{
    cout << "\n=== ACTUALIZAR AEROLINEA ===\n";

    string codigoActual =
        leerTexto("Codigo actual: ");
    
    Aerolinea* aerolinea =
        sistema.buscarAerolinea(codigoActual);
    
    if (aerolinea == nullptr)
    {
        cout << "Aerolinea no encontrada.\n";
        return;
    }

    cout << "\n1. Cambiar nombre\n";
    cout << "2. Cambiar codigo\n";
    cout << "0. Cancelar\n";

    int opcion =
        leerEntero("Opcion: ");

    switch (opcion)
    {
        case 1:
        {
            string nuevoNombre =
                leerTexto("Nuevo nombre: ");
            
            aerolinea->setNombre(nuevoNombre);

            cout << "Nombre actualizado.\n";
            break;
        }

        case 2:
        {
            string nuevoCodigo =
                leerTexto("Nuevo codigo: ");

            Aerolinea* existente =
                sistema.buscarAerolinea(nuevoCodigo);

            if (
                existente != nullptr &&
                existente != aerolinea
            )
            {
                cout << "Ese codigo ya pertenece "
                     << "a otra aerolinea.\n";

                break;
            }

            aerolinea->setCodigo(nuevoCodigo);

            cout << "Codigo actualizado.\n";
            break;
        
        }

        case 0:
            cout << "Operacion cancelada.\n";
            break;

        default:
            cout << "Opcion invalida.\n";
            break;
    
    }
}

void eliminarAerolinea(SistemaAerocivil& sistema)
{
    cout << "\n=== ELIMINAR AEROLINEA ===\n";

    string codigo =
        leerTexto("Codigo: ");
    
    if (sistema.eliminarAerolinea(codigo))
    {
        cout << "Aerolinea eliminada correctamente.\n";
    }
    else
    {
        cout << "Aerolinea no encontrada.\n";
    }
}

void menuAerolineas(SistemaAerocivil& sistema)
{
    int opcion;

    do
    {
       cout << "\n====== ADMINISTRAR AEROLINEAS ======\n";
       cout << "1. Registrar aerolinea\n";
       cout << "2. Actualizar aerolinea\n";
       cout << "3. Eliminar aerolinea\n";
       cout << "0. Volver\n";

       opcion =
            leerEntero("Opcion: ");

        switch (opcion)
        {
            case 1:
                registrarAerolinea(sistema);
                break;

            case 2:
                actualizarAerolinea(sistema);
                break;
            
            case 3:
                eliminarAerolinea(sistema);
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                break;

        }

    } while (opcion != 0);
    
}

// ============================================================
// CRUD VUELOS
// ============================================================

void registrarVuelo(SistemaAerocivil& sistema)
{
    cout << "\n=== REGISTRAR VUELO ===\n";

    string codigoAerolinea =
        leerTexto("Codigo de la aerolinea: ");

    if (
        sistema.buscarAerolinea(codigoAerolinea)
        == nullptr
    )
    {
        cout << "Aerolinea no encontrada.\n";
        return;
    }

    int dia = leerDia();

    string codigoVuelo =
        leerTexto("Codigo del vuelo: ");

    string origen =
        leerTexto("Origen: ");

    string destino =
        leerTexto("Destino: ");

    string hora =
        leerTexto("Hora: ");

    string modelo =
        leerTexto("Modelo de aeronave: ");

    int capacidad;

    do
    {
        capacidad =
            leerEntero("Capacidad de pasajeros: ");

        if (capacidad <= 0)
        {
            cout << "La capacidad debe ser mayor que 0.\n";
        }

    } while (capacidad <= 0);

    Aeronave aeronave(
        modelo,
        capacidad
    );

    Vuelo vuelo(
        codigoVuelo,
        origen,
        destino,
        hora,
        aeronave
    );

    if (
        sistema.agregarVuelo(
            codigoAerolinea,
            dia,
            vuelo
        )
    )
    {
        cout << "Vuelo registrado correctamente.\n";
    }
    else
    {
        cout << "No se pudo registrar el vuelo.\n";
        cout << "Puede existir otro vuelo con el mismo "
             << "codigo en ese dia.\n";
    }
}


void buscarVueloMenu(SistemaAerocivil& sistema)
{
    cout << "\n=== BUSCAR VUELO ===\n";

    string codigoAerolinea =
        leerTexto("Codigo de la aerolinea: ");

    int dia = leerDia();

    string codigoVuelo =
        leerTexto("Codigo del vuelo: ");

    Vuelo* vuelo =
        sistema.buscarVuelo(
            codigoAerolinea,
            dia,
            codigoVuelo
        );

    if (vuelo == nullptr)
    {
        cout << "Vuelo no encontrado.\n";
        return;
    }

    cout << "\nVuelo encontrado:\n";
    mostrarVuelo(*vuelo);
}


void actualizarVuelo(SistemaAerocivil& sistema)
{
    cout << "\n=== ACTUALIZAR VUELO ===\n";

    string codigoAerolinea =
        leerTexto("Codigo de la aerolinea: ");

    int dia = leerDia();

    string codigoVuelo =
        leerTexto("Codigo actual del vuelo: ");

    Vuelo* vuelo =
        sistema.buscarVuelo(
            codigoAerolinea,
            dia,
            codigoVuelo
        );

    if (vuelo == nullptr)
    {
        cout << "Vuelo no encontrado.\n";
        return;
    }

    cout << "\n1. Cambiar codigo\n";
    cout << "2. Cambiar origen\n";
    cout << "3. Cambiar destino\n";
    cout << "4. Cambiar hora\n";
    cout << "5. Cambiar aeronave\n";
    cout << "0. Cancelar\n";

    int opcion =
        leerEntero("Opcion: ");

    switch (opcion)
    {
        case 1:
        {
            string nuevoCodigo =
                leerTexto("Nuevo codigo: ");

            Vuelo* existente =
                sistema.buscarVuelo(
                    codigoAerolinea,
                    dia,
                    nuevoCodigo
                );

            if (
                existente != nullptr &&
                existente != vuelo
            )
            {
                cout << "Ese codigo ya existe "
                     << "en este dia.\n";

                break;
            }

            vuelo->setCodigo(nuevoCodigo);

            cout << "Codigo actualizado.\n";
            break;
        }

        case 2:
        {
            string origen =
                leerTexto("Nuevo origen: ");

            vuelo->setOrigen(origen);

            cout << "Origen actualizado.\n";
            break;
        }

        case 3:
        {
            string destino =
                leerTexto("Nuevo destino: ");

            vuelo->setDestino(destino);

            cout << "Destino actualizado.\n";
            break;
        }

        case 4:
        {
            string hora =
                leerTexto("Nueva hora (HH:MM): ");

            if (vuelo->setHora(hora))
            {
                cout << "Hora actualizada.\n";
            }
            else
            {
                cout << "Hora invalida. "
                << "Debe usar formato HH:MM entre 00:00 y 23:59.\n";
            }

            break;
        }

        case 5:
        {
            string modelo =
                leerTexto("Nuevo modelo: ");

            int capacidad;

            do
            {
                capacidad =
                    leerEntero(
                        "Nueva capacidad: "
                    );

                if (capacidad <= 0)
                {
                    cout << "La capacidad debe ser "
                         << "mayor que 0.\n";
                }

            } while (capacidad <= 0);

            Aeronave nuevaAeronave(
                modelo,
                capacidad
            );

            vuelo->setAeronave(
                nuevaAeronave
            );

            cout << "Aeronave actualizada.\n";
            cout << "Nueva cantidad de pasajeros: "
                 << vuelo->getCantidadPasajeros()
                 << '\n';

            break;
        }

        case 0:
            cout << "Operacion cancelada.\n";
            break;

        default:
            cout << "Opcion invalida.\n";
            break;
    }
}


void eliminarVueloMenu(SistemaAerocivil& sistema)
{
    cout << "\n=== ELIMINAR VUELO ===\n";

    string codigoAerolinea =
        leerTexto("Codigo de la aerolinea: ");

    int dia = leerDia();

    string codigoVuelo =
        leerTexto("Codigo del vuelo: ");

    if (
        sistema.eliminarVuelo(
            codigoAerolinea,
            dia,
            codigoVuelo
        )
    )
    {
        cout << "Vuelo eliminado correctamente.\n";
    }
    else
    {
        cout << "No se encontro el vuelo.\n";
    }
}


void menuVuelos(SistemaAerocivil& sistema)
{
    int opcion;

    do
    {
        cout << "\n========= ADMINISTRAR VUELOS =========\n";
        cout << "1. Registrar vuelo\n";
        cout << "2. Buscar vuelo\n";
        cout << "3. Actualizar vuelo\n";
        cout << "4. Eliminar vuelo\n";
        cout << "0. Volver\n";

        opcion =
            leerEntero("Opcion: ");

        switch (opcion)
        {
            case 1:
                registrarVuelo(sistema);
                break;

            case 2:
                buscarVueloMenu(sistema);
                break;

            case 3:
                actualizarVuelo(sistema);
                break;

            case 4:
                eliminarVueloMenu(sistema);
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                break;
        }

    } while (opcion != 0);
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    SistemaAerocivil sistema;

    sistema.precargarDatos();

    int opcion;

    do
    {
        cout << "\n=====================================\n";
        cout << "       AEROCIVIL COLOMBIA\n";
        cout << " Aeropuerto Vanguardia - Villavicencio\n";
        cout << "=====================================\n";

        cout << "1. Mostrar informacion del sistema\n";
        cout << "2. Administrar aerolineas\n";
        cout << "3. Administrar vuelos\n";
        cout << "4. Restaurar datos precargados\n";
        cout << "0. Salir\n";

        opcion =
            leerEntero("Opcion: ");

        switch (opcion)
        {
            case 1:
                mostrarSistema(sistema);
                break;

            case 2:
                menuAerolineas(sistema);
                break;

            case 3:
                menuVuelos(sistema);
                break;

            case 4:
                sistema.precargarDatos();

                cout << "Datos precargados restaurados.\n";
                break;

            case 0:
                cout << "Cerrando sistema...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}