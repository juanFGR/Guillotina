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
  //cout << "Mostrando Matriz de Programacion Dinamica" << endl;
  //cortes.mostrar ();
  cout << "Valor Optimo: " << cortes.getPos (large, weight) << endl;
  //cortes.mostrarSol ();
}
