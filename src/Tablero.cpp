////////////////////////////////////////////
//Includes

#include "Tablero.h"

///////////////////////////////////////////
// Constructor por defecto

Tablero :: Tablero (void) :

  por_obs_(0.0)

{}

///////////////////////////////////////////
// Constructor por parametros

Tablero :: Tablero (int row, int col) {

  this->mapa_.clear();
  this->mapa_.resize(row);

  for (int i = 0; i < row; i++){

    this->mapa_[i].clear();
    this->mapa_[i].resize(col);

  }

}

/////////////////////////////////////////////
// Constructor de copia

Tablero :: Tablero (const Tablero& board) :

  car_(board.car_)

{

  mapa_ = board.mapa_;
  pasajeros_ = board.pasajeros_;
  pos_inicial_coche_ = board.pos_inicial_coche_;
  pos_final_coche_ = board.pos_final_coche_;
  por_obs_ = board.por_obs_;

}

////////////////////////////////////////////
// Destructor

Tablero :: ~Tablero () {}

////////////////////////////////////////////
// Funcion get

int Tablero :: getRow (void) const{

  return (this->mapa_.size());

}

int Tablero :: getCol (void) const{

  return (this->mapa_[0].size());

}

char Tablero :: getSimbTab (int i, int j) const{

  return (this->mapa_[i][j]);

}

std::vector<pasajeros> Tablero :: getVPasajeros () const{

  return (this->pasajeros_);

}

Coche Tablero :: getCoche (void) const {

  return (this->car_);

}

float Tablero :: getPorObs (void) const{

  return (this->por_obs_);

}

///////////////////////////////////////////////
//Funciones para establecer las rows and col

void Tablero :: setRow (int n) {

  this->mapa_.resize(n);

}

void Tablero :: setCol (int m) {

  for (size_t i = 0; i < this->getRow(); i++)
    this->mapa_[i].resize(m);

}

void Tablero :: setPosTab (int i, int j, char x) {

  this->mapa_[i][j] = x;

}

void Tablero :: setPorObs (float per) {

  this->por_obs_ = per;

}

//////////////////////////////////////////////////
//Funcion para redimensionar el tablero

void Tablero :: redimensionar (void) {

  char option;

  do {

    std::cout << "\n\tEl tablero esta definido a " << this->getRow() << " x " << this->getCol() << '\n';
    std::cout << "\t¿Desea cambiar el tamanio? (y/n): ";
    std::cin >> option; std::cin.get();

    switch (option) {

      case 'y':{

        int n = 0, m = 0;

        std::cout << "\tFilas: ";
        std::cin >> n; std::cin.get();
        std::cout << "\tColumna: ";
        std::cin >> m; std::cin.get();

        this->setRow(n);
        this->setCol(m);

        break;
      }

      case 'n':{
        break;
      }

      default:{
        std::cout << "\n\tOpcion invalida" << '\n';
        break;
      }

    }

  } while ( (option!='y') && (option!='n') );

  for (int i = 0; i < this->getRow(); i++){

    for (int j = 0; j < this->getCol(); j++) {

      this->mapa_[i][j] = ' ';

    }

  }

}

/////////////////////////////////////////////////////
//Funcion para colocar el coche de manera aleatoria o manual

void Tablero :: colocarCoche (void) {

  char option;

  do {

    std::cout << "\n\tTablero de " << this->getRow() << " x " << this->getCol() << '\n';
    std::cout << "\t¿Desea introducir la posicion del COCHE Manual o Aleatorio? (m/a): ";
    std::cin >> option; std::cin.get();

    switch (option) {

      case 'm':{

        // Introducir el coche de forma manual

        int i, j;
        bool correcto = true;

        do {

          correcto = true;

          std::cout << "\n\tCoordenada inicial i [0, " << this->getRow()-1 << "]: ";
          std::cin >> i; std::cin.get();
          std::cout << "\tCoordenada inicial j [0, " << this->getCol()-1 << "]: ";
          std::cin >> j; std::cin.get();

          if ( (i < 0) || (i > this->getRow()) || (j < 0) || (j > this->getCol()) ) {

            std::cout << "\n\t╳ Coordenadas inválidas" << '\n';
            correcto = false;

          }

        }while(!correcto);

        this->car_.setPos(i, j);
        this->setPosInicial(i, j);

        this->setPosTab(i, j, this->car_.getSimb());

        do {

          correcto = true;

          std::cout << "\n\tCoordenada final i [0, " << this->getRow()-1 << "]: ";
          std::cin >> i; std::cin.get();
          std::cout << "\tCoordenada final j [0, " << this->getCol()-1 << "]: ";
          std::cin >> j; std::cin.get();

          if ( (i < 0) || (i > this->getRow()) || (j < 0) || (j > this->getCol()) ) {

            std::cout << "\n\t╳ Coordenadas inválidas" << '\n';
            correcto = false;

          }

        }while(!correcto);

        this->setPosFinal(i, j);

        break;
      }

      case 'a':{

        //Introducir el coche de forma Aleatoria

        int i, j;

        srand(time(NULL));

        i = rand() % this->getRow();
        j = rand() % this->getCol();

        this->car_.setPos(i, j);
        this->setPosInicial(i, j);

        this->setPosTab(i, j, this->car_.getSimb());

        srand(time(NULL)*i);

        i = rand() % this->getRow();
        j = rand() % this->getCol();

        this->setPosFinal(i, j);

        break;
      }

      default:{

        std::cout << "╳ Opcion invalida" << '\n';
        break;
      }

    }

  } while ( (option!='m') && (option!='a') );

}

///////////////////////////////////////////////////////
// Funciones para establecer las funciones del coche

void Tablero :: setPosInicial (int posi, int posj){

  this->pos_inicial_coche_.i = posi;
  this->pos_inicial_coche_.j = posj;

  this->car_.setInicio(pos_inicial_coche_);

}

void Tablero :: setPosFinal (int posi, int posj){

  this->pos_final_coche_.i = posi;
  this->pos_final_coche_.j = posj;

  this->setPosTab(posi, posj, 'X');

  this->car_.setFin(pos_final_coche_);

}

//////////////////////////////////////////////////////
// Funciones para recoger los valores de la pos inicial y final

posicion Tablero :: getPosInicial (void) const{

  return this->pos_inicial_coche_;

}

posicion Tablero :: getPosFinal (void) const{

  return this->pos_final_coche_;

}

//////////////////////////////////////////////////////
// Funcion para colocar los obstaculos (%)

void Tablero :: rellenarObstaculos (void) {

  char option;

  do {

    std::cout << "\n\tEstablecido el no. de obstaculos al 0,3 del tablero";

    this->setPorObs(0.3);

    int n_obs = ((this->getRow()*this->getCol()) * this->getPorObs());

    std::cout << " (" << n_obs << " obstaculos)\n";
    std::cout << "\t¿Desea introducir los OBSTACULOS de forma Manual o Aleatoria? (m/a): ";
    std::cin >> option; std::cin.get();

    switch (option) {

      case 'm':{

        //Introducir los obstaculos de manera manual

        char option2;

        do {

          std::cout << "\t¿Desea introducir los OBSTACULOS por Teclado o Fichero? (t/f): ";
          std::cin >> option2; std::cin.get();

          switch (option2) {

            case 'f': {

              std::string fich_entrada;

              std::cout << "\n\tIntroduzca el nombre del fichero con la posicion: ";
              std::cin >> fich_entrada; std::cin.get();

              std::ifstream fich;
              fich.open(fich_entrada.c_str());

              if (fich.is_open()) {

                fich >> n_obs;

                for (int i = 0; i < n_obs; i++) {

                  // Los indices que se leeran de teclado seran dentro del intervalo [1, 20]

                  int inx = 0, jnx = 0;

                  fich >> inx >> jnx;

                  if ( (this->getSimbTab(inx-1, jnx-1) != 'C') )
                    this->setPosTab(inx-1, jnx-1, '#');

                }

                fich.close();

              }
              else {

                  std::cerr << "\nError en la apertura del fichero, asegúrese que ha escrito bien el nombre del fichero\n";

              }

              break;
            }

            case 't': {

              std::cout << "\n\tNumero de obstaculos: ";
              std::cin >> n_obs; std::cin.get();

              int inx = 0, jnx = 0;

              std::cout << "\tIntroduzca la coordenada [i, j] dentro del intervalo [" << this->getRow() << ", " << this->getCol() << "]\n";

              for (int i = 0; i < n_obs; i++){

                std::cout << "\t> ";
                std::cin >> inx >> jnx; std::cin.get();

                if ( (this->getSimbTab(inx-1, jnx-1) != 'C') )
                  this->setPosTab(inx-1, jnx-1, '#');

              }

              break;
            }

            default:{

              std::cout << "\n\t╳ Opcion invalida" << '\n';
              break;
            }

          }

        } while((option2!='f') && (option2!='t'));

        break;
      }

      case 'a':{

        //Introducir los obstaculos de forma aletoria conforme a una proporcion

        int inx, jnx, acu=0;

        for (int i = 0; i < n_obs; i++) {

          srand(time(NULL)+acu);

          inx = rand() % this->getRow();
          jnx = rand() % this->getCol();

          if (this->getSimbTab(inx, jnx) == '#') {
            i--;
          } else if (this->getSimbTab(inx, jnx) == 'C') {
            i--;
          } else if ((this->getPosInicial().i == inx) && (this->getPosInicial().j == jnx)) {
            i--;
          } else if ((this->getPosFinal().i == inx) && (this->getPosFinal().j == jnx)) {
            i--;
          } else {
            this->setPosTab(inx, jnx, '#');
          }

          acu++;

        }

        break;
      }

      default:{

        std::cout << "\n\t╳ Opcion invalida" << '\n';
        break;
      }

    }

  } while ( (option!='m') && (option!='a') );

}

/////////////////////////////////////////////////////////////
// Funcion para colocar las personas que tendra que recoger el coche

void Tablero :: rellenarPersonas (void) {

  char option;

  do {

    std::cout << "\n\tEstablecido el no. de pasajeros a 5";

    int n_pas = 5;

    std::cout << "\n\t¿Desea introducir los PASAJEROS de forma Manual o Aleatoria? (m/a): ";
    std::cin >> option; std::cin.get();

    switch (option) {

      case 'm':{

        //Introducir los pasajeros de manera manual

        int inx = 0, jnx = 0;

        std::cout << "\n\tIntroduzca la coordenada [i, j] dentro del intervalo [" << this->getRow() << ", " << this->getCol() << "]\n";

        for (int i = 0; i < n_pas; i++){

          std::cout << "\t> ";
          std::cin >> inx >> jnx; std::cin.get();

          if ( (this->getSimbTab(inx-1, jnx-1) != 'C') )
            this->setPosTab(inx-1, jnx-1, 'P');
          else {

            std::cout << "\n\tEl pasajero " << i+1 << " coincide con la pos. inicial del coche";
            std::cout << "\n\tIntroduzca de nuevo dicho pasajero." << '\n';
            i--;

          }

        }

        break;
      }

      case 'a':{

        //Introducir los pasajeros de forma aleatoria

        int inx, jnx, acu=0;

        for (int i = 0; i < n_pas; i++) {

          srand(time(NULL)+acu);

          inx = rand() % this->getRow();
          jnx = rand() % this->getCol();

          if (this->getSimbTab(inx, jnx) == '#')
            i--;
          else{
            if (this->getSimbTab(inx, jnx) == 'C')
              i--;
            else{

              pasajeros aux;

              aux.posi = inx;
              aux.posj = jnx;
              aux.recogido = false;

              this->setPosTab(inx, jnx, 'P');

              this->pasajeros_.push_back(aux);

            }

          }

          acu++;

        }

        break;
      }

      default:{
        std::cout << "\n\t╳ Opcion invalida" << '\n';
        break;
      }

    }

  } while ( (option!='m') && (option!='a') );

}

//////////////////////////////////////////////////////
// Funcion para calcular el Camino

void Tablero :: hallarCamino (int heure) {

  this->car_.calcularCamino(this->mapa_, this->pos_inicial_coche_, this->pos_final_coche_, heure);

}

/////////////////////////////////////////////////////
//Funcion para mover el COCHE

void Tablero :: moverCoche (int direccion) {

  this->car_.mover(this->mapa_, direccion);

}

/////////////////////////////////////////////////////
// Sobrecarga del operador salida para tablero_t

std::ostream& operator<< (std::ostream& os, const Tablero& map){

  os << std::endl << "\t";

  for (int i = 0; i < map.getCol(); i++){

    if (i == 0)	os << "\033[0;97m――\033[0m";

    os << "\033[0;97m―\033[0m";

  }

  os << std::endl;

  for (int i = 0; i < map.getRow(); i++){

    os << "\t\033[0;97m│\033[0m";

    for (int j = 0; j < map.getCol(); j++) {

      switch (map.getSimbTab(i,j)) {

        case '#':{

          os << "\033[0;91m" << map.getSimbTab(i,j) <<"\033[0m";

          break;
        }

        case 'P':{

          os << "\033[0;34m" << map.getSimbTab(i,j) <<"\033[0m";

          break;
        }

        case 'C':{

          os << "\033[0;93m" << map.getSimbTab(i,j) <<"\033[0m";

          break;
        }

        case '+':{

          os << "\033[0;97m" << map.getSimbTab(i,j) <<"\033[0m";

          break;
        }

        default: {

          os << "\033[0;93m" << map.getSimbTab(i,j) <<"\033[0m";

          break;
        }

      }

    }

    os << "\033[0;97m│\033[0m" << std::endl;

  }

  for (int i = 0; i < map.getCol(); i++){

    if (i == 0)	os << "\t\033[0;97m――\033[0m";

    os << "\033[0;97m―\033[0m";

  }

  os << std::endl;

  os << "\n\tInicio: [" << map.getPosInicial().i << ", " << map.getPosInicial().j << "]";
  os << " -- Final: [" << map.getPosFinal().i << ", " << map.getPosFinal().j << "]";

  return os;

}

/////////////////////////////////////////////
