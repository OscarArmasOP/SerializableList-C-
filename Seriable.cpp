#include "Seriable.h"

#include "CSeriableList.h"
#include "Cliente.h"
#include "ClienteVIP.h"

using namespace std;

CSeriable* Seriablefactory(int CLSID) {

    CSeriable *pSerializable = 0;

    switch(CLSID) {
    case CLSID_ClienteVIP:
        pSerializable = new ClienteVIP;
    case CLSID_Cliente:
        pSerializable = new Cliente;

        case CLSID_SeriableList:
            pSerializable = new CSeriableList;
            break;
        }

    return pSerializable;

    }
