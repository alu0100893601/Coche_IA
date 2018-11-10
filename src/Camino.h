////////////////////////////////////////////
//Includes

#ifndef CAMINO
#define CAMINO

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include "Nodo.h"

////////////////////////////////////////////

class Camino {

private:

  std::vector<Nodo> evaluacion_;
  std::vector<Nodo> camino_final_;

  std::vector<int> movimientos_;

public:

  Camino();
  Camino(const Camino&);
  ~Camino();

  void establecerH_1 (posicion, Nodo&);
  void establecerH_2 (posicion, Nodo&);

  std::vector<int> getMovimientos () const;

  void limpiar ();

  int getNnodos () const;

  Nodo evaluarFrontera (posicion);

  void calculo (std::vector<std::vector<char> >, posicion, posicion, int);

};

////////////////////////////////////////////

#endif
