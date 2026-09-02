#include "SistemaAerocivil.h"

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// ============================================================
// ENTRADAS SEGURAS
// ============================================================

int leerEntero(const string& mensaje)
{
   while(true)
   {
        cout << mensaje;

        string entrada;
        getline(cin, entrada);

        stringstream ss(entrada);

        int valor;

        if(ss >> valor)
        {
            ss >> ws;

            if(ss.eof())
            {
                return valor;
            }
        }

        cout << "Entrada invalida. Ingrese un numero entero. \n";
   }
}

string leerTexto(const string& mensaje)
{
    while (true)
    {
        cout << mensaje;

        string texto;
        getline(cin, texto);

        bool tieneContenido = false;

        for (char c : texto)
        {
            if (!isspace(static_cast<unsigned char>(c)))
            {
                tieneContenido = true;
                break;
            }
        }

        if (tieneContenido)
        {
            return texto;
        }

        cout << "El texto no puede estar vacio.\n";
    }
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

Aeronave seleccionarAeronave()
{
    int opcion;

    do
    {
        cout << "\n=== AERONAVES DISPONIBLES ===\n";
        cout << "1. ATR 42 - 48 pasajeros\n";
        cout << "2. ATR 72-600 - 70 pasajeros\n";

        opcion = leerEntero("Seleccione una aeronave: ");

        switch (opcion)
        {
            case 1:
                return Aeronave("ATR 42", 48);

            case 2:
                return Aeronave("ATR 72-600", 70);

            default:
                cout << "Aeronave invalida. Intente nuevamente.\n";
                break;
        }
    } while (true);

}

string leerHoraValida()
{
    while (true)
    {
        string hora =
            leerTexto("Hora (HH:MM): ");

        Vuelo prueba;

        if (prueba.setHora(hora))
        {
            return hora;
        }

        cout << "Hora invalida. "
             << "Use formato HH:MM entre 00:00 y 23:59.\n";
    }
}

string normalizarCodigo(string codigo)
{
    for (char& c : codigo)
    {
        c = toupper(static_cast<unsigned char>(c));
    }

    return codigo;
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
        normalizarCodigo(
            leerTexto("Codigo: ")
    );
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
        normalizarCodigo(
            leerTexto("Codigo actual: ")
        );

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
                normalizarCodigo(
                    leerTexto("Nuevo codigo: ")
                );

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

void mostrarVuelosDisponibles(
    const Aerolinea& aerolinea,
    int dia
)
{
    int cantidad =
        aerolinea.getCantidadVuelos(dia);

    cout << "\n=== VUELOS DISPONIBLES ===\n";

    if (cantidad == 0)
    {
        cout << "No hay vuelos registrados para este dia.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++)
    {
        const Vuelo* vuelo =
            aerolinea.getVuelo(dia, i);

        if (vuelo != nullptr)
        {
            cout << i + 1 << ". "
                 << vuelo->getCodigo()
                 << " | "
                 << vuelo->getOrigen()
                 << " -> "
                 << vuelo->getDestino()
                 << " | "
                 << vuelo->getHora()
                 << '\n';
        }
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

     string codigoAerolinea = normalizarCodigo
    (
        leerTexto
        (
            "Codigo de la aerolinea "
            "(Avianca = AV, Clic = VE, Satena = 9R): "
        )
    );

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
        normalizarCodigo(
            leerTexto("Codigo del vuelo: ")
    );

    string origen =
        leerTexto("Origen: ");

    string destino =
        leerTexto("Destino: ");

    while (destino == origen)
    {
        cout << "El destino no puede ser igual al origen.\n";

        destino =
            leerTexto("Destino: ");
    }

    string hora =
        leerHoraValida();

    Aeronave aeronave = seleccionarAeronave();

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

    string codigoAerolinea = normalizarCodigo
    (
        leerTexto
        (
            "Codigo de la aerolinea "
            "(Avianca = AV, Clic = VE, Satena = 9R): "
        )
    );

    Aerolinea* aerolinea =
        sistema.buscarAerolinea(codigoAerolinea);

    if (aerolinea == nullptr)
    {
        cout << "Aerolinea no encontrada.\n";
        return;
    }

    int dia = leerDia();

    mostrarVuelosDisponibles(
        *aerolinea,
        dia
    );

    if (aerolinea->getCantidadVuelos(dia) == 0)
    {
        return;
    }

    string codigoVuelo =
        normalizarCodigo(
        leerTexto("Codigo del vuelo que desea buscar: ")
    );

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
   string codigoAerolinea =
    normalizarCodigo(
        leerTexto(
            "Codigo de la aerolinea "
            "(Avianca = AV, Clic = VE, Satena = 9R): "
        )
    );

    Aerolinea* aerolinea =
        sistema.buscarAerolinea(codigoAerolinea);

    if (aerolinea == nullptr)
    {
        cout << "Aerolinea no encontrada.\n";
        return;
    }

    int dia = leerDia();

    mostrarVuelosDisponibles(*aerolinea, dia);

    if (aerolinea->getCantidadVuelos(dia) == 0)
    {
        return;
    }

    string codigoVuelo =
        normalizarCodigo(
        leerTexto("Codigo del vuelo a actualizar: ")
    );

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
            Aeronave nuevaAeronave =
                seleccionarAeronave();

            vuelo -> setAeronave(nuevaAeronave);

            cout << "Aeronave actualizada.\n";

            cout << "Nueva cantidad de pasajeros: "
                 << vuelo -> getCantidadPasajeros()
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
        normalizarCodigo(
            leerTexto(
                "Codigo de la aerolinea "
                "(Avianca = AV, Clic = VE, Satena = 9R): "
            )
        );

    Aerolinea* aerolinea =
        sistema.buscarAerolinea(codigoAerolinea);

    if (aerolinea == nullptr)
    {
        cout << "Aerolinea no encontrada.\n";
        return;
    }

    int dia = leerDia();

    mostrarVuelosDisponibles(*aerolinea, dia);

    if (aerolinea->getCantidadVuelos(dia) == 0)
    {
        return;
    }

    string codigoVuelo =
        normalizarCodigo(
            leerTexto("Codigo del vuelo a eliminar: ")
        );

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

    cout << "\nVuelo seleccionado:\n";
    mostrarVuelo(*vuelo);

    cout << "\n1. Confirmar eliminacion\n";
    cout << "0. Cancelar\n";

    int confirmar =
        leerEntero("Opcion: ");

    if (confirmar != 1)
    {
        cout << "Operacion cancelada.\n";
        return;
    }

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

            {
                cout << "Esta opcion eliminara los cambios actuales.\n";
                cout << "1. Restaurar datos\n";
                cout << "0. Cancelar\n";

                int confirmar =
                    leerEntero("Opcion: ");

                if (confirmar == 1)
                {
                    sistema.precargarDatos();

                    cout << "Datos precargados restaurados.\n";
                }
                else
                {
                    cout << "Operacion cancelada.\n";
                }

                break;

            }
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
