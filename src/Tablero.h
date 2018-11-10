////////////////////////////////////////////
//Includes

#ifndef TABLERO
#define TABLERO

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <time.h>
#include "Coche.h"

////////////////////////////////////////////

struct pasajeros{

  int posi;
  int posj;
  bool recogido;

};

///////////////////////////////////////////

class Tablero {

private:

  std::vector<std::vector<char>> mapa_;
  Coche car_;
  std::vector<pasajeros> pasajeros_;
  posicion pos_inicial_coche_;
  posicion pos_final_coche_;

  float por_obs_;

public:

  Tablero();
  Tablero(int, int);
  Tablero(const Tablero&);
  ~Tablero();

  void redimensionar ();

  void colocarCoche ();
  void rellenarObstaculos ();
  void rellenarPersonas ();

  void setPosInicial (int, int);
  void setPosFinal (int, int);

  posicion getPosInicial () const;
  posicion getPosFinal () const;

  int getRow (void) const;
  int getCol (void) const;
  char getSimbTab (int, int) const;
  std::vector<pasajeros> getVPasajeros () const;
  Coche getCoche () const;
  float getPorObs () const;

  void setRow (int);
  void setCol (int);
  void setPosTab (int, int, char);
  void setPorObs (float);

  void hallarCamino (int);

  void moverCoche (int);

  friend std::ostream& operator<< (std::ostream&, const Tablero&);

};

////////////////////////////////////////////

#endif
