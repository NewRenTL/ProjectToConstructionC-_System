//
// Created by Miguel on 6/07/2024.
//

#ifndef PROYECTO_CSOLICITUD_H
#define PROYECTO_CSOLICITUD_H
#include <iostream>
#include <vector>
#include "Cmaterial.h"

using namespace std;

enum tipos
{
    TRAER,
    PEDIR,
    DEVOLVER
};

class Csolicitud
{
    //HERENCIA SOLICITUD AUMENTO , SOLICITUD DE USO
private:
    string codigo;
    string DNIinvestigador;
    vector<Cmaterial> materialessolicitados;
    string tipo;
    // TRAER - PEDIR
    // TRAER - CUANDO SE INGRESA UN INVESTIGADOR QUE VIENE CON MATERIAL
    // 1. Se busca el material para verificar que no esta
    // 2. Si no esta el material se agrega, con todo y cantidad
    // 3. Si el material ya no se agrega, pero se suma cantidad
    // PEDIR -
    // 1. El investigador ya logueado
    // 2. Hace una solicitud de una lista de materiales y cantidad
    // 3. Cada material que vaya ingresando, se verificara si cumple con la cantidad
    // solicitada.
    // 4. Si no cumple se le avisara, (podria salir una opción para traer todo el material)
    // 5. Si tiene cantidad solicitada en laboratorio , normal se añade a la solicitud
    //

    string generateCode()
    {
        string code = "";
        for (int i = 0; i < 5; ++i)
        {
            if (i < 3)
            {
                code += 60 + (rand() % 31);
            }
            else
            {
                code += 48 + (rand() % 10);
            }
        }
        return code;
    };

public:
    Csolicitud(string DNIinvestigador, vector<Cmaterial> materialessolicitados, string tipo)
    {
        this->codigo = generateCode();
        this->DNIinvestigador = DNIinvestigador;
        this->materialessolicitados = materialessolicitados;
        this->tipo = tipo;
    };

    const string &getCodigo()
    {
        return codigo;
    };

    void setCodigo(const string &codigo)
    {
        this->codigo = codigo;
    };

    const string &getDnIinvestigador() {
        return DNIinvestigador;
    };

    void setDnIinvestigador(const string &dnIinvestigador)
    {
        this->DNIinvestigador = dnIinvestigador;
    };

    const vector<Cmaterial> &getMaterialessolicitados()
    {
        return materialessolicitados;
    };

    void setMaterialessolicitados(const vector<Cmaterial> &materialessolicitados)
    {
        this->materialessolicitados = materialessolicitados;
    };

    const string &getTipo() {
        return this->tipo;
    };

    void setTipo(const string &tipo)
    {
        this->tipo = tipo;
    };
};

#endif // PROYECTO_CSOLICITUD_H
