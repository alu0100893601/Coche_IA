//////////////////////////////////////////////////
// Includes

#include "Camino.h"

//////////////////////////////////////////////////

Camino :: Camino (void) :

  evaluacion_(),
  camino_final_(),
  movimientos_()

{}

//////////////////////////////////////////////////

Camino :: Camino (const Camino& cam) {

  evaluacion_ = cam.evaluacion_;
  camino_final_ = cam.camino_final_;
  movimientos_ = cam.movimientos_;

}

///////////////////////////////////////////////////

Camino :: ~Camino () {}

/////////////////////////////////////////////////////

void Camino :: limpiar (void) {

  this->evaluacion_.clear();
  this->camino_final_.clear();
  this->movimientos_.clear();

}

//////////////////////////////////////////////////////
// Funcion para ver el numero de nodos generados

int Camino :: getNnodos (void) const {

  return this->evaluacion_.size();

}

////////////////////////////////////////////////////
// Establecer heuristicas distancia euclidea

void Camino :: establecerH_1 (posicion final, Nodo& act) {

  int pi = act.getPos().i;
  int pj = act.getPos().j;

  int distancia = sqrt(((final.i - pi) * (final.i - pi)) + ((final.j - pj) * (final.j - pj)));

  act.setH(distancia);

}

////////////////////////////////////////////////////
// Establecer heuristicas distancia rectilinia

void Camino :: establecerH_2 (posicion final, Nodo& act) {

  int pi = act.getPos().i;
  int pj = act.getPos().j;

  int distancia = abs(final.i - pi)+ abs(final.j - pj);

  act.setH(distancia);

}

///////////////////////////////////////////////////
// Funcion para evaluar la frontera

Nodo Camino :: evaluarFrontera (posicion fini) {

  //Elegir uno de los nodos a evaluar para expandir

  int aux = INT_MAX;
  int inx = 0;

  for (size_t i = 0; i < this->evaluacion_.size(); i++) {

    if (this->evaluacion_[i].getEleg() == false) {

      this->evaluacion_[i].setG(this->evaluacion_[i].getCoste() + this->evaluacion_[i].getH());

      if (aux > this->evaluacion_[i].getG()) {

        aux = this->evaluacion_[i].getG();
        inx = i;

      }

    }

  }

  this->evaluacion_[inx].setEleg(true);
  return this->evaluacion_[inx];

}

///////////////////////////////////////////////////
// Funcion para calcular el Camino

void Camino :: calculo (std::vector<std::vector<char> > mapa, posicion ini, posicion fini, int heure) {

  if (!((ini.i==fini.i) && (ini.j==fini.j))) {

    posicion pos_actual;
    pos_actual.i = ini.i;
    pos_actual.j = ini.j;

    posicion aux;
    int cost_aux = 0;
    Nodo x1;
    Nodo chosen;
    bool parar = false;

    x1.setCoste(0);
    x1.setPos(ini);
    x1.setPosPadre(ini);
    x1.setEleg(true);

    this->evaluacion_.push_back(x1);
    x1.limpiar();

    if ((pos_actual.i-1 >= 0) && ((mapa[pos_actual.i-1][pos_actual.j] == ' ') || (mapa[pos_actual.i-1][pos_actual.j] == 'P') || (mapa[pos_actual.i-1][pos_actual.j] == 'X'))) {

        aux.i = pos_actual.i-1;
        aux.j = pos_actual.j;

        cost_aux = 1;
        x1.setCoste(cost_aux);
        x1.setMov(0); //Arriba
        x1.setPos(aux);
        x1.setPosPadre(this->evaluacion_[0].getPos());

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        this->evaluacion_.push_back(x1);
        x1.limpiar();

    }

    if ((pos_actual.i+1 < mapa.size()) && ((mapa[pos_actual.i+1][pos_actual.j] == ' ') || (mapa[pos_actual.i+1][pos_actual.j] == 'P') || (mapa[pos_actual.i+1][pos_actual.j] == 'X'))) {

        aux.i = pos_actual.i+1;
        aux.j = pos_actual.j;

        cost_aux = 1;
        x1.setCoste(cost_aux);
        x1.setMov(1); //Abajo
        x1.setPos(aux);
        x1.setPosPadre(this->evaluacion_[0].getPos());

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        this->evaluacion_.push_back(x1);
        x1.limpiar();

    }

    if ((pos_actual.j-1 >= 0) && ((mapa[pos_actual.i][pos_actual.j-1] == ' ') || (mapa[pos_actual.i][pos_actual.j-1] == 'P') || (mapa[pos_actual.i][pos_actual.j-1] == 'X'))) {

        aux.i = pos_actual.i;
        aux.j = pos_actual.j-1;

        cost_aux = 1;
        x1.setCoste(cost_aux);
        x1.setMov(2); //Izquierda
        x1.setPos(aux);
        x1.setPosPadre(this->evaluacion_[0].getPos());

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        this->evaluacion_.push_back(x1);
        x1.limpiar();

    }

    if ((pos_actual.j+1 < mapa[0].size()) && ((mapa[pos_actual.i][pos_actual.j+1] == ' ') || (mapa[pos_actual.i][pos_actual.j+1] == 'P') || (mapa[pos_actual.i][pos_actual.j+1] == 'X'))) {

        aux.i = pos_actual.i;
        aux.j = pos_actual.j+1;

        cost_aux = 1;
        x1.setCoste(cost_aux);
        x1.setMov(3); //Derecha
        x1.setPos(aux);
        x1.setPosPadre(this->evaluacion_[0].getPos());

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        this->evaluacion_.push_back(x1);
        x1.limpiar();

    }

    chosen = this->evaluarFrontera(fini);

    pos_actual.i = chosen.getPos().i;
    pos_actual.j = chosen.getPos().j;

    if (pos_actual.i == fini.i)
      if (pos_actual.j == fini.j)
        parar = true;
      else
        parar = false;
    else
      parar = false;

    while (!parar) {

      if ((pos_actual.i-1 >= 0) && ((mapa[pos_actual.i-1][pos_actual.j] == ' ') || (mapa[pos_actual.i-1][pos_actual.j] == 'P') || (mapa[pos_actual.i-1][pos_actual.j] == 'X'))) {

        if ((pos_actual.i-1 != chosen.getPosPadre().i) && (pos_actual.j != chosen.getPosPadre().j)) {

          aux.i = pos_actual.i-1;
          aux.j = pos_actual.j;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(0); //Arriba
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      if ((pos_actual.i+1 < mapa.size()) && ((mapa[pos_actual.i+1][pos_actual.j] == ' ') || (mapa[pos_actual.i+1][pos_actual.j] == 'P') || (mapa[pos_actual.i+1][pos_actual.j] == 'X'))) {

        if ((pos_actual.i+1 != chosen.getPosPadre().i) && (pos_actual.j != chosen.getPosPadre().j)) {

          aux.i = pos_actual.i+1;
          aux.j = pos_actual.j;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(1); //Abajo
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      if ((pos_actual.j-1 >= 0) && ((mapa[pos_actual.i][pos_actual.j-1] == ' ') || (mapa[pos_actual.i][pos_actual.j-1] == 'P') || (mapa[pos_actual.i][pos_actual.j-1] == 'X'))) {

        if ((pos_actual.i != chosen.getPosPadre().i) && (pos_actual.j-1 != chosen.getPosPadre().j)) {

          aux.i = pos_actual.i;
          aux.j = pos_actual.j-1;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(2); //Izquierda
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      if ((pos_actual.j+1 < mapa[0].size()) && ((mapa[pos_actual.i][pos_actual.j+1] == ' ') || (mapa[pos_actual.i][pos_actual.j+1] == 'P') || (mapa[pos_actual.i][pos_actual.j+1] == 'X'))) {

        if ((pos_actual.i != chosen.getPosPadre().i) && (pos_actual.j+1 != chosen.getPosPadre().j)) {

          aux.i = pos_actual.i;
          aux.j = pos_actual.j+1;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(3); //Derecha
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      chosen = this->evaluarFrontera(fini);

      pos_actual.i = chosen.getPos().i;
      pos_actual.j = chosen.getPos().j;

      if (pos_actual.i == fini.i)
        if (pos_actual.j == fini.j)
          parar = true;
        else
          parar = false;
      else
        parar = false;

    }

    // En este bloque es donde obtenemos el camino final que debe seguir el coche

    int end = this->evaluacion_.size()-1;
    bool finalizado = false;
    bool find = false;
    std::vector<Nodo> vec_aux;
    vec_aux.push_back(this->evaluacion_.back());

    while (!finalizado) {

      find = false;

      for (int i = end; find == false; i--) {

        if (this->evaluacion_[i].getEleg()) {

          if ((vec_aux.back().getPosPadre().i == this->evaluacion_[i].getPos().i) && (vec_aux.back().getPosPadre().j == this->evaluacion_[i].getPos().j)) {

            find = true;
            end = i;
            vec_aux.push_back(this->evaluacion_[i]);

          }

        }

      }

      if ((ini.i == vec_aux.back().getPos().i) && (ini.j == vec_aux.back().getPos().j))
        finalizado = true;

    }

    std::cout << "\n\tNodo finales ordenados:" << '\n';
    for (int i = vec_aux.size()-1; 0 <= i; i--) {

      std::cout << "\t> " << vec_aux[i];
      this->camino_final_.push_back(vec_aux[i]);

    }

    for (size_t i = 0; i < this->camino_final_.size(); i++) {
      this->movimientos_.push_back(this->camino_final_[i].getMov());
    }


  }
  else {

    std::cout << "Posicion INICIO y FINAL iguales" << '\n';

  }

}

///////////////////////////////////////////////////
// Funcion para devolver los movimientos

std::vector<int> Camino :: getMovimientos (void) const{

  return this->movimientos_;

}
