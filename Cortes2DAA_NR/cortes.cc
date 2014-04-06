#include <iostream>
#include <fstream>
#include "cortes.h"

using namespace std;

CCortes::CCortes (int l, int w, ifstream &fich){
  const int COLUMNAS = 3;
  int temp, k = 0, lm = 0;
  int nPiezas = 0;
  setLarge (l); // Filas
  setWeight (w); //Columnas
  //Creando la matriz de programacion dinamica
  matG = new int* [getLarge () + 1];
  for (int i = 0; i <= getLarge (); i++) {
    matG [i] = new int [getWeight () + 1];
  }
  //Creando la Matriz con la informacion de las piezas
  fich >> nPiezas;
  setNumPiezas (nPiezas);
  piezas = new int* [getNumPiezas ()];
  for (int i = 0; i < getNumPiezas(); i++) {
    piezas[i] = new int [COLUMNAS];
  }
  //Leyendo de fichero la informacion de las piezas
  //Ancho Alto Valor
  while ((!fich.eof ()) && (k < getNumPiezas ()) && (lm < COLUMNAS)){
    fich >> temp;
    setInfo (k, lm, temp);
    lm++;
    if (lm == COLUMNAS) {
      lm = 0;
      k++;
    }
  }
  //Inicializando la matriz de programacion dinamica
  for (int i = 0; i <= l; i++) {
    for (int j = 0; j < w; j++) {
      setPos (i, j, 0);
    }
  }
  
}

CCortes::~CCortes () {
 // int l = getLarge ();
  cout<<"Borrado";
  for (int i = 0; i <= getLarge (); i++) {
    delete [] matG [i];
  }
  delete [] matG;
  setLarge (0);
  setWeight (0);
}

void CCortes::setLarge (int l) {
  large = l;
}

int CCortes::getLarge (){
  return large;
}

void CCortes::setWeight (int w) {
  weight = w;
}

int CCortes::getWeight () {
  return weight;
}

void CCortes::setNumPiezas (int nPiezas) {
  numPiezas = nPiezas;
}

int CCortes::getNumPiezas () {
  return numPiezas;
}

int CCortes::getPos (int i, int j) {
  return matG[i][j];
}

void CCortes::setPos (int i, int j, int valor) {
  matG[i][j] = valor;
}

void CCortes::mostrar () {
  int l = getLarge ();
  int w = getWeight ();
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= w; j++) {
      cout << getPos (i, j) << "\t";
    }
    cout << endl;
  }
}

void CCortes::setInfo (int i, int j, int value){
  piezas[i][j] = value;
}

int CCortes::getInfo (int i, int j) {
  return piezas[i][j];
}

void CCortes::mostrarPiezas () {
  const int COLUMNAS = 3;
  cout << "Ancho\tAlto\tValor Pieza" << endl;
  for (int i = 0; i < getNumPiezas (); i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      cout << getInfo(i, j) << "\t";
    }
    cout << endl;
  }
}

void CCortes::mostrarSol () {
  
  cout << "Solucion: ";
  for (int i = 0; i < sol.size (); i++) {
      cout << sol[i] << "\t";
  }
  cout << endl;
}


//--------------------ALGORITMO DE CORTE TIPO GUILLOTINA--------------------------------------
int CCortes::maximo (int num1, int num2, int num3) {
  int max = num1;
  if (num2 > max) {
	 max = num2;
  }
  if (num3 > max) {
	 max = num3;
  }
  return max;
}

void CCortes::cortes (int x, int y) {
  for (int i = 0; i <= x; i++) {
	 for (int j = 0; j <= y; j++) {
		cortesG (i, j);
	 }
  }
}

void CCortes::cortesG (int x, int y) {
  //G(x, y) = max {H(x, y), G(x0, y) + G(x - x0, y), G(x, y0) + G(x, y - y0)}
  //x0 <= 1/2 x, y0 <= y
  int xMed = (x / 2), yMed = (y / 2);
  int x0 = 0, y0 = 0;
  int temp = 0;
  while ((x0 <= xMed) && (y0 <= yMed)) {
	 temp = maximo (cortesH(x, y), getPos (x0, y) + getPos (x - x0, y), getPos (x, y0) + getPos (x, y - y0));
	 setPos (x, y, temp);
	 x0++;
	 y0++;
  }
  //setPos (x, y, temp1);
}

int CCortes::cortesH (int x, int y) {
  //H(x, y) = max_i {p_i tal que w_i <= x; l_i <= y}; i = 1....n
  int nPiezas = getNumPiezas ();
  int i = 0;
  int p_i = 0, an_i = 0, al_i = 0;
  while ((i < nPiezas) && (getInfo(i, 0) <= x) && (getInfo (i, 1) <= y)) {
	 p_i = getInfo (i, 2);
	 i++;
  }
  return p_i;
}
