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

      if (aux >= this->evaluacion_[i].getG()) {

        aux = this->evaluacion_[i].getG();
        inx = i;

      }

    }

  }

  this->evaluacion_[inx].setEleg(true);
  Nodo aux_n(this->evaluacion_[inx]);
  return aux_n;

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
    x1.limpiar();
    chosen.limpiar();
    bool parar = false;
    std::vector<Nodo> vector_elegidos;

    x1.setCoste(0);
    x1.setPos(ini);
    x1.setPosPadre(ini);
    x1.setEleg(true);

    if (heure == 1)
      this->establecerH_1(fini, x1);
    if (heure == 2)
      this->establecerH_2(fini, x1);

    x1.setG(x1.getCoste() + x1.getH());

    this->evaluacion_.push_back(x1);
    vector_elegidos.push_back(x1);
    x1.limpiar();

    if ((pos_actual.i-1 >= 0) && ((mapa[pos_actual.i-1][pos_actual.j] == ' ') || (mapa[pos_actual.i-1][pos_actual.j] == 'P') || (mapa[pos_actual.i-1][pos_actual.j] == 'X'))) {

        aux.i = pos_actual.i-1;
        aux.j = pos_actual.j;

        cost_aux = 1;
        x1.setCoste(cost_aux);
        x1.setMov(0); //Arriba
        x1.setPos(aux);
        x1.setPosPadre(this->evaluacion_[0].getPos());
        x1.setEleg(false);

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        x1.setG(x1.getCoste() + x1.getH());

        int k = 0;
        bool meter = true;
        while (k<this->evaluacion_.size()) {
          if(this->evaluacion_[k] == x1)
            meter = false;
          k++;
        }
        if (meter)
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
        x1.setEleg(false);

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        x1.setG(x1.getCoste() + x1.getH());

        int k = 0;
        bool meter = true;
        while (k<this->evaluacion_.size()) {
          if(this->evaluacion_[k] == x1)
            meter = false;
          k++;
        }
        if (meter)
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
        x1.setEleg(false);

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        x1.setG(x1.getCoste() + x1.getH());

        int k = 0;
        bool meter = true;
        while (k<this->evaluacion_.size()) {
          if(this->evaluacion_[k] == x1)
            meter = false;
          k++;
        }
        if (meter)
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
        x1.setEleg(false);

        if (heure == 1)
          this->establecerH_1(fini, x1);
        if (heure == 2)
          this->establecerH_2(fini, x1);

        x1.setG(x1.getCoste() + x1.getH());

        int k = 0;
        bool meter = true;
        while (k<this->evaluacion_.size()) {
          if(this->evaluacion_[k] == x1)
            meter = false;
          k++;
        }
        if (meter)
          this->evaluacion_.push_back(x1);
        x1.limpiar();

    }

    chosen.limpiar();
    chosen = this->evaluarFrontera(fini);
    vector_elegidos.push_back(chosen);

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

        if (!((pos_actual.i-1 == chosen.getPosPadre().i) && (pos_actual.j == chosen.getPosPadre().j))) {

          aux.i = pos_actual.i-1;
          aux.j = pos_actual.j;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(0); //Arriba
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());
          x1.setEleg(false);

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          x1.setG(x1.getCoste() + x1.getH());

          int k = 0;
          bool meter = true;
          while (k<this->evaluacion_.size()) {
            if(this->evaluacion_[k] == x1)
              meter = false;
            k++;
          }
          if (meter)
            this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      if ((pos_actual.i+1 < mapa.size()) && ((mapa[pos_actual.i+1][pos_actual.j] == ' ') || (mapa[pos_actual.i+1][pos_actual.j] == 'P') || (mapa[pos_actual.i+1][pos_actual.j] == 'X'))) {

        if (!((pos_actual.i+1 == chosen.getPosPadre().i) && (pos_actual.j == chosen.getPosPadre().j))) {

          aux.i = pos_actual.i+1;
          aux.j = pos_actual.j;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(1); //Abajo
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());
          x1.setEleg(false);

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          x1.setG(x1.getCoste() + x1.getH());

          int k = 0;
          bool meter = true;
          while (k<this->evaluacion_.size()) {
            if(this->evaluacion_[k] == x1)
              meter = false;
            k++;
          }
          if (meter)
            this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      if ((pos_actual.j-1 >= 0) && ((mapa[pos_actual.i][pos_actual.j-1] == ' ') || (mapa[pos_actual.i][pos_actual.j-1] == 'P') || (mapa[pos_actual.i][pos_actual.j-1] == 'X'))) {

        if (!((pos_actual.i == chosen.getPosPadre().i) && (pos_actual.j-1 == chosen.getPosPadre().j))) {

          aux.i = pos_actual.i;
          aux.j = pos_actual.j-1;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(2); //Izquierda
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());
          x1.setEleg(false);

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          x1.setG(x1.getCoste() + x1.getH());

          int k = 0;
          bool meter = true;
          while (k<this->evaluacion_.size()) {
            if(this->evaluacion_[k] == x1)
              meter = false;
            k++;
          }
          if (meter)
            this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      if ((pos_actual.j+1 < mapa[0].size()) && ((mapa[pos_actual.i][pos_actual.j+1] == ' ') || (mapa[pos_actual.i][pos_actual.j+1] == 'P') || (mapa[pos_actual.i][pos_actual.j+1] == 'X'))) {

        if (!((pos_actual.i == chosen.getPosPadre().i) && (pos_actual.j+1 == chosen.getPosPadre().j))) {

          aux.i = pos_actual.i;
          aux.j = pos_actual.j+1;

          cost_aux = 1 + chosen.getCoste();
          x1.setCoste(cost_aux);
          x1.setMov(3); //Derecha
          x1.setPos(aux);
          x1.setPosPadre(chosen.getPos());
          x1.setEleg(false);

          if (heure == 1)
            this->establecerH_1(fini, x1);
          if (heure == 2)
            this->establecerH_2(fini, x1);

          x1.setG(x1.getCoste() + x1.getH());

          int k = 0;
          bool meter = true;
          while (k<this->evaluacion_.size()) {
            if(this->evaluacion_[k] == x1)
              meter = false;
            k++;
          }
          if (meter)
            this->evaluacion_.push_back(x1);
          x1.limpiar();

        }

      }

      chosen.limpiar();
      chosen = this->evaluarFrontera(fini);
      vector_elegidos.push_back(chosen);

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

    int end = vector_elegidos.size()-1;
    this->camino_final_.push_back(vector_elegidos.back());
    bool finalizado = false;

    while (!finalizado) {

      for (int i = end; i>=0; i--) {

        if ((vector_elegidos[i].getPos().i == this->camino_final_.back().getPosPadre().i) && (vector_elegidos[i].getPos().j == this->camino_final_.back().getPosPadre().j)) {
          this->camino_final_.push_back(vector_elegidos[i]);
          end = i;
        }
      }

      if (end == 0)
        finalizado = true;
    }

    // std::cout << "\n\tNodo finales ordenados:" << '\n';
    for (int i = this->camino_final_.size()-1; i>=0 ; i--) {

      //std::cout << "\t> " << this->camino_final_[i];
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
