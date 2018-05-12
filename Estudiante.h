/*
  Archivo: Nodo.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2018-02-09
  Fecha Última modificación: 2018-02-09
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Nodo
// Responsabilidad: elemento (nodo) de una lista
// ColaboraciÃ³n: ninguna


#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

using namespace std;


class Estudiante
{
protected:
    int codigo;
    string apellidos;
    string nombres;
    Estudiante *sig;
public:
    Estudiante();
    Estudiante(int codigo, string apellidos, string nombres);
    ~Estudiante();
    void setCodigo(int codigo);
    int getCodigo();
    void setApellidos(string apellidos);
    string getApellidos();
    void setNombres(string nombres);
    string getNombres();
    Estudiante *getSig();
    void setSig(Estudiante *sig);
};

#endif
