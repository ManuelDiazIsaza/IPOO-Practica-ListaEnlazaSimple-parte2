/*
  Archivo: Lista.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2017-08-31
  Fecha última modificación: 2017-08-31
  Versión: 0.1
  Licencia: GPL
*/

#include "Lista.h"
#include "Estudiante.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

Lista::Lista()
{
    cab = nullptr;
}


void Lista::nuevo(Estudiante estudiante){
    Estudiante *nuevo;
    nuevo = new Estudiante();
    nuevo->setCodigo(estudiante.getCodigo());
    nuevo->setApellidos(estudiante.getApellidos());
    nuevo->setNombres(estudiante.getNombres());
    if(cab == nullptr){
        cab = nuevo;
        nuevo->setSig(nullptr);
    } else {
        nuevo->setSig(cab);
        cab = nuevo;
    }
}

void Lista::imprimir(){
    Estudiante *desplaza = cab;
    string nombre = "";
    int longitud;
    cout << "================== LISTADO DE ESTUDIANTES ==================" << endl;
    cout << endl << "Codigo" << setw(20) << "Apellido" << setw(13) << "Nombre" << setw(15) << endl;
    cout << "============================================================ " << endl;
    if(cab == nullptr){
        cout << endl << "Lista vacia" << endl <<endl;
    }
    else
    {
        while(desplaza != nullptr)
        {
            nombre = desplaza->getNombres();
            longitud = nombre.length();
        //    cout << nombre.append(20-longitud,'.') << " : " <<setw(5) ;
            cout << desplaza->getCodigo()  <<setw(18) ;
            cout << desplaza->getApellidos()  <<setw(15) ;
            cout << desplaza->getNombres()  << endl;
            desplaza = desplaza->getSig();
        }
    }
    cout << endl << endl;
}


Lista::~Lista()
{
    Estudiante *desplaza = cab;
    Estudiante *borrar;
    while (desplaza != nullptr)
    {
        borrar = desplaza;
        desplaza = desplaza->getSig();
        delete borrar;
    }
}

int Lista::cantidadElem()
{
    Estudiante *desplaza = cab;
    int cont=0;

    if(cab == nullptr){
        return cont;
    }else{
        while(desplaza != nullptr){
            cont++;
            desplaza = desplaza->getSig();
        }
    }
    return cont;
}

bool Lista::listaOrde()
{
    Estudiante *pos1 = cab;
    bool orde = true;

    if(cantidadElem()==1)
    {
        return orde;
    }
    else if(cab== nullptr)
    {
        return orde;
    }
    else
    {
        Estudiante *pos2 = cab->getSig();
        while(pos2 != nullptr)
        {
            if(pos1->getCodigo() < pos2->getCodigo())
            {
                pos1 = pos1->getSig();
                pos2 = pos2->getSig();
            }
            else
            {
                orde = false;
                pos1 = pos1->getSig();
                pos2 = pos2->getSig();
            }
        }
    }
    return orde;
}

void Lista::borrarPrimero()
{
    Estudiante *pos1 = cab;

    if(cantidadElem()==0)
    {
        cout << "Lista Vacia" << endl;
    }
    else if(cantidadElem()==1)
    {
        cab = nullptr;
        delete pos1;
    }
    else
    {
    Estudiante *pos2 = cab->getSig();
    cab = pos2;
    delete pos1;
    }
}

void Lista::borrarUltimo()
{
    Estudiante *pos1 = cab;

    if(cantidadElem()==0)
    {
        cout << "Lista Vacia" << endl;
    }
    else if(cantidadElem()==1)
    {
        cab = nullptr;
        delete pos1;
    }
    else
    {
    Estudiante *pos2 = cab->getSig();
    while(pos2->getSig() != nullptr)
    {
        pos1 = pos1->getSig();
        pos2 = pos2->getSig();
    }
    pos1->setSig(nullptr);
    delete pos2;
    }
}

void Lista::borrarElemento(int elem)
{
    Estudiante *pos1 = cab;
    bool encontro = false;

    if(cantidadElem()==0)
    {
        cout << "Lista Vacia" << endl;
    }
    else if(cantidadElem()==1 && pos1->getCodigo()==elem)
    {
        cab = nullptr;
        delete pos1;
        encontro = true;
    }
    else
    {
        Estudiante *pos2 = cab->getSig();

        if(pos1->getCodigo()==elem)
        {
            cab = pos2;
            delete pos1;
            encontro = true;
        }
        else
        {
            while(pos2 != nullptr)
            {
                if(pos2->getCodigo()==elem && pos2->getSig()== nullptr)
                {
                    pos1->setSig(nullptr);
                    delete pos2;
                    pos2 = nullptr;
                    encontro = true;
                }
                else if(pos2->getCodigo()==elem)
                {
                    pos1->setSig(pos2->getSig());
                    pos1 = pos2->getSig();
                    delete pos2;
                    pos2 = pos1->getSig();
                    encontro = true;
                }
                else
                {
                    pos1 = pos1->getSig();
                    pos2 = pos2->getSig();
                }
            }
        }
    }
    if(encontro)
    {
        cout << "El elemento ha sido eliminado correctamente." << endl;
    }
    else
    {
        cout << "El elemento no se encontraba en la lista." << endl;
    }

}

void Lista::borrarElementos(int elem)
{
    Estudiante *pos1 = cab;
    bool encontro = false;

    while(estaElemento(elem))
    {
        pos1 = cab;

        if(cantidadElem()==0)
        {
            cout << "Lista Vacia" << endl;
        }
        else if(cantidadElem()==1 && pos1->getCodigo()==elem)
        {
           cab = nullptr;
          delete pos1;
           encontro = true;
        }
        else
        {
            Estudiante *pos2 = cab->getSig();
            while(pos2 != nullptr)
            {
                if(pos1->getCodigo()==elem && pos1 == cab)
                {
                    cab = pos2;
                    delete pos1;
                    encontro = true;
                    pos1 = pos2;
                    pos2 = pos2->getSig();
                }
                else if(pos2->getCodigo()==elem && pos2->getSig()== nullptr)
                {
                    pos1->setSig(nullptr);
                    delete pos2;
                    pos2 = nullptr;
                    encontro = true;
                }
                else if(pos2->getCodigo()==elem)
                {
                    pos1->setSig(pos2->getSig());
                    pos1 = pos2->getSig();
                    delete pos2;
                    pos2 = pos1->getSig();
                    encontro = true;
                }
                else
                {
                    pos1 = pos1->getSig();
                    pos2 = pos2->getSig();
                }
            }
        }
    }
    if(pos1->getCodigo() == elem)
    {
        borrarUltimo();
    }
    if(encontro)
    {
        cout << "Todas las coincidencias han sido eliminadas correctamente." << endl;
    }
    else
    {
        cout << "El elemento no se encontraba en la lista." << endl;
    }

}

bool Lista::estaElemento(int elem)
{
    Estudiante *pos1 = cab;
    bool esta=false;

    while(pos1 != nullptr)
    {
        if(pos1->getCodigo()==elem)
        {
            esta=true;
            pos1= nullptr;
        }
        else
        {
            pos1 = pos1->getSig();
        }
    }
    return esta;
}

void Lista::buscarCodigo(int codigo)
{
    Estudiante *pos1 = cab;
    bool esta=false;
    while(pos1 != nullptr)
    {
        if(pos1->getCodigo()== codigo)
        {
            cout << "El codigo del Estudiante es: " << pos1->getCodigo() << endl;
            cout << "Los apellidos del estudiante son: " << pos1->getApellidos() << endl;
            cout << "Los Nombres del Estudiante son: " << pos1->getNombres() << endl;
            pos1 = nullptr;
            esta = true;
        }
        else
        {
            pos1 = pos1->getSig();
        }
    }
    if(!esta)
    {
        cout << "El estudiante no se encuentra registrado." << endl;
    }
}

void Lista::interfazPpal()
{
    int opcion;
    while(opcion != 4) {
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::: MENU PRINCIPAL ::::::::::::::::::::::::" << endl;
        cout << "1. Adicionar Estudiante." << endl;
        cout << "2. Listar Estudiantes." << endl;
        cout << "3. Buscar estudiante por Codigo." << endl;
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl << endl;
        cout << "Ingrese su opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int codigo;
                string apellidos, nombres;
                cout << "Introduzca el codigo del estudiante a ingresar." << endl;
                cin >> codigo;
                cout << "Introduzca el apellido del estudiante a ingresar." << endl;
                cin >> apellidos;
                cout << "Introduzca el nombre del estudiante a ingresar." << endl;
                cin >> nombres;
                Estudiante estudiAgregar(codigo, apellidos, nombres);
                nuevo(estudiAgregar);
                break;
            }
            case 2: {
                imprimir();
                break;
            }
            case 3: {
                int codigo;
                cout << "Introduzca el codigo del estudiante a buscar." << endl;
                cin >> codigo;
                buscarCodigo(codigo);
                cout << endl << endl;
            }
        }
    }
}