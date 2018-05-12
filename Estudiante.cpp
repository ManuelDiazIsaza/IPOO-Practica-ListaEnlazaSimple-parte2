/*
  Archivo: Nodo.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2017-08-31
  Fecha última modificación: 2017-08-31
  Versión: 0.1
  Licencia: GPL
*/

#include <stdio.h>
#include <iostream>
#include "Estudiante.h"
#include "string.h"

Estudiante::Estudiante()
{
    codigo = 0;
    nombres = "";
    apellidos = "";
    sig = NULL;
}

Estudiante::Estudiante(int codigo, string apellidos, string nombres)
{
    this->codigo = codigo;
    this->apellidos = apellidos;
    this->nombres = nombres;
    sig = NULL;
}

Estudiante::~Estudiante()
{
    //Método destructor
}

void Estudiante::setCodigo(int codigo){
    this -> codigo = codigo;
}
int Estudiante::getCodigo(){
    return codigo;
}
void Estudiante::setApellidos(string apellidos){
    this -> apellidos = apellidos;
}
string Estudiante::getApellidos(){
    return apellidos;
}
void Estudiante::setNombres(string nombres){
    this -> nombres = nombres;
}
string Estudiante::getNombres(){
    return nombres;
}

void Estudiante::setSig(Estudiante *sig){
    this -> sig = sig;
}

Estudiante* Estudiante::getSig(){
    return this -> sig;
}