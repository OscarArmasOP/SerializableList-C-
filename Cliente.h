#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Seriable.h"

#define CLSID_Cliente 30

class Cliente : public CSeriable {
    private:
        int iEdad;
        char cSexo; ///M,F
        char szNombre[64];
    public:
        void setIEdad(const int&);
        int getIEdad();

        void setSexo(const char&);
        char getSexo();

        void setNombre(std::string&);
        std::string getNombre();

        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);
        virtual void imprimir();
    };

#endif // CLIENTE_H_INCLUDED
