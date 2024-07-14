
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
        std::cout << "(4) Listar Materiales" << endl;
        std::cout << "(5) Listar Solicitudes" << endl;
        std::cout << "(6) Salir" << endl;
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
                getline(cin, nameMaterial);
                std::cout << "Enter your category name:";
                getline(cin, paramName);
                int cantMaterial;
                std::cout << "How many material do you have?:";
                std::cin >> cantMaterial;
                std::cin.ignore();
                Cmaterial c2(nameMaterial, category);
                c2.setCantidad(cantMaterial);
                listMaterial.push_back(c2);
                clab->agregar(c2);

                char validator = 'n';
                std::cout << "Do you want to add more material? (Y/n):";
                std::cin >> validator;
                std::cin.ignore();
                if (validator == 'n')
                {
                    break;
                }
            }
            // Creación de solicitud con todo los datos necesarios
            Csolicitud newSoli(paramDNI, listMaterial, "TRAER");
            c1.agregar(newSoli);
            clab->agregar(newSoli);
        }

        clab->agregar(c1);

        std::cout << "Your Researcher was added to laboratory" << std::endl;
        return 1;
    };

    void ingresarResearcher()
    {
        string dni_param = "";
        do
        {
            std::cout << "Ingrese el DNI del Investigador:";
            std::cin >> dni_param;
        } while (clab->existReasearcherByDni(dni_param) == false);

        int optionX = menuResearcher();

        if (optionX == 1)
        {
            crearSolicitudMaterialesMenu(dni_param);
        }
        else if (optionX == 2)
        {
            clab->listaMateriales();
        }
        else if (optionX == 3)
        {
            int optionX2 = menuBusquedas();

            if (optionX2 == 1)
            {
                string nameMaterialX;
                std::cout << "Ingrese el nombre del material:";
                std::cin >> nameMaterialX;
                clab->busquedaByName(nameMaterialX);
            }
            else
            {
                string cateogoryMaterialX;
                std::cout << "Ingrese la categoria del material:";
                std::cin >> cateogoryMaterialX;
                clab->busquedaByName(cateogoryMaterialX);
            }
        }
        else if (optionX == 4)
        {
            crearSolicitudDeDevolverMaterial(dni_param);
        }
    }

    int menuBusquedas()
    {
        int option = -1;
        do
        {
            std::cout << "(1) Busqueda por Nombre" << endl;
            std::cout << "(2) Busqueda por Categoria" << endl;
            std::cin >> option;
        } while (option > 2 || option < 1);

        return option;
    }

    int menuResearcher()
    {
        // DNI , -> Busque en el vector de investigadores de laboratorio
        // Si lo encuentro te muestra este menu, si no , te va a pedir que crees el investigador
        // DNI - Nombre del investigador

        int option = -1;
        std::cout << "(1) Crear Solicitud de Materiales" << endl;
        std::cout << "(2) Ver Lista de materiales" << endl;
        std::cout << "(3) Busquedas de Materiales" << endl;
        std::cout << "(4) Crear Devolución de Materiales" << endl;
        do

        {
            std::cout << "Enter your option:";
            std::cin >> option;
        } while (option < 1 | option > 4);

        return option;
    };

    void crearSolicitudMaterialesMenu(string dni)
    {
        string tipo = "PEDIR";
        vector<Cmaterial> solicitadosMateriales;
        std::cout << "Lista de materiales de solicitud:" << endl;
        int num = 0;
        while (true)
        {
            cout << endl;
            cout << "Material Numero " << num + 1 << " :" << endl;
            string nameMatSoli = "";
            string codeSoliMat = "";
            std::cin.ignore();
            std::cout << "Nombre de Material:";
            getline(cin, nameMatSoli);
            std::cout << "Codigo:";
            getline(cin, codeSoliMat);

            if (!clab->existMaterialCodeName(codeSoliMat, nameMatSoli))
            {
                std::cout << "El material que ingresaste no existe";
            }
            else
            {
                int cantidad;
                do
                {
                    std::cout << "Cuanta cantidad necesitas?:";
                    cin >> cantidad;
                } while (clab->existEnoughAmount(codeSoliMat, nameMatSoli, cantidad) == false);

                Cmaterial materialSolicitado;
                materialSolicitado.setCantidad(cantidad);

                clab->updateByCodigoAndNameMaterial(codeSoliMat, nameMatSoli, materialSolicitado);

                // Ya esta listo nuestro material para guardar
                solicitadosMateriales.push_back(materialSolicitado);

                char validator = 'n';
                std::cout << "Do you want to add more material? (Y/n):";
                std::cin >> validator;
                std::cin.ignore();
                if (validator == 'n')
                {
                    break;
                }

                num++;
            }
        }

        // Tenemos lista nuestra solicitud
        Csolicitud newSoli(dni, solicitadosMateriales, tipo);

        // Ahora la añadimos a la solicitudes del investigador

        clab->agregarSolicitudAInvestigator(newSoli, dni);

        // Ahora ya esta registrada en el investigator
        // Ahora registraremos en el laboratorio
        // pero ahora si la función agregar de laboratorio
        // hara el trabajo de retirar material de laboratorio(simulation)
        clab->agregar(newSoli);
        // Listo se agregaron las 2 solicitudes
    }

    void crearSolicitudDeDevolverMaterial(string dni)
    {
        vector<Cmaterial> materialesDevolver;
        string materialName = "";
        string codeMaterial = "";
        int cantMaterial = -1;
        string tipo = "DEVOLVER";
        std::cout << "Que material quieres devolver?" << std::endl;
        do
        {
            std::cout << "Nombre del material:";
            std::cin >> materialName;
            std::cout << "Codigo del material:";
            std::cin >> codeMaterial;
        } while (clab->existMaterialCodeName(codeMaterial, materialName) == false);

        Cmaterial materialparaDevolver;

        std::cout << "Cuanto de material va a devolver?:";
        std::cin >> cantMaterial;

        materialparaDevolver.setCantidad(cantMaterial);

        clab->updateByCodigoAndNameMaterial(codeMaterial, materialName, materialparaDevolver);

        materialesDevolver.push_back(materialparaDevolver);

        Csolicitud newSoli(dni, materialesDevolver, tipo);

        std::cout << "Material ha sido devuelto con exito";

        clab->agregarSolicitudAInvestigator(newSoli, dni);

        clab->agregar(newSoli);

        std::cout << "Material ha sido devuelto ..." << std::endl;
    }

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

            if (option < 1 | option > 6)
            {
                std::cout << "You entered an incorrect option.. Please try it again" << std::endl;
            }
            else if (option == 6)
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
                case 3:
                    ingresarResearcher();
                case 4:
                    clab->listaMateriales();
                case 5:
                    clab->listaDeSolicitudesFull();
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
