//
// Created by Miguel on 6/07/2024.
//

#ifndef PROYECTO_CFECHA_H
#define PROYECTO_CFECHA_H

#include <iostream>

using namespace std;

class Cfecha
{
private:
    int dia;
    int mes;
    int ano;

public:
    Cfecha(int dia, int mes)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = 2024;
    };

    Cfecha(int dia, int mes, int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    };

    int getDia() const
    {
        return dia;
    };

    void setDia(int dia)
    {
        this->dia = dia;
    };

    int getMes() const
    {
        return mes;
    };

    void setMes(int mes)
    {
        this->mes = mes;
    };

    int getAno() const
    {
        return ano;
    };

    void setAno(int ano)
    {
        this->ano = ano;
    };
};

#endif // PROYECTO_CFECHA_H
