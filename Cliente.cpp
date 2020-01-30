#include "Cliente.h"

using namespace std;
void Cliente::setIEdad(const int& edad) {
    iEdad = edad;
    }

int Cliente::getIEdad() {
    return iEdad;
    }

void Cliente::setSexo(const char& sex) {
    cSexo = sex;
    }

char Cliente::getSexo() {
    return cSexo;
    }

void Cliente::setNombre(std::string& nombre) {
    char temp[64];
    strncpy(temp, nombre.c_str(), sizeof(temp));
    for(int i = 0; i < 64; i++) {
        szNombre[i] = temp[i];
        }
    }

string Cliente::getNombre() {
    return szNombre;
    }

int Cliente::getCLSID() {
    return CLSID_Cliente;
    }

void Cliente::guardar(fstream& out) {
    out << getCLSID() << endl;
    out << iEdad << endl;
    out << cSexo << endl;
    out << szNombre << endl;
    }

void Cliente::cargar(fstream& in) {
    in >> iEdad;
    in >> cSexo;
    in >> szNombre;
    }

void Cliente::imprimir() {
        cout << getNombre() << setw(20) << getIEdad() << setw(20) << getSexo() << endl;
}
