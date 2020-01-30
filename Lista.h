#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
class Lista {
    protected:
        class Nodo {
            private:
                T dato;
                Nodo* siguiente;
                Nodo* anterior;

                void insertarAdelante(T);
                T eliminarSiguiente();

                friend class Lista;
                friend class Iterador;


            };

        class Iterador {
            private:
                Nodo* pActual;
            public:
                void operator = (Iterador&);
                bool operator != (Iterador&);
                bool operator == (Iterador&);
                Iterador& operator ++ (); ///Prefijo
                Iterador& operator -- ();
                T& operator * ();

                friend class Lista;
            };

        Iterador it;
        Nodo inicio;
        Nodo fin;

    public:
        Lista();
        ~Lista();

        void insertarInicio(T);
        void insertarFinal(T);

        T eliminarInicio();
        T eliminarFinal();

        int sizeLista();

        bool isEmpty();

        void imprimir();

        void vacia();

        Iterador& beginIt();
        Iterador& endIt();
    };

#endif // LISTA_H_INCLUDED

template<class T>
void Lista<T>::Nodo::insertarAdelante(T nd) {
    Nodo* nuevo(new Nodo);

    nuevo->dato = nd;

    nuevo->anterior = this;
    nuevo->siguiente = this->siguiente;
    this->siguiente = nuevo;
    nuevo->siguiente->anterior = nuevo;
    }

template<class T>
T Lista<T>::Nodo::eliminarSiguiente() {
    T aux = this->siguiente->dato;
    Nodo* nodAux = this->siguiente;

    this->siguiente = this->siguiente->siguiente;
    this->siguiente->anterior = this;

    delete nodAux;

    return aux;
    }

template<class T>
void Lista<T>::Iterador::operator=(Iterador& p) {
    this->pActual = p.pActual;
    }

template<class T>
bool Lista<T>::Iterador::operator!=(Iterador& a) {
    return this->pActual != a.pActual;
    }

template<class T>
bool Lista<T>::Iterador::operator==(Iterador& p) {
    return this->pActual == p.pActual;
    }

template<class T>
typename Lista<T>::Iterador& Lista<T>::Iterador::operator++() {
    this->pActual = pActual->siguiente;
    return (*this);
    }

template<class T>
typename Lista<T>::Iterador& Lista<T>::Iterador::operator--() {
    this->pActual = this->pActual->anterior;
    return (*this);
    }

template<class T>
T& Lista<T>::Iterador::operator*() {
    return this->pActual->dato;
    }

template<class T>
Lista<T>::Lista() {
    inicio.siguiente = &fin;
    fin.anterior = &inicio;
    inicio.anterior = nullptr;
    fin.siguiente = nullptr;
    }

template<class T>
Lista<T>::~Lista() {
    vacia();
    }

template<class T>
void Lista<T>::insertarInicio(T nd) {
    inicio.insertarAdelante(nd);
    }

template<class T>
void Lista<T>::insertarFinal(T nd) {
    fin.anterior->insertarAdelante(nd);
    }

template<class T>
T Lista<T>::eliminarInicio() {
    return inicio.eliminarSiguiente();
    }

template<class T>
T Lista<T>::eliminarFinal() {
    return fin.anterior->anterior->eliminarSiguiente();
    }

template<class T>
int Lista<T>::sizeLista() {
    int contador = 0;
    Nodo* p = inicio.siguiente;

    while(p != &fin) {
        contador++;
        p = p->siguiente;
        }

    return contador;
    }

template<class T>
bool Lista<T>::isEmpty() {
    if(inicio.siguiente == &fin) {
        return true;
        }
    return false;
    }

template<class T>
void Lista<T>::imprimir() {
    Nodo* p = inicio.siguiente;
    if(isEmpty()) {
        cout << "Lista vacia" << endl;
        return;
        }

    while(p != &fin) {
        cout << p->dato << endl;
        p = p->siguiente;
        }
    }

template<class T>
void Lista<T>::vacia() {
    while(!isEmpty()) {
        inicio.eliminarSiguiente();
        }
    }

template<class T>
typename Lista<T>::Iterador& Lista<T>::beginIt() {
    it.pActual = inicio.siguiente;
    return it;
    }

template<class T>
typename Lista<T>::Iterador& Lista<T>::endIt() {
    it.pActual = &fin;
    return it;
    }
