#include "SistemaAerocivil.h"

using namespace std;

SistemaAerocivil::SistemaAerocivil()
    : aerolineas(nullptr),
      cantidadAerolineas(0)
{
}

SistemaAerocivil::~SistemaAerocivil()
{
    liberarMemoria();
}

void SistemaAerocivil::liberarMemoria()
{
    delete[] aerolineas;

    aerolineas = nullptr;
    cantidadAerolineas = 0;
}

int SistemaAerocivil::getCantidadAerolineas() const
{
    return cantidadAerolineas;
}

int SistemaAerocivil::buscarIndiceAerolinea(
    const string& codigo
) const
{
    for(int i=0; i < cantidadAerolineas; i++)
    {
        if(aerolineas[i].getCodigo() == codigo)
        {
            return i;
        }
    }

    return -1;
}

Aerolinea* SistemaAerocivil::buscarAerolinea(
    const string& codigo
)
{
    int indice = buscarIndiceAerolinea(codigo);

    if(indice == -1)
    {
        return nullptr;
    }

    return &aerolineas[indice];
}

const Aerolinea* SistemaAerocivil::buscarAerolinea(
    const string& codigo
) const
{
    int indice = buscarIndiceAerolinea(codigo);

    if (indice == -1)
    {
        return nullptr;
    }

    return &aerolineas[indice];

}

bool SistemaAerocivil::agregarAerolinea(
    const Aerolinea& aerolinea
)
{
    if (buscarAerolinea(aerolinea.getCodigo()) != nullptr)
    {
        return false;
    }

    Aerolinea* nuevoArreglo =
        new Aerolinea[cantidadAerolineas + 1];

    for(int i = 0; i < cantidadAerolineas; i++)
    {
        nuevoArreglo[i] = aerolineas[i];
    }

    nuevoArreglo[cantidadAerolineas] = aerolinea;

    delete[] aerolineas;

    aerolineas = nuevoArreglo;
    cantidadAerolineas++;

    return true;
}

bool SistemaAerocivil::eliminarAerolinea(
    const string& codigo
)
{
    int indiceEliminar = buscarIndiceAerolinea(codigo);

    if (indiceEliminar == -1)
    {
        return false;
    }

    if(cantidadAerolineas == 1)
    {
        delete[] aerolineas;

        aerolineas = nullptr;
        cantidadAerolineas = 0;

        return true;
    }

    Aerolinea* nuevoArreglo =
        new Aerolinea[cantidadAerolineas -1];

    int j = 0;

    for (int i = 0; i < cantidadAerolineas; i++)
    {
        if (i != indiceEliminar)
        {
            nuevoArreglo[j] = aerolineas[i];
            j++;
        }
    }

    delete[] aerolineas;

    aerolineas = nuevoArreglo;
    cantidadAerolineas--;

    return true;
}

Aerolinea* SistemaAerocivil::getAerolinea(int indice)
{
    if(indice < 0 || indice >= cantidadAerolineas)
    {
        return nullptr;
    }

    return &aerolineas[indice];
}

const Aerolinea* SistemaAerocivil::getAerolinea(int indice) const
{
    if (indice < 0 || indice >= cantidadAerolineas)
    {
        return nullptr;
    }

    return &aerolineas[indice];
}

bool SistemaAerocivil::agregarVuelo(
    const string& codigoAerolinea,
    int dia,
    const Vuelo& vuelo
)
{
    Aerolinea* aerolinea =
        buscarAerolinea(codigoAerolinea);

    if (aerolinea == nullptr)
    {
        return false;
    }

    return aerolinea -> agregarVuelo(dia, vuelo);
}

bool SistemaAerocivil::eliminarVuelo(
    const string& codigoAerolinea,
    int dia,
    const string& codigoVuelo
)
{
    Aerolinea* aerolinea =
        buscarAerolinea(codigoAerolinea);

    if (aerolinea == nullptr)
    {
        return false;
    }

    return aerolinea -> eliminarVuelo(
        dia,
        codigoVuelo
    );

}

Vuelo* SistemaAerocivil::buscarVuelo(
    const string& codigoAerolinea,
    const string& codigoVuelo
)
{
    Aerolinea* aerolinea =
        buscarAerolinea(codigoAerolinea);
    
    if (aerolinea == nullptr)
    {
        return nullptr;
    }

    return aerolinea -> buscarVuelo(codigoVuelo);
}

const Vuelo* SistemaAerocivil::buscarVuelo(
    const string& codigoAerolinea,
    const string& codigoVuelo
) const
{
    const Aerolinea* aerolinea =
        buscarAerolinea(codigoAerolinea);
    
    if (aerolinea == nullptr)
    {
        return nullptr;
    }

    return aerolinea -> buscarVuelo(codigoVuelo);
}

Vuelo* SistemaAerocivil::buscarVuelo(
    const string& codigoAerolinea,
    int dia,
    const string& codigoVuelo
)
{
    Aerolinea* aerolinea = 
        buscarAerolinea(codigoAerolinea);
    
    if (aerolinea == nullptr)
    {
        return nullptr;
    }

    return aerolinea -> buscarVuelo(
        dia,
        codigoVuelo
    );
}

const Vuelo* SistemaAerocivil::buscarVuelo(
    const string& codigoAerolinea,
    int dia,
    const string& codigoVuelo
) const
{
    const Aerolinea* aerolinea =
        buscarAerolinea(codigoAerolinea);

    if (aerolinea == nullptr)
    {
        return nullptr;
    }

    return aerolinea->buscarVuelo(
        dia,
        codigoVuelo
    );
}

void SistemaAerocivil::copiarDesde(
    const SistemaAerocivil& otro
)
{
    cantidadAerolineas = otro.cantidadAerolineas;

    if (cantidadAerolineas == 0)
    {
        aerolineas = nullptr;
        return;
    }

    aerolineas = new Aerolinea[cantidadAerolineas];

    for (int i = 0; i < cantidadAerolineas; i++)
    {
        aerolineas[i] = otro.aerolineas[i];
    }
}

SistemaAerocivil::SistemaAerocivil(
    const SistemaAerocivil& otro
)
    : aerolineas(nullptr),
      cantidadAerolineas(0)
{
    copiarDesde(otro);
}

SistemaAerocivil&
SistemaAerocivil::operator=(
    const SistemaAerocivil& otro
)
{
    if (this != &otro)
    {
        liberarMemoria();
        copiarDesde(otro);
    }

    return *this;
}

void SistemaAerocivil::precargarDatos()
{
    liberarMemoria();

    Aerolinea avianca(
        "Avianca Express",
        "AV"
    );

    Aerolinea clic(
        "Clic Air",
        "VE"
    );

    Aerolinea satena(
        "SATENA",
        "9R"
    );

    agregarAerolinea(avianca);
    agregarAerolinea(clic);
    agregarAerolinea(satena);

    Aeronave atr72(
        "ATR 72-600",
        70
    );

    Aeronave atr42(
        "ATR 42",
        48
    );

    // =========================
    // AVIANCA EXPRESS
    // VVC -> BOG
    // =========================

    for(int dia = 0; dia < 7; dia++)
    {
        agregarVuelo(
            "AV",
            dia,
            Vuelo(
                "AV4809",
                "Villavicencio (VVC)",
                "Bogota (BOG)",
                "7:55",
                atr72
            )
        );

        agregarVuelo(
            "AV",
            dia,
            Vuelo(
                "AV4881",
                "Villavicencio (VVC)",
                "Bogota (BOG)",
                "11:35",
                atr72
            )
        );

        agregarVuelo(
            "AV",
            dia,
            Vuelo(
                "AV4827",
                "Villavicencio (VVC)",
                "Bogota (BOG)",
                "15:25",
                atr72
            )
        );
    }
       
    // =========================
    // CLIC AIR
    // =========================     
            
    agregarVuelo(
        "VE",
        0,
        Vuelo(
            "VE7881",
            "Villavicencio (VVC)",
            "Bogota (BOG)",
            "10:50",
            atr42
        )
    );

    agregarVuelo(
        "VE",
        4,
        Vuelo(
            "VE7881",
            "Villavicencio (VVC)",
            "Bogota (BOG)",
            "15:25",
            atr42
        )
    );

    agregarVuelo(
        "VE",
        0,
        Vuelo(
            "VE7821",
            "Villavicencio (VVC)",
            "Medellin (EOH)",
            "10:15",
            atr42
        )
    );

    agregarVuelo(
        "VE",
        2,
        Vuelo(
            "VE7821",
            "Villavicencio (VVC)",
            "Medellin (EOH)",
            "10:15",
            atr42
        )
    );

    agregarVuelo(
        "VE",
        4,
        Vuelo(
            "VE7821",
            "Villavicencio (VVC)",
            "Medellin (EOH)",
            "10:25",
            atr42
        )
    );


    // =========================
    // SATENA
    // VVC -> BOG
    // =========================

    agregarVuelo(
        "9R",
        0,
        Vuelo(
            "9R8883",
            "Villavicencio (VVC)",
            "Bogota (BOG)",
            "16:40",
            atr72
        )
    );

    agregarVuelo(
        "9R",
        1,
        Vuelo(
            "9R8883",
            "Villavicencio (VVC)",
            "Bogota (BOG)",
            "17:10",
            atr72
        )
    );

    agregarVuelo(
        "9R",
        2,
        Vuelo(
            "9R8883",
            "Villavicencio (VVC)",
            "Bogota (BOG)",
            "16:42",
            atr72
        )
    );

    agregarVuelo(
        "9R",
        3,
        Vuelo(
            "9R8883",
            "Villavicencio (VVC)",
            "Bogota (BOG)",
            "15:55",
            atr72
        )
    );

    agregarVuelo(
        "9R",
        4,
        Vuelo(
            "9R8883",
            "Villavicencio (VVC)",
            "Bogota (BOG)",
            "15:42",
            atr72
        )
    );
}