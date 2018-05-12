
#include <stdio.h>
#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
   Lista lista;
   Estudiante estudiante1(1741652,"Diaz","Manuel");
   Estudiante estudiante2(1741641,"Isaza","Alejandro");
   Estudiante estudiante3(1741698,"Rios","Jeffrey");
   Estudiante estudiante4(1741627,"Cardona","Jennifer");


   lista.nuevo(estudiante1);
   lista.nuevo(estudiante2);
   lista.nuevo(estudiante3);
   lista.nuevo(estudiante4);

   lista.interfazPpal();
//   lista.imprimir();
//   cout << endl << lista.cantidadElem();
//   cout << endl << lista.listaOrde();
//   lista.borrarPrimero();
//   cout <<  endl << endl;
//   lista.imprimir();
//   cout <<  endl << endl;
//   lista.borrarUltimo();
//   lista.imprimir();
//   cout << endl << endl;
// lista.borrarElemento(1741652);
// lista.imprimir();

//   cout << endl << lista.estaElemento(3) << endl;

   return 0;
}