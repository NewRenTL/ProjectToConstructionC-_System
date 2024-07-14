//
// Created by Miguel on 6/07/2024.
//

#ifndef PROYECTO_CMATERIAL_H
#define PROYECTO_CMATERIAL_H

#include <iostream>
#include "Cfecha.h"

using namespace std;

class Cmaterial
{
private:
    string nombre, categoria, ID;
    int cantidad = 0;

public:
    Cmaterial(){

    };

    
    Cmaterial(string nombre, string categoria)
    {
        // srand((unsigned int)time(NULL));
        this->nombre = nombre;
        this->categoria = categoria;
        ID = generateCode();
        cout << ID << "<--ID" << endl;
    };

    Cmaterial(string nombre, string categoria, string ID)
    {
        this->nombre = nombre;
        this->categoria = categoria;
        this->ID = ID;
    };

    const string &getNombre()
    {
        return nombre;
    };

    void setNombre(const string &nombre)
    {
        this->nombre = nombre;
    };

    const string &getCategoria()
    {
        return this->categoria;
    }

    void setCategoria(const string &categoria)
    {
        this->categoria = categoria;
    };

    const string &getId()
    {
        return this->ID;
    };

    void setId(const string &id)
    {
        this->ID = id;
    };

    int getCantidad() const
    {
        return this->cantidad;
    }

    void setCantidad(int cantidad)
    {
        this->cantidad = cantidad;
    };

    string generateCode()
    {
        string code = "";
        for (int i = 0; i < 10; ++i)
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
};

#endif // PROYECTO_CMATERIAL_H
