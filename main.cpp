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

  Tablero map(10, 20);
  map.redimensionar();

  map.colocarCoche();
  map.rellenarObstaculos();
  map.rellenarPersonas();

  for (int i = 0; i < 300; i++) {

    map.moverCoche();
    std::cout << "\x1B[2J\x1B[H";
    std::cout << map << '\n';
    delay(DELAY);

  }

  // std::cout << "\n\tPRESIONE RETORNO DE CARRO PARA SALIR DEL PROGRAMA";
  // std::cin.get();
  // std::cout << "\x1B[2J\x1B[H";
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Funcion de delay

void delay (double secs){

  for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));

}
