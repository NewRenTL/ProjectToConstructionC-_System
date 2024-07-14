
#ifndef PROYECTO_CSYSTEM
#define PROYECTO_CSYSTEM
#include "Claboratorio.h"
#include "Cinvestigador.h"
#include "string"
class CSystem
{
private:
    Claboratorio *clab;

    int menuPrincipal()
    {
        std::cout << "-- Menu Principal --" << std::endl;
        std::cout << "(1) Crear Material" << endl;
        std::cout << "(2) Crear Investigador" << endl;
        std::cout << "(3) Ingresar (Investigador)" << endl;
        std::cout << "(4) Salir" << endl;
        int x = -1;
        std::cout << "Ingrese la opcion:";
        std::cin >> x;
        return x;
    };

    void creationMaterial()
    {
        std::cin.ignore();
        std::string paramName, category;
        std::cout << "Enter your material name:";
        getline(cin, paramName);
        std::cout << "Enter your category name:";
        getline(cin, paramName);
        std::cout << "Creation...Construction" << std::endl;
        Cmaterial newMaterial(paramName, category);
        clab->agregar(newMaterial);
        std::cout << "Your material was added to our laboratory" << std::endl;

        return;
    };

    int creationResearcher()
    {
        cin.ignore();
        std::string paramName, paramLastname, paramDNI, paramDepartment;
        std::cout << "Enter reasearcher name:";
        getline(cin, paramName);
        std::cout << "Enter researcher lastname:";
        getline(cin, paramLastname);
        std::cout << "Enter researcher DNI:";
        std::cin >> paramDNI;
        std::cin.ignore();
        std::cout << "Enter researcher department:";
        getline(cin, paramDepartment);
        std::cout << "Creation Researcher..." << std::endl;
        Cinvestigador c1(paramName, paramLastname, paramDNI, paramDepartment);
        // Tienes materiales?
        // te explique que materiales
        // esos materiales -> solicitud
        // enviar el investigador (el investigador 1 solicitud)
        bool youHaveMaterial = false;
        char y_n = 'n';
        std::cout << "Do you have material to add to our laboratory?((Y/n)):";
        std::cin >> y_n;

        if (toupper(y_n) == 'Y')
        {
            std::vector<Cmaterial> listMaterial;
            while (true)
            {
                std::cin.ignore();
                std::string nameMaterial, category;
                std::cout << "Enter your material name:";
                getline(cin,nameMaterial);
                std::cout << "Enter your category name:";
                getline(cin, paramName);
                int cantMaterial;
                std::cout << "How many material do you have?:";
                std::cin>>cantMaterial;
                std::cin.ignore();
                Cmaterial c2(nameMaterial,category);
                c2.setCantidad(cantMaterial);
                listMaterial.push_back(c2);
                clab->agregar(c2);
                
                char validator = 'n';
                std::cout<<"Do you want to add more material? (Y/n):";
                std::cin>>validator;
                std::cin.ignore();
                if(validator == 'n')
                {
                    break;
                }
            }
            Csolicitud newSoli(paramDNI,listMaterial,"TRAER");
            c1.agregar(newSoli);
            clab->agregar(newSoli);
        }

        clab->agregar(c1);

        std::cout << "Your Researcher was added to laboratory" << std::endl;
        return 1;
    };

    int menuResearcher()
    {
        // DNI , -> Busque en el vector de investigadores de laboratorio
        // Si lo encuentro te muestra este menu, si no , te va a pedir que crees el investigador
        // DNI - Nombre del investigador

        std::cout << "(1) Crear Solicitud de Materiales" << endl;
        std::cout << "(3) Salir" << endl;
        return -1;
    };

    bool activate = false;

public:
    CSystem(/* args */)
    {
        clab = new Claboratorio("Lab1", "Peru", "202120115");
    }

    void init()
    {
        activate = true;
        do
        {
            int option = menuPrincipal();

            if (option < 1 | option > 3)
            {
                std::cout << "You entered an incorrect option.. Please try it again" << std::endl;
            }
            else if (option == 4)
            {
                activate = false;
                std::cout << "Exit..";
            }
            else
            {
                switch (option)
                {
                case 1:
                    creationMaterial();
                    break;
                case 2:
                    creationResearcher();
                    break;
                default:
                    break;
                }
            }

        } while (activate == true);
    }
    ~CSystem()
    {
        std::cout << "Destruction";
        delete clab;
    };
};

#endif
