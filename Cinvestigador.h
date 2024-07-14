//
// Created by Miguel on 6/07/2024.
//

#ifndef PROYECTO_CINVESTIGADOR_H
#define PROYECTO_CINVESTIGADOR_H

#include <iostream>
#include "Cmaterial.h"
#include "Csolicitud.h"
#include <vector>
using namespace std;

class Cinvestigador
{
private:
    string nombre;
    string apellido;
    string DNI;
    string departamento;
    int cantidadmaterial = 0;
    std::vector<Csolicitud> solicitudes;

public:
    Cinvestigador(string nombre, string apellido, string DNI, string departamento)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->DNI = DNI;
        this->departamento = departamento;
    }

    void agregar(Csolicitud solicitud)
    {
        solicitudes.push_back(solicitud);
    };

    const string &getNombre() {
        return nombre;
    };

    void setNombre(const string &nombre)
    {
        this->nombre= nombre;
    };

    const string &getApellido() 
    {
        return this->apellido;
    }

    void setApellido(const string &apellido)
    {
        this->apellido = apellido;
    };

    const string &getDni(){
        return DNI;
    };

    void setDni(const string &dni)
    {
        this->DNI = dni;
    };

    const string &getDepartamento(){
        return departamento;
    };

    void setDepartamento(const string &departamento)
    {
        this->departamento = departamento;
    };

    int getCantidadmaterial() const{
        return cantidadmaterial;
    };

    void setCantidadmaterial(int cantidadmaterial)
    {
        this->cantidadmaterial = cantidadmaterial;
    };

    const vector<Csolicitud> &getSolicitudes() 
    {
        return this->solicitudes;
    };

    void setSolicitudes(const vector<Csolicitud> _solicitudes){
        this->solicitudes = solicitudes;
    };
};

#endif // PROYECTO_CINVESTIGADOR_H
