//
// Created by Miguel on 6/07/2024.
//

#ifndef PROYECTO_CLABORATORIO_H
#define PROYECTO_CLABORATORIO_H

using namespace std;
#include <iostream>
#include <vector>

#include "Cmaterial.h"
#include "Cinvestigador.h"
#include "Csolicitud.h"

class Claboratorio
{
private:
    string nombre;
    string direccion;
    string codigo;
    vector<Cinvestigador> investigadoresgeneral;
    vector<Cmaterial> materialesgeneral;
    vector<Csolicitud> solicitudesgeneral;

    bool materialExists(Cmaterial param)
    {
      
        for (int i = 0; i < materialesgeneral.size(); i++)
        {
            if (materialesgeneral[i].getNombre() == param.getNombre())
            {
                return true;
            }
        }

        return false;
    };

    bool ResearcherExists(Cinvestigador param)
    {   

        for (int i = 0; i < investigadoresgeneral.size(); i++)
        {
            if (investigadoresgeneral[i].getDni() == param.getDni())
            {
                return true;
            }
        }

        return false;
    }

public:
    Claboratorio(){

    };
    Claboratorio(string nombre, string direccion, string codigo)
    {
        this->nombre = nombre;
        this->direccion = direccion;
        this->codigo = codigo;
    };

    const string &getNombre()
    {
        return this->nombre;
    };

    void setNombre(const string &nombre)
    {
        this->nombre = nombre;
    };

    const string &getDireccion()
    {
        return this->direccion;
    }

    void setDireccion(const string &direccion)
    {
        this->direccion = direccion;
    };

    const string &getCodigo()
    {
        return this->codigo;
    };

    void setCodigo(const string &codigo)
    {
        this->codigo = codigo;
    };

    const vector<Cinvestigador> &getInvestigadoresgeneral()
    {
        return investigadoresgeneral;
    };

    void setInvestigadoresgeneral(const vector<Cinvestigador> &investigadoresgeneral)
    {
        this->investigadoresgeneral = investigadoresgeneral;
    };

    const vector<Cmaterial> &getMaterialesgeneral()
    {
        return materialesgeneral;
    };

    void setMaterialesgeneral(const vector<Cmaterial> &materialesgeneral)
    {
        this->materialesgeneral = materialesgeneral;
    };

    const vector<Csolicitud> &getSolicitudesgeneral()
    {
        return solicitudesgeneral;
    };

    void setSolicitudesgeneral(const vector<Csolicitud> &solicitudesgeneral)
    {
        this->solicitudesgeneral = solicitudesgeneral;
    };

    void agregar(Cinvestigador investigador)
    {
        // Lea la solicitud,
        // Si tiene los materiales ya no los agrega, pero le aumenta la cantidad al laboratorio
        // Caso contrario no tenga los materiales el laboratorio, se añaden automaticamente como sifueran
        // nuevos materiales

        investigadoresgeneral.push_back(investigador);
    };

    void agregar(Cmaterial material)
    {
        // I need to add a function that check if the material was pushed before

        if (materialExists(material) == false)
        {
            materialesgeneral.push_back(material);
            return;
        }
        
        //It's possible improve its funcitionality

        //It's only should be activate when you bring material to our laboratory
        
        for (int i = 0; i < materialesgeneral.size(); i++)
        {
            if(materialesgeneral[i].getNombre() == material.getNombre())
            {
                materialesgeneral[i].setCantidad(materialesgeneral[i].getCantidad() + material.getCantidad());
            }
        }

        return;
    };

    void agregar(Csolicitud solicitud)
    {
        solicitudesgeneral.push_back(solicitud);
    };

    bool existsMaterialPublic(Cmaterial param)
    {
        return materialExists(param);
    }
};

#endif // PROYECTO_CLABORATORIO_H
