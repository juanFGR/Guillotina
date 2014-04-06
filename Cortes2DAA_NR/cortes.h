#include <iostream>
#include <fstream>
#include <vector>
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

using namespace std;

#ifndef __CORTES_H__
#define __CORTES_H__

class CCortes {
  
private:
  int large;
  int weight;
  int numPiezas;
  int** piezas;
  int** matG;
  vector <int> sol;
  
public:
  CCortes (int, int, ifstream&);
  ~CCortes ();
  void setLarge (int);
  int getLarge ();
  void setWeight (int);
  int getWeight ();
  void setNumPiezas (int);
  int getNumPiezas ();
  int getPos (int, int);
  void setPos (int, int, int);
  void setInfo (int, int, int);
  int getInfo (int, int);
  void mostrar ();
  void mostrarPiezas ();
  void mostrarSol ();
  
  //--------------------ALGORITMO DE CORTE TIPO GUILLOTINA--------------------------------------
  int maximo (int, int, int);
  void cortes (int, int);
  void cortesG (int, int);
  int cortesH (int, int);
};

#endif
