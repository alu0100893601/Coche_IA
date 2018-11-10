//////////////////////////////////////////////////
// Includes

#include "Coche.h"

//////////////////////////////////////////////////

Coche :: Coche (void) :

  simbolo_coche_('C'),
  i_(0),
  j_(0),
  personas_recogidas_(0),
  inicio_(),
  fin_(),
  path_()

{}

//////////////////////////////////////////////////

Coche :: Coche (const Coche& car) :

  path_(car.path_)

{

  simbolo_coche_ = car.simbolo_coche_;
  i_ = car.i_;
  j_ = car.j_;
  personas_recogidas_ = car.personas_recogidas_;
  inicio_ = car.inicio_;
  fin_ = car.fin_;

}

/////////////////////////////////////////////////////

Coche :: ~Coche () {}

//////////////////////////////////////////////////////

char Coche :: getSimb (void) const{

  return this->simbolo_coche_;

}

int Coche :: getI (void) const{

  return this->i_;

}

int Coche :: getJ (void) const{

  return this->j_;

}

//////////////////////////////////////////////////////
// Número de persona recogidas

void Coche :: setPRecogidas (int val) {

  this->personas_recogidas_ = this->personas_recogidas_ + val;

}

int Coche :: getPRecogidas (void) const{

  return this->personas_recogidas_;

}

void Coche :: resetPRecogidas (void) {

  this->personas_recogidas_ = 0;

}

//////////////////////////////////////////////////////
// Poner posicion del coche (i,j)

void Coche :: setPos (int i, int j) {

  this->i_ = i;
  this->j_ = j;

}

void Coche :: setInicio (posicion x) {

  this->inicio_.i = x.i;
  this->inicio_.j = x.j;

}

void Coche :: setFin (posicion x) {

  this->fin_.i = x.i;
  this->fin_.j = x.j;

}

/////////////////////////////////////////////////////
// Funcion para hallar el camino por el A*

void Coche :: calcularCamino (std::vector<std::vector<char> > mapa, posicion ini, posicion fini, int heure) {

  this->path_.limpiar();
  this->path_.calculo(mapa, ini, fini, heure);

  std::cout << "\n\tPRESIONE RETORNO DE CARRO PARA SIMULAR EL CAMINO";

}

/////////////////////////////////////////////////////

std::vector<int> Coche :: getMovements (void) const{

  return this->path_.getMovimientos();

}

/////////////////////////////////////////////////////

int Coche :: getTotalGenerado () const{

  return this->path_.getNnodos();

}

/////////////////////////////////////////////////////
// Funcion para mover el COCHE
// 0 = arriba
// 1 = abajo
// 2 = izq
// 3 = drch

void Coche :: mover (std::vector<std::vector<char> >& mapa, int direccion) {

  bool completed = false;

  do {

    int mov = direccion;

    switch (mov) {

      case 0: {

        if (this->getI()-1 >= 0) {

          if (mapa[this->getI()-1][this->getJ()] != '#') {

            if (mapa[this->getI()-1][this->getJ()] == 'P') {

              this->setPRecogidas(1);

              mapa[this->getI()-1][this->getJ()] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI()-1, this->getJ());

              completed = true;

            }
            else {

              mapa[this->getI()-1][this->getJ()] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI()-1, this->getJ());

              completed = true;

            }

          }

        }

        break;
      }

      case 1: {

        if (this->getI()+1 < mapa.size()) {

          if (mapa[this->getI()+1][this->getJ()] != '#') {

            if (mapa[this->getI()+1][this->getJ()] == 'P') {

              this->setPRecogidas(1);

              mapa[this->getI()+1][this->getJ()] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI()+1, this->getJ());

              completed = true;

            }
            else {

              mapa[this->getI()+1][this->getJ()] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI()+1, this->getJ());

              completed = true;

            }

          }

        }

        break;
      }

      case 2: {

        if (this->getJ()-1 >= 0) {

          if (mapa[this->getI()][this->getJ()-1] != '#') {

            if (mapa[this->getI()][this->getJ()-1] == 'P') {

              this->setPRecogidas(1);

              mapa[this->getI()][this->getJ()-1] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI(), this->getJ()-1);

              completed = true;

            }
            else {

              mapa[this->getI()][this->getJ()-1] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI(), this->getJ()-1);

              completed = true;

            }

          }

        }

        break;
      }

      case 3: {

        if (this->getJ()+1 < mapa[0].size()) {

          if (mapa[this->getI()][this->getJ()+1] != '#') {

            if (mapa[this->getI()][this->getJ()+1] == 'P') {

              this->setPRecogidas(1);

              mapa[this->getI()][this->getJ()+1] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI(), this->getJ()+1);

              completed = true;

            }
            else {

              mapa[this->getI()][this->getJ()+1] = 'C';
              mapa[this->getI()][this->getJ()] = ' ';

              this->setPos(this->getI(), this->getJ()+1);

              completed = true;

            }

          }

        }

        break;
      }

    }

  } while (!completed);

}

//////////////////////////////////////////////////////
// Sobrecarga del operador salida

std::ostream& operator<< (std::ostream& os, const Coche& car){

  os << car.getSimb();

  return os;

}
