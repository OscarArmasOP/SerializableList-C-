#include "ClienteVIP.h"

using namespace std;

void ClienteVIP::setSaldo(const int& saldo) {
    iSaldoExtra = saldo;
    }

int ClienteVIP::getSaldo() {
    return iSaldoExtra;
    }

int ClienteVIP::getCLSID() {
    return CLSID_ClienteVIP;
    }

void ClienteVIP::guardar(fstream& out) {
    Cliente::guardar(out);
    out << iSaldoExtra << endl;
    }

void ClienteVIP::cargar(fstream& in) {
    Cliente::cargar(in);
    in >> iSaldoExtra;
    }

void ClienteVIP::imprimir() {
    Cliente::imprimir();
    }
