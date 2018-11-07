////////////////////////////////////////////
//Includes

#ifndef COCHE
#define COCHE

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

////////////////////////////////////////////

class Coche {

private:

  char simbolo_coche_;
  int i_;
  int j_;
  int personas_recogidas_;

public:

  Coche();
  Coche(const Coche&);
  ~Coche();

  char getSimb () const;
  int getI () const;
  int getJ () const;
  
  int getPRecogidas () const;
  void setPRecogidas ();

  void setPos (int, int);

  void mover (std::vector<std::vector<char> >&);

  //Algoritmos

  friend std::ostream& operator<< (std::ostream&, const Coche&);

};

////////////////////////////////////////////

#endif
