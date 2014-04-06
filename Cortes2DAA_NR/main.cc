/** ******************************************************
 * Diseño y analisis de algoritmos                       *
 * El problema de corte bidimensional sin restricciones  *
 * es el problema de cortar de una lamina plana          *
 * rectangular un conjunto de piezas rectangulares más   *
 * pequeñas, de un tamaño dado, y cada una con un valor, * 
 * de manera que se maximice el valor de las piezas      *
 * a cortar.                                             *
 *                                                       *
 * @author Juan Francisco González Ramos                 * 
 * @version 0.2                                          *
 * @copyright Creative Commons
 * *******************************************************/

#include <iostream>
#include <fstream>
#include "cortes.h"

using namespace std;

int main () {
  char name [80];
  int large;
  int weight;
  
  cout << "Introduzca nombre del fichero con informacion de las piezas" << endl;
  cin >> name;
  cout << "Introduzca Largo y Ancho de la plancha: Largo espacio Ancho" << endl;
  cin >> large >> weight;
  ifstream fich (name);
  CCortes cortes (large, weight, fich);
  fich.close ();
  cortes.cortes (large, weight);
  cout << "Mostrando Matriz de Piezas" << endl;
  cortes.mostrarPiezas ();
  cout << "Mostrando Matriz de Programacion Dinamica" << endl;
  cortes.mostrar ();
  cout << "Valor Optimo: " << cortes.getPos (large, weight) << endl;
  cortes.mostrarSol ();
}
