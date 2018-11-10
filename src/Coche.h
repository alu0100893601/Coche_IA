////////////////////////////////////////////
//Includes

#ifndef COCHE
#define COCHE

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Camino.h"

////////////////////////////////////////////

class Coche {

private:

  char simbolo_coche_;
  int i_;
  int j_;
  int personas_recogidas_;

  posicion inicio_;
  posicion fin_;

  Camino path_;

public:

  Coche();
  Coche(const Coche&);
  ~Coche();

  char getSimb () const;
  int getI () const;
  int getJ () const;
  int getPRecogidas () const;
  std::vector<int> getMovements () const;
  int getTotalGenerado () const;

  void setPos (int, int);
  void setInicio (posicion);
  void setFin (posicion);
  void setPRecogidas (int);

  void resetPRecogidas ();

  void calcularCamino (std::vector<std::vector<char> >, posicion, posicion, int);

  void mover (std::vector<std::vector<char> >&, int);

  //Algoritmos

  friend std::ostream& operator<< (std::ostream&, const Coche&);

};

////////////////////////////////////////////

#endif
