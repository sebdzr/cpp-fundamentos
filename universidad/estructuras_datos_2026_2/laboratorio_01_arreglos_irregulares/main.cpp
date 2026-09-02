#include "SistemaAerocivil.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// ============================================================
// ENTRADAS SEGURAS
// ============================================================

class FinDeEntrada
{
};

string leerLinea(const string& mensaje)
{
    cout << mensaje;

    string entrada;

    if (!getline(cin, entrada))
    {
        throw FinDeEntrada();
    }

    return entrada;
}

string recortar(const string& texto)
{
    size_t inicio = 0;

    while (
        inicio < texto.length() &&
        isspace(static_cast<unsigned char>(texto[inicio]))
    )
    {
        inicio++;
    }

    size_t fin = texto.length();

    while (
        fin > inicio &&
        isspace(static_cast<unsigned char>(texto[fin - 1]))
    )
    {
        fin--;
    }

    return texto.substr(inicio, fin - inicio);
}

int leerEntero(const string& mensaje)
{
    while (true)
    {
        string entrada = recortar(leerLinea(mensaje));

        stringstream ss(entrada);
        int valor;

        if (ss >> valor)
        {
            ss >> ws;

            if (ss.eof())
            {
                return valor;
            }
        }

        cout << "Entrada invalida. Escriba un numero entero, "
             << "sin letras ni decimales.\n";
    }
}

string leerTexto(const string& mensaje)
{
    while (true)
    {
        string texto = recortar(leerLinea(mensaje));

        if (!texto.empty())
        {
            return texto;
        }

        cout << "Entrada vacia. Escriba al menos un caracter.\n";
    }
}

int leerOpcionEnRango(
    const string& mensaje,
    int minimo,
    int maximo
)
{
    while (true)
    {
        int opcion = leerEntero(mensaje);

        if (opcion >= minimo && opcion <= maximo)
        {
            return opcion;
        }

        cout << "Opcion fuera de rango. Escriba un numero entre "
             << minimo
             << " y "
             << maximo
             << ".\n";
    }
}

int leerDia()
{
    cout << "\nDias disponibles:\n";
    cout << "1. Lunes\n";
    cout << "2. Martes\n";
    cout << "3. Miercoles\n";
    cout << "4. Jueves\n";
    cout << "5. Viernes\n";
    cout << "6. Sabado\n";
    cout << "7. Domingo\n";

    return leerOpcionEnRango(
        "Escriba el numero del dia (1-7): ",
        1,
        7
    ) - 1;
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
    cout << "\n=== AERONAVES DISPONIBLES ===\n";
    cout << "1. ATR 42 - 48 pasajeros\n";
    cout << "2. ATR 72-600 - 70 pasajeros\n";

    int opcion = leerOpcionEnRango(
        "Escriba 1 o 2 para seleccionar la aeronave: ",
        1,
        2
    );

    if (opcion == 1)
    {
        return Aeronave("ATR 42", 48);
    }

    return Aeronave("ATR 72-600", 70);
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
    codigo = recortar(codigo);

    for (char& c : codigo)
    {
        c = toupper(static_cast<unsigned char>(c));
    }

    return codigo;
}

bool codigoValido(const string& codigo)
{
    if (codigo.empty())
    {
        return false;
    }

    for (char c : codigo)
    {
        if (!isalnum(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }

    return true;
}

string leerCodigo(const string& mensaje)
{
    while (true)
    {
        string codigo =
            normalizarCodigo(leerTexto(mensaje));

        if (codigoValido(codigo))
        {
            return codigo;
        }

        cout << "Codigo invalido. Escriba solo letras y numeros, "
             << "sin espacios ni simbolos. Ejemplo: AV4809.\n";
    }
}

string normalizarParaComparar(string texto)
{
    texto = recortar(texto);

    for (char& c : texto)
    {
        c = toupper(static_cast<unsigned char>(c));
    }

    return texto;
}

bool mismaUbicacion(const string& primera, const string& segunda)
{
    return normalizarParaComparar(primera) ==
           normalizarParaComparar(segunda);
}

bool confirmarOperacion(const string& advertencia)
{
    cout << "\nADVERTENCIA: " << advertencia << '\n';
    cout << "1. Confirmar\n";
    cout << "0. Cancelar\n";

    return leerOpcionEnRango(
        "Escriba 1 para confirmar o 0 para cancelar: ",
        0,
        1
    ) == 1;
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

bool mostrarAerolineasDisponibles(
    const SistemaAerocivil& sistema
)
{
    cout << "\n=== AEROLINEAS DISPONIBLES ===\n";

    if (sistema.getCantidadAerolineas() == 0)
    {
        cout << "No hay aerolineas registradas.\n";
        return false;
    }

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
            cout << "- "
                 << aerolinea->getCodigo()
                 << " | "
                 << aerolinea->getNombre()
                 << '\n';
        }
    }

    return true;
}

Aerolinea* seleccionarAerolinea(
    SistemaAerocivil& sistema,
    const string& accion
)
{
    if (!mostrarAerolineasDisponibles(sistema))
    {
        return nullptr;
    }

    string codigo = leerCodigo(
        "Escriba el codigo de la aerolinea que desea " +
        accion +
        ": "
    );

    Aerolinea* aerolinea =
        sistema.buscarAerolinea(codigo);

    if (aerolinea == nullptr)
    {
        cout << "No existe una aerolinea con el codigo "
             << codigo
             << ". Revise la lista mostrada.\n";
    }

    return aerolinea;
}

int contarVuelos(const Aerolinea& aerolinea)
{
    int total = 0;

    for (int dia = 0; dia < 7; dia++)
    {
        total += aerolinea.getCantidadVuelos(dia);
    }

    return total;
}

// ============================================================
// CRUD AEROLINEAS
// ============================================================

void registrarAerolinea(SistemaAerocivil& sistema)
{
    cout << "\n=== REGISTRAR AEROLINEA ===\n";

    mostrarAerolineasDisponibles(sistema);

    string nombre =
        leerTexto("Escriba el nombre de la nueva aerolinea: ");

    string codigo =
        leerCodigo(
            "Escriba su codigo alfanumerico. Ejemplo: AV: "
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

    Aerolinea* aerolinea =
        seleccionarAerolinea(sistema, "actualizar");

    if (aerolinea == nullptr)
    {
        return;
    }

    cout << "\n1. Cambiar nombre\n";
    cout << "2. Cambiar codigo\n";
    cout << "0. Cancelar\n";

    int opcion =
        leerOpcionEnRango(
            "Escriba una opcion entre 0 y 2: ",
            0,
            2
        );

    switch (opcion)
    {
        case 1:
        {
            string nuevoNombre =
                leerTexto("Escriba el nuevo nombre: ");

            aerolinea->setNombre(nuevoNombre);

            cout << "Nombre actualizado.\n";
            break;
        }

        case 2:
        {
            string nuevoCodigo =
                leerCodigo(
                    "Escriba el nuevo codigo alfanumerico: "
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
    }
}

void eliminarAerolinea(SistemaAerocivil& sistema)
{
    cout << "\n=== ELIMINAR AEROLINEA ===\n";

    Aerolinea* aerolinea =
        seleccionarAerolinea(sistema, "eliminar");

    if (aerolinea == nullptr)
    {
        return;
    }

    string codigo = aerolinea->getCodigo();
    string nombre = aerolinea->getNombre();
    int cantidadVuelos = contarVuelos(*aerolinea);

    cout << "\nSeleccionada: "
         << nombre
         << " ("
         << codigo
         << "), con "
         << cantidadVuelos
         << " vuelo(s).\n";

    if (!confirmarOperacion(
        "se eliminara la aerolinea y todos sus vuelos."
    ))
    {
        cout << "Operacion cancelada. No se elimino la aerolinea.\n";
        return;
    }

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

Vuelo* seleccionarVuelo(
    Aerolinea& aerolinea,
    int dia,
    const string& accion
)
{
    mostrarVuelosDisponibles(aerolinea, dia);

    if (aerolinea.getCantidadVuelos(dia) == 0)
    {
        return nullptr;
    }

    string codigoVuelo = leerCodigo(
        "Escriba el codigo del vuelo que desea " +
        accion +
        ": "
    );

    Vuelo* vuelo =
        aerolinea.buscarVuelo(dia, codigoVuelo);

    if (vuelo == nullptr)
    {
        cout << "No existe el vuelo "
             << codigoVuelo
             << " para "
             << nombreDia(dia)
             << " en la aerolinea "
             << aerolinea.getCodigo()
             << ". Revise la lista mostrada.\n";
    }

    return vuelo;
}

string leerUbicacionDiferente(
    const string& mensaje,
    const string& otraUbicacion
)
{
    while (true)
    {
        string ubicacion = leerTexto(mensaje);

        if (!mismaUbicacion(ubicacion, otraUbicacion))
        {
            return ubicacion;
        }

        cout << "Origen y destino no pueden ser iguales, "
             << "aunque cambien mayusculas o espacios.\n";
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
            leerOpcionEnRango(
                "Escriba una opcion entre 0 y 3: ",
                0,
                3
            );

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
        }

    } while (opcion != 0);
    
}

// ============================================================
// CRUD VUELOS
// ============================================================

void registrarVuelo(SistemaAerocivil& sistema)
{
    cout << "\n=== REGISTRAR VUELO ===\n";

    Aerolinea* aerolinea =
        seleccionarAerolinea(sistema, "usar");

    if (aerolinea == nullptr)
    {
        return;
    }

    string codigoAerolinea = aerolinea->getCodigo();

    int dia = leerDia();

    string codigoVuelo;

    while (true)
    {
        codigoVuelo = leerCodigo(
            "Escriba el codigo del nuevo vuelo. Ejemplo: AV4809: "
        );

        if (aerolinea->buscarVuelo(dia, codigoVuelo) == nullptr)
        {
            break;
        }

        cout << "El codigo "
             << codigoVuelo
             << " ya existe para "
             << nombreDia(dia)
             << ". Escriba uno diferente.\n";
    }

    string origen =
        leerTexto(
            "Escriba el origen. Ejemplo: Villavicencio (VVC): "
        );

    string destino =
        leerUbicacionDiferente(
            "Escriba el destino. Ejemplo: Bogota (BOG): ",
            origen
        );

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
        cout << "No se pudo registrar el vuelo. "
             << "La aerolinea, el dia o el codigo dejaron "
             << "de ser validos.\n";
    }
}


void buscarVueloMenu(SistemaAerocivil& sistema)
{
    cout << "\n=== BUSCAR VUELO ===\n";

    Aerolinea* aerolinea =
        seleccionarAerolinea(sistema, "consultar");

    if (aerolinea == nullptr)
    {
        return;
    }

    int dia = leerDia();

    Vuelo* vuelo =
        seleccionarVuelo(*aerolinea, dia, "consultar");

    if (vuelo == nullptr)
    {
        return;
    }

    cout << "\nVuelo encontrado:\n";
    mostrarVuelo(*vuelo);
}


void actualizarVuelo(SistemaAerocivil& sistema)
{
    cout << "\n=== ACTUALIZAR VUELO ===\n";

    Aerolinea* aerolinea =
        seleccionarAerolinea(sistema, "usar");

    if (aerolinea == nullptr)
    {
        return;
    }

    int dia = leerDia();

    Vuelo* vuelo =
        seleccionarVuelo(*aerolinea, dia, "actualizar");

    if (vuelo == nullptr)
    {
        return;
    }

    cout << "\n1. Cambiar codigo\n";
    cout << "2. Cambiar origen\n";
    cout << "3. Cambiar destino\n";
    cout << "4. Cambiar hora\n";
    cout << "5. Cambiar aeronave\n";
    cout << "0. Cancelar\n";

    int opcion =
        leerOpcionEnRango(
            "Escriba una opcion entre 0 y 5: ",
            0,
            5
        );

    switch (opcion)
    {
        case 1:
        {
            string nuevoCodigo;

            while (true)
            {
                nuevoCodigo = leerCodigo(
                    "Escriba el nuevo codigo alfanumerico: "
                );

                Vuelo* existente =
                    aerolinea->buscarVuelo(dia, nuevoCodigo);

                if (existente == nullptr || existente == vuelo)
                {
                    break;
                }

                cout << "El codigo "
                     << nuevoCodigo
                     << " ya pertenece a otro vuelo de "
                     << nombreDia(dia)
                     << ". Escriba uno diferente.\n";
            }

            vuelo->setCodigo(nuevoCodigo);

            cout << "Codigo actualizado.\n";
            break;
        }

        case 2:
        {
            string origen =
                leerUbicacionDiferente(
                    "Escriba el nuevo origen: ",
                    vuelo->getDestino()
                );

            vuelo->setOrigen(origen);

            cout << "Origen actualizado.\n";
            break;
        }

        case 3:
        {
            string destino =
                leerUbicacionDiferente(
                    "Escriba el nuevo destino: ",
                    vuelo->getOrigen()
                );

            vuelo->setDestino(destino);

            cout << "Destino actualizado.\n";
            break;
        }

        case 4:
        {
            string hora =
                leerHoraValida();

            vuelo->setHora(hora);

            cout << "Hora actualizada.\n";

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
    }
}


void eliminarVueloMenu(SistemaAerocivil& sistema)
{
    cout << "\n=== ELIMINAR VUELO ===\n";

    Aerolinea* aerolinea =
        seleccionarAerolinea(sistema, "usar");

    if (aerolinea == nullptr)
    {
        return;
    }

    int dia = leerDia();

    Vuelo* vuelo =
        seleccionarVuelo(*aerolinea, dia, "eliminar");

    if (vuelo == nullptr)
    {
        return;
    }

    string codigoAerolinea = aerolinea->getCodigo();
    string codigoVuelo = vuelo->getCodigo();

    cout << "\nVuelo seleccionado:\n";
    mostrarVuelo(*vuelo);

    if (!confirmarOperacion(
        "se eliminara definitivamente el vuelo seleccionado."
    ))
    {
        cout << "Operacion cancelada. No se elimino el vuelo.\n";
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
    else
    {
        cout << "No se pudo eliminar el vuelo porque ya no existe.\n";
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
            leerOpcionEnRango(
                "Escriba una opcion entre 0 y 4: ",
                0,
                4
            );

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
        }

    } while (opcion != 0);
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    try
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
                leerOpcionEnRango(
                    "Escriba una opcion entre 0 y 4: ",
                    0,
                    4
                );

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
                    if (confirmarOperacion(
                        "se perderan todas las modificaciones actuales."
                    ))
                    {
                        sistema.precargarDatos();

                        cout << "Datos precargados restaurados.\n";
                    }
                    else
                    {
                        cout << "Operacion cancelada. "
                             << "Los datos no cambiaron.\n";
                    }

                    break;
                }

                case 0:
                    cout << "Cerrando sistema...\n";
                    break;
            }

        } while (opcion != 0);
    }
    catch (const FinDeEntrada&)
    {
        cout << "\nFin de entrada detectado. "
             << "La operacion pendiente fue cancelada.\n";
        cout << "Cerrando sistema...\n";
    }

    return 0;
}
