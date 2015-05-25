/**
  @file Lista.h

  Implementaci�n del TAD lista, utilizando una 
  lista doblemente enlazada.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Marco Antonio G�mez Mart�n, 2012
 */
#ifndef __LISTA_H
#define __LISTA_H

#include "Excepciones.h"
#include <cassert>

/**
 Implementaci�n del TAD Pila utilizando vectores din�micos.

 Las operaciones son:

 - ListaVacia: -> Lista. Generadora implementada en el
   constructor sin par�metros.
 - Cons: Lista, Elem -> Lista. Generadora.
 - ponDr: Lista, Elem -> Lista. Modificadora.
 - primero: Lista - -> Elem. Observadora parcial
 - resto: Lista - -> Lista. Modificadora parcial
 - ultimo: Lista - -> Elem. Observadora parcial
 - inicio: Lista - -> Lista. Modificadora parcial
 - esVacia: Lista -> Bool. Observadora
 - numElems: Lista -> Elem. Obervadora.
 - elem: Lista, Entero - -> Elem. Observador parcial.

 @author Marco Antonio G�mez Mart�n
 */
template <class T>
class Lista {
private:

    /**
     Clase nodo que almacena internamente el elemento (de tipo T),
     y dos punteros, uno al nodo anterior y otro al nodo siguiente.
     Ambos punteros podr�an ser NULL si el nodo es el primero
     y/o �ltimo de la lista enlazada.
     */
    class Nodo {
    public:

        Nodo() : _sig(NULL), _ant(NULL) {
        }

        Nodo(const T &elem) : _elem(elem), _sig(NULL), _ant(NULL) {
        }

        Nodo(Nodo *ant, const T &elem, Nodo *sig) :
        _elem(elem), _sig(sig), _ant(ant) {
        }

        T _elem;
        Nodo *_sig;
        Nodo *_ant;
    };

public:

    /** Constructor; operaci�n ListaVacia. */
    Lista() : _prim(NULL), _ult(NULL), _numElems(0) {
    }

    /** Destructor; elimina la lista doblemente enlazada. */
    ~Lista() {
        libera();
    }

    /**
     A�ade un nuevo elemento en la cabeza de la lista.
     Operaci�n generadora.

     @param elem Elemento que se a�ade en la cabecera de
     la lista.
     */
    void Cons(const T &elem) {
        _numElems++;
        _prim = insertaElem(elem, NULL, _prim);
        if (_ult == NULL)
            _ult = _prim;
    }

    /**
     A�ade un nuevo elemento al final de la lista (a la 
     "derecha"). Operaci�n modificadora.

     ponDr(e, ListaVacia) = Cons(e, ListaVacia)
     ponDr(e, Cons(x, xs)) = Cons(x, ponDr(e, xs))
     */
    void ponDr(T &elem) {
        _numElems++;
        _ult = insertaElem(elem, _ult, NULL);
        if (_prim == NULL)
            _prim = _ult;
    }

    void ponDr(const T &elem) {
        _numElems++;
        _ult = insertaElem(elem, _ult, NULL);
        if (_prim == NULL)
            _prim = _ult;
    }

    /**
     Devuelve el valor almacenado en la cabecera de la
     lista. Es un error preguntar por el primero de
     una lista vac�a.

     primero(Cons(x, xs)) = x
     error primero(ListaVacia)

     @return Elemento en la cabecera de la lista.
     */
    const T &primero() const {
        if (esVacia())
            throw EListaVacia();
        return _prim->_elem;
    }

    /**
     Devuelve el valor almacenado en la �ltima posici�n
     de la lista (a la derecha).
     Es un error preguntar por el primero de una lista vac�a.

     ultimo(Cons(x, xs)) = x           SI esVacia(xs)
     ultimo(Cons(x, xs)) = ultimo(xs)  SI !esVacia(xs)
     error ultimo(ListaVacia)

     @return Elemento en la cola de la lista.
     */
    const T &ultimo() const {
        if (esVacia())
            throw EListaVacia();

        return _ult->_elem;
    }

    /**
     Elimina el primer elemento de la lista.
     Es un error intentar obtener el resto de una lista vac�a.

     resto(Cons(x, xs)) = xs
     error resto(ListaVacia)
     */
    void resto() {
        if (esVacia())
            throw EListaVacia();

        Nodo *aBorrar = _prim;
        _prim = _prim->_sig;
        borraElem(aBorrar);
        if (_prim == NULL)
            _ult = NULL;
        --_numElems;
    }

    /**
     Elimina el �ltimo elemento de la lista.
     Es un error intentar obtener el inicio de una lista vac�a.

     inicio(Cons(x, ListaVacia)) = ListaVacia
     inicio(Cons(x, xs)) = Cons(x, inicio(xs)) SI !esVacia(xs)
     error inicio(ListaVacia)
     */
    void inicio() {
        if (esVacia())
            throw EListaVacia();

        Nodo *aBorrar = _ult;
        _ult = _ult->_ant;
        borraElem(aBorrar);
        if (_ult == NULL)
            _prim = NULL;
        --_numElems;
    }

    /**
     Operaci�n observadora para saber si una lista
     tiene o no elementos.

     esVacia(ListaVacia) = true
     esVacia(Cons(x, xs)) = false

     @return true si la lista no tiene elementos.
     */
    bool esVacia() const {
        return _prim == NULL;
    }

    /**
     Devuelve el n�mero de elementos que hay en la
     lista.
     numElems(ListaVacia) = 0
     numElems(Cons(x, xs)) = 1 + numElems(xs)

     @return N�mero de elementos.
     */
    unsigned int numElems() const {
        return _numElems;
    }

    /**
     Devuelve el elemento i-�simo de la lista, teniendo
     en cuenta que el primer elemento (primero())
     es el elemento 0 y el �ltimo es numElems()-1,
     es decir idx est� en [0..numElems()-1].
     Operaci�n observadora parcial que puede fallar
     si se da un �ndice incorrecto. El �ndice es
     entero sin signo, para evitar que se puedan
     pedir elementos negativos.

     elem(0, Cons(x, xs)) = x
     elem(n, Cons(x, xs)) = elem(n-1, xs) si n > 0
     error elem(n, xs) si !( 0 <= n < numElems(xs) )
     */
    T &elem(unsigned int idx) const {
        if (idx >= _numElems)
            throw EAccesoInvalido();

        Nodo *aux = _prim;
        for (int i = 0; i < idx; ++i)
            aux = aux->_sig;

        return aux->_elem;
    }

    /**
     Clase interna que implementa un iterador sobre
     la lista que permite recorrer la lista e incluso
     alterar el valor de sus elementos.
     */
    class Iterador {
    public:

        void avanza() {
            if (_act == NULL) throw EAccesoInvalido();
            _act = _act->_sig;
        }

        T &elem() const {
            if (_act == NULL) throw EAccesoInvalido();
            return _act->_elem;
        }

        void pon(const T &elem) {
            if (_act == NULL) throw EAccesoInvalido();
            _act->_elem = elem;
        }

        bool operator==(const Iterador &other) const {
            return _act == other._act;
        }

        bool operator!=(const Iterador &other) const {
            return !(this->operator==(other));
        }
    protected:
        // Para que pueda construir objetos del
        // tipo iterador
        friend class Lista;

        Iterador() : _act(NULL) {
        }

        Iterador(Nodo *act) : _act(act) {
        }

        // Puntero al nodo actual del recorrido
        Nodo *_act;
    };

    /**
     Devuelve el iterador al principio de la lista.
     @return iterador al principio de la lista;
     coincidir� con final() si la lista est� vac�a.
     */
    Iterador principio() {
        return Iterador(_prim);
    }

    /**
     @return Devuelve un iterador al final del recorrido
     (fuera de �ste).
     */
    Iterador final() const {
        return Iterador(NULL);
    }

    /**
     Permite eliminar de la lista el elemento
     apuntado por el iterador que se pasa como par�metro.
     El iterador recibido DEJA DE SER V�LIDO. En su
     lugar, deber� utilizarse el iterador devuelto, que
     apuntar� al siguiente elemento al borrado.
     @param it Iterador colocado en el elemento que se
     quiere borrar.
     @return Nuevo iterador colocado en el elemento siguiente
     al borrado (podr�a coincidir con final() si el
     elemento que se borr� era el �ltimo de la lista).
     */
    Iterador borra(const Iterador &it) {
        if (it._act == NULL)
            throw EAccesoInvalido();

        // Cubrimos los casos especiales donde
        // borramos alguno de los extremos
        if (it._act == _prim) {
            resto();
            return Iterador(_prim);
        } else if (it._act == _ult) {
            inicio();
            return Iterador(NULL);
        } else {
            // El elemento a borrar es interno a la lista.
            --_numElems;
            Nodo *sig = it._act->_sig;
            borraElem(it._act);
            return Iterador(sig);
        }
    }

    /**
     M�todo para insertar un elemento en la lista
     en el punto marcado por el iterador. En concreto,
     se a�ade _justo antes_ que el elemento actual. Es
     decir, si it==l.primero(), el elemento insertado se
     convierte en el primer elemento (y el iterador
     apuntar� al segundo). Si it==l.final(), el elemento
     insertado ser� el �ltimo (e it seguir� apuntando
     fuera del recorrido).
     @param elem Valor del elemento a insertar.
     @param it Punto en el que insertar el elemento.
     */
    void insertar(const T &elem, const Iterador &it) {

        // Caso especial: �a�adir al principio?
        if (_prim == it._act) {
            Cons(elem);
        } else
            // Caso especial: �a�adir al final?
            if (it._act == NULL) {
            ponDr(elem);
        }// Caso normal
        else {
            insertaElem(elem, it._act->_ant, it._act);
        }
    }

    // //
    // M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
    // A LA CLASE
    // //

    /** Constructor copia */
    Lista(const Lista<T> &other) : _prim(NULL), _ult(NULL) {
        copia(other);
    }

    /** Operador de asignaci�n */
    Lista<T> &operator=(const Lista<T> &other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    /** Operador de comparaci�n. */
    bool operator==(const Lista<T> &rhs) const {
        if (_numElems != rhs._numElems)
            return false;
        Nodo *p1 = _prim;
        Nodo *p2 = rhs._prim;
        while ((p1 != NULL) && (p2 != NULL)) {
            if (p1->_elem != p2->_elem)
                return false;
            p1 = p1->_sig;
            p2 = p2->_sig;
        }

        return (p1 == NULL) && (p2 == NULL);
    }

    bool operator!=(const Lista<T> &rhs) const {
        return !(*this == rhs);
    }


protected:

    void libera() {
        libera(_prim);
        _prim = NULL;
        _ult = NULL;
    }

    void copia(const Lista<T> &other) {
        // En vez de trabajar con punteros en la inserci�n,
        // usamos ponDr
        _prim = 0;
        _numElems = 0;

        Nodo *act = other._prim;
        while (act != NULL) {
            ponDr(act->_elem);
            act = act->_sig;
        }
    }

private:

    /**
     Inserta un elemento entre el nodo1 y el nodo2.
     Devuelve el puntero al nodo creado.
     Caso general: los dos nodos existen.
        nodo1->_sig == nodo2
        nodo2->_ant == nodo1
     Casos especiales: alguno de los nodos no existe
        nodo1 == NULL y/o nodo2 == NULL
     */
    static Nodo *insertaElem(const T &e, Nodo *nodo1, Nodo *nodo2) {
        Nodo *nuevo = new Nodo(nodo1, e, nodo2);
        if (nodo1 != NULL)
            nodo1->_sig = nuevo;
        if (nodo2 != NULL)
            nodo2->_ant = nuevo;
        return nuevo;
    }

    /**
     Elimina el nodo n. Si el nodo tiene nodos antes
     o despu�s, actualiza sus punteros anterior y siguiente.
     Caso general: hay nodos anterior y siguiente.
     Casos especiales: algunos de los nodos (anterior o siguiente
     a n) no existen.
     */
    static void borraElem(Nodo *n) {
        assert(n != NULL);
        Nodo *ant = n->_ant;
        Nodo *sig = n->_sig;
        if (ant != NULL)
            ant->_sig = sig;
        if (sig != NULL)
            sig->_ant = ant;
        delete n;
    }

    /**
     Elimina todos los nodos de la lista enlazada cuyo
     primer nodo se pasa como par�metro.
     Se admite que el nodo sea NULL (no habr� nada que
     liberar). En caso de pasarse un nodo v�lido,
     su puntero al nodo anterior debe ser NULL (si no,
     no ser�a el primero de la lista!).
     */
    static void libera(Nodo *prim) {
        assert(!prim || !prim->_ant);

        while (prim != NULL) {
            Nodo *aux = prim;
            prim = prim->_sig;
            delete aux;
        }
    }

    // Puntero al primer y �ltimo elemento
    Nodo *_prim, *_ult;

    // N�mero de elementos (n�mero de nodos entre _prim y _ult)
    unsigned int _numElems;
};

#endif // __LISTA_ENLAZADA_H
