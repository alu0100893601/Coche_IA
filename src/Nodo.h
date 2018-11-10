////////////////////////////////////////////
//Includes

#ifndef NODO
#define NODO

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

////////////////////////////////////////////

struct posicion{

  int i;
  int j;

};

///////////////////////////////////////////////

class Nodo {

private:

  int coste_;
  int h_;
  int g_;

  posicion pos_;
  posicion pos_padre_;

  bool elegido_;

  int mov_;

public:

  Nodo();
  Nodo(int, posicion);
  Nodo(const Nodo&);
  ~Nodo();

  int getCoste () const;
  int getH () const;
  int getG () const;
  int getMov () const;
  posicion getPos () const;
  posicion getPosPadre () const;
  bool getEleg () const;

  void setCoste (int);
  void setH (int);
  void setG (int);
  void setMov (int);
  void setPos (posicion);
  void setPosPadre (posicion);
  void setEleg (bool);

  void limpiar ();

  Nodo& operator= (const Nodo&);
  bool operator== (const Nodo&) const;

  friend std::ostream& operator<< (std::ostream&, const Nodo&);

};

////////////////////////////////////////////

#endif
