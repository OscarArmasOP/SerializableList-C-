//Oscar Martinez Armas

#include <iostream>
#include <fstream>

#include "Seriable.h"
#include "CSeriableList.h"
#include "Cliente.h"
#include "ClienteVIP.h"

using namespace std;

int main() {
    int edad, opc, saldoEx;
    char sexo; ///M,F
    string nombre;
    CSeriableList* myLista(new CSeriableList);

    fstream salida;
    fstream entrada;

    int CLSID;
    entrada.open("clientes.txt", ios_base::in);

    entrada >> CLSID;

    if(CLSID == CLSID_SeriableList) {
        myLista->cargar(entrada);

        myLista->imprimir();
        system("pause");
        }
    entrada.close();

    do {
        system("cls");
        cout << "[1] Agregar Cliente" << endl;
        cout << "[2] Agregar Cliente VIP" << endl;
        cout << "[3] Eliminar Ultimo Cliente" << endl;
        cout << "[4] Mostrar" << endl;
        cout << "[0] Salir" << endl << endl;

        cout << "Elija su opcion: ";
        cin >> opc;
        cin.ignore();

        switch(opc) {
            case 1: {
                system("cls");
                Cliente* myCl(new Cliente);

                cout << "Ingrese el nombre: " << endl;
                getline(cin, nombre);
                myCl->setNombre(nombre);

                cout << "Ingrese la edad: " << endl;
                cin >> edad;
                myCl->setIEdad(edad);

                cout << "Ingrese el sexo (M/F): " << endl;
                cin >> sexo;
                myCl->setSexo(sexo);

                myLista->insertarFinal(myCl);

                system("pause");
                break;

                }
            case 2: {
                system("cls");
                ClienteVIP* myClVIP(new ClienteVIP);

                cout << "Ingrese el nombre: " << endl;
                getline(cin, nombre);
                myClVIP->setNombre(nombre);

                cout << "Ingrese la edad: " << endl;
                cin >> edad;
                myClVIP->setIEdad(edad);

                cout << "Ingrese el sexo (M/F): " << endl;
                cin >> sexo;
                myClVIP->setSexo(sexo);

                cout << "Ingrese el saldo extra: " << endl;
                cin >> saldoEx;
                myClVIP->setSaldo(saldoEx);

                myLista->insertarFinal(myClVIP);

                system("pause");
                break;
                }
            case 3:
                system("cls");
                if(myLista->isEmpty()) {
                    cout << "Lista Vacia" << endl;
                    system("pause");
                    break;
                    }

                myLista->eliminarFinal();

                system("pause");
                break;

            case 4:
                system("cls");

                myLista->imprimir();

                system("pause");
                break;
            case 0:
                cout << "Gracias por ingresar" << endl;

                salida.open("clientes.txt", ios_base::out);
                myLista->guardar(salida);
                salida.close();

                break;
            default:
                cout << "No es una opcion valida" << endl;
                system("pause");
                break;
            }
        }
    while(opc != 0);

    return 0;
    }
