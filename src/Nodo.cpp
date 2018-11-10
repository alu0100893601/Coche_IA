//////////////////////////////////////////////////
// Includes

#include "Nodo.h"

//////////////////////////////////////////////////

Nodo :: Nodo (void) :

  coste_(0),
  h_(0),
  g_(0),
  pos_(),
  pos_padre_(),
  mov_(-1),
  elegido_(false)

{}

//////////////////////////////////////////////////

Nodo :: Nodo (int val, posicion p) :

  coste_(val)

{

  this->pos_.i = p.i;
  this->pos_.j = p.j;

}

//////////////////////////////////////////////////

Nodo :: Nodo (const Nodo& nod) {

  coste_ = nod.coste_;
  h_ = nod.h_;
  g_ = nod.g_;
  pos_ = nod.pos_;
  pos_padre_ = nod.pos_padre_;
  mov_ = nod.mov_;
  elegido_ = nod.elegido_;

}

///////////////////////////////////////////////////

Nodo :: ~Nodo () {}

///////////////////////////////////////////////////
// Getters

int Nodo :: getCoste (void) const{

  return this->coste_;

}

int Nodo :: getH (void) const{

  return this->h_;

}

int Nodo :: getG (void) const{

  return this->g_;

}

int Nodo :: getMov (void) const{

  return this->mov_;

}

posicion Nodo :: getPos (void) const{

  return this->pos_;

}

posicion Nodo :: getPosPadre (void) const{

  return this->pos_padre_;

}

bool Nodo :: getEleg (void) const {

  return this->elegido_;

}

////////////////////////////////////////////////////////
// Setters

void Nodo :: setCoste (int val) {

  this->coste_ = val;

}

void Nodo :: setH (int h) {

  this->h_ = h;

}

void Nodo :: setG (int g) {

  this->g_ = g;

}

void Nodo :: setMov (int m) {

  this->mov_ = m;

}

void Nodo ::setPos (posicion x) {

  this->pos_.i = x.i;
  this->pos_.j = x.j;

}

void Nodo :: setPosPadre (posicion x) {

  this->pos_padre_.i = x.i;
  this->pos_padre_.j = x.j;

}

void Nodo :: setEleg (bool sn) {

  this->elegido_ = sn;

}

//////////////////////////////////////////////////////////
// Funcion para limpiar el nodos

void Nodo :: limpiar (void) {

  posicion limp;
  limp.i = -1;
  limp.j = -1;

  this->coste_ = 0;
  this->h_ = 0;
  this->g_ = 0;
  this->pos_ = limp;
  this->pos_padre_ = limp;
  this->mov_ = -1;
  this->elegido_ = false;

}

//////////////////////////////////////////////////////////
// Sobrecarga del operador =

Nodo& Nodo :: operator= (const Nodo& aux) {

  this->coste_ = aux.getCoste();
  this->h_ = aux.getH();
  this->g_ = aux.getG();
  this->pos_ = aux.getPos();
  this->pos_padre_ = aux.getPosPadre();
  this->elegido_ = aux.getEleg();
  this->mov_ = aux.mov_;


  return (*this);

}

/////////////////////////////////////////////////////////////
// Sobracarga del operador ==

bool Nodo :: operator== (const Nodo& aux) const {

  if ((this->pos_.i == aux.getPos().i) && (this->pos_.j == aux.getPos().j))
    return 1;
  else
    return 0;

}

//////////////////////////////////////////////////////////////
// Sobrecarga del operador salida

std::ostream& operator<< (std::ostream& os, const Nodo& nodito) {

  os << "Nodo: [" << nodito.getPos().i << ", " << nodito.getPos().j << "]";
  os << " con " << nodito.getCoste() << " + " << nodito.getH() << " = " << nodito.getG();
  os << " -> Nodo padre: [" << nodito.getPosPadre().i << ", " << nodito.getPosPadre().j << "]\n";

  return os;

}
