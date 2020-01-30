#ifndef CLIENTEVIP_H_INCLUDED
#define CLIENTEVIP_H_INCLUDED

#include "Cliente.h"

#define CLSID_ClienteVIP 2

class ClienteVIP : public Cliente {
    private:
        int iSaldoExtra;
    public:
        void setSaldo(const int&);
        int getSaldo();

        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);
        virtual void imprimir();
    };

#endif // CLIENTEVIP_H_INCLUDED
