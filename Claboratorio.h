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

    bool ResearcherExists(string dni_param)
    {
        for (auto &&i : investigadoresgeneral)
        {
            if (i.getDni() == dni_param)
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

    void agregar(Cmaterial &material)
    {
        // I need to add a function that check if the material was pushed before

        if (materialExists(material) == false)
        {
            // Si no lo encuentra lo colocamos de frente
            materialesgeneral.push_back(material);
            return;
        }

        // It's possible improve its funcitionality

        // It's only should be activate when you bring material to our laboratory

        // Casi contrario
        // SABIENDO QUE EXISTA, NOS QUEDARIA ACTUALIZAR SU ID, PARA QUE NO SEAN EL MISMO MATERIAL
        //  CON IDS DISTINTOS
        //  Y TAMBIEN A NUESTRO VECTOR DE MATERIALES DE LABORATORIO LE AUMENTAMOS LA CANTIDAD QUE TRAE
        //  EL INVESTIGADOR

        // A NUESTRO MATERIAL QUE TRAE EL INVESTIGADOR NO LE AUMENTAMOS LA CANTIDAD
        // PORQUE ES SOLO QUEDARA COMO UN REGISTRO EN UNA SOLICITUD
        for (int i = 0; i < materialesgeneral.size(); i++)
        {
            if (materialesgeneral[i].getNombre() == material.getNombre())
            {
                material.setId(materialesgeneral[i].getId());
                materialesgeneral[i].setCantidad(materialesgeneral[i].getCantidad() + material.getCantidad());
            }
        }

        return;
    };

    void agregar(Csolicitud solicitud)
    {
        if (solicitud.getTipo() == "PEDIR")
        {
            for (Cmaterial i : solicitud.getMaterialessolicitados())
            {
                for (Cmaterial j : materialesgeneral)
                {
                    if (i.getId() == j.getId())
                    {
                        // Reducimos la cantidad
                        j.setCantidad(j.getCantidad() - i.getCantidad());
                    }
                }
            }
        }
        // Recorremos nuestro vector de materiales de la solicitud

        solicitudesgeneral.push_back(solicitud);
    };

    bool existsMaterialPublic(Cmaterial param)
    {
        return materialExists(param);
    }

    bool existReasearcherByDni(string dni_param)
    {
        return ResearcherExists(dni_param);
    }

    bool existMaterialCodeName(string code, string name)
    {
        for (auto &&i : materialesgeneral)
        {
            if (i.getId() == code | i.getNombre() == name)
            {
                return true;
            }
        }

        return false;
    }

    bool existEnoughAmount(string code, string name, int cant)
    {
        for (auto &&i : materialesgeneral)
        {
            if ((i.getId() == code | i.getNombre() == name) && i.getCantidad() >= cant)
            {
                std::cout << "Hay suficiente" << endl;
                return true;
            }
            else
            {
                std::cout << "No hay suficiente.. Pruebe de nuevo" << endl;
                std::cout << "Cantidad Actual:" << i.getCantidad() << endl;
                return false;
            }
        }
        return false;
    }

    Cinvestigador searchReturnInvestigator(string dni)
    {
        for (auto &&i : investigadoresgeneral)
        {
            if (i.getDni() == dni)
            {
                return i;
            }
        }
    }

    void updateByCodigoAndNameMaterial(string code, string name, Cmaterial &x)
    {
        for (auto &&i : materialesgeneral)
        {
            if (i.getId() == code || i.getNombre() == name)
            {
                x.setCategoria(i.getCategoria());
                x.setNombre(i.getNombre());
                x.setId(i.getId());
            }
        }
    }

    void busquedaByCategory(string nameCategory)
    {
        for (auto &&i : materialesgeneral)
        {
            if (i.getCategoria() == nameCategory)
            {
                std::cout << endl;
                std::cout << "ID:" << i.getId() << endl;
                std::cout << "Material Name:" << i.getNombre() << endl;
                std::cout << "Category Name:" << i.getCategoria() << endl;
                std::cout << "Cantidad:" << i.getCantidad() << endl;
                std::cout << endl;
            }
        }
    }
    void listaMateriales()
    {
        for (auto &&i : materialesgeneral)
        {
            std::cout << endl;
            std::cout << "ID:" << i.getId() << endl;
            std::cout << "Material Name:" << i.getNombre() << endl;
            std::cout << "Category Name:" << i.getCategoria() << endl;
            std::cout << "Cantidad:" << i.getCantidad() << endl;
            std::cout << endl;
        }
    }

    void agregarSolicitudAInvestigator(Csolicitud x, string dni)
    {
        for (auto &&i : investigadoresgeneral)
        {
            if (i.getDni() == dni)
            {
                i.agregar(x);
                return;
            }
        }
        return;
    }

    void busquedaByName(string nameMaterial)
    {
        std::cout<<"Lista Materiales:"<<endl;
        for (auto &&i : materialesgeneral)
        {
            if (i.getNombre() == nameMaterial)
            {
                std::cout << endl;
                std::cout << "ID:" << i.getId() << endl;
                std::cout << "Material Name:" << i.getNombre() << endl;
                std::cout << "Category Name:" << i.getCategoria() << endl;
                std::cout << "Cantidad:" << i.getCantidad() << endl;
                std::cout << endl;
            }
        }
    }
};

#endif // PROYECTO_CLABORATORIO_H
