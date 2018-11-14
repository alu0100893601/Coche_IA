///////////////////////////////////////////////////////////////////////////
//Includes

#include <stdio.h>
#include "Tablero.h"

#define DELAY 1
void delay (double);

///////////////////////////////////////////////////////////////////////////
//Programa principal

int main(int argc, char const *argv[]) {

  std::cout << "\x1B[2J\x1B[H";
  std::cout << "\n\tInteligencia Artificial.";
  std::cout << "\n\tCoche autónomo.";
  std::cout << "\n\tPRESIONE RETORNO DE CARRO PARA CONTINUAR";
  std::cin.get();

  std::cout << "\x1B[2J\x1B[H";

  Tablero map(30, 140);
  map.redimensionar();

  map.colocarCoche();
  map.rellenarObstaculos();
  map.rellenarPersonas();

  Tablero map2(map);

  std::cout << "\n\tSituacion inicial en el mapa:" << '\n';
  std::cout << map << '\n';

  map.hallarCamino(1); //Distancia euclidea
  std::cin.get();

  for (int i = 1; i < map.getCoche().getMovements().size(); i++) {

    map.moverCoche(map.getCoche().getMovements()[i]);
    std::cout << "\x1B[2J\x1B[H";
    // std::cout << map << '\n';
    // delay(DELAY);

  }

  std::cout << map << '\n';

  std::cout << "\n\t\e[4m+ Memoria - heuristica distancia euclidea +\e[0m\n";
  std::cout << "\n\tInicio: [" << map.getPosInicial().i << ", " << map.getPosInicial().j << "]\n";
  std::cout << " -- Final: [" << map.getPosFinal().i << ", " << map.getPosFinal().j << "]";
  std::cout << "\tDimension: " << map.getRow() << " x " << map.getCol() << '\n';
  std::cout << "\tObstaculos: " << map.getPorObs()*100 << "%\n";
  std::cout << "\tNodos generados: " << map.getCoche().getTotalGenerado() << '\n';
  std::cout << "\tLongitud del camino: " << map.getCoche().getMovements().size() << '\n';
  std::cout << "\tPersonas recogidas: " << map.getCoche().getPRecogidas() << '\n';
  std::cout << "\n\tPRESIONE RETORNO DE CARRO PARA REALIZAR LA SIGUIENTE PRUEBA HEURISTICA";
  std::cin.get();

  map.getCoche().resetPRecogidas();

  std::cout << "\x1B[2J\x1B[H";
  std::cout << "\n\tSituación inicial en el mapa:" << '\n';
  std::cout << map2 << '\n';

  map2.hallarCamino(2); //Distancia rectilinia
  std::cin.get();

  for (int i = 1; i < map.getCoche().getMovements().size(); i++) {

    map2.moverCoche(map2.getCoche().getMovements()[i]);
    std::cout << "\x1B[2J\x1B[H";
    //std::cout << map2 << '\n';
    //delay(DELAY);

  }

  std::cout << map2 << '\n';

  std::cout << "\n\t\e[4m+ Memoria - heuristica distancia rectilinea +\e[0m\n";
  std::cout << "\n\tInicio: [" << map2.getPosInicial().i << ", " << map2.getPosInicial().j << "]";
  std::cout << " -- Final: [" << map2.getPosFinal().i << ", " << map2.getPosFinal().j << "]\n";
  std::cout << "\tDimension: " << map2.getRow() << " x " << map2.getCol() << '\n';
  std::cout << "\tObstaculos: " << map2.getPorObs()*100 << "%\n";
  std::cout << "\tNodos generados: " << map2.getCoche().getTotalGenerado() << '\n';
  std::cout << "\tLongitud del camino: " << map2.getCoche().getMovements().size() << '\n';
  std::cout << "\tPersonas recogidas: " << map2.getCoche().getPRecogidas() << '\n';
  std::cout << "\n\tPRESIONE RETORNO DE CARRO PARA SALIR DEL PROGRAMA";
  std::cin.get();
  std::cout << "\x1B[2J\x1B[H";

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Funcion de delay

void delay (double secs){

  for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));

}
