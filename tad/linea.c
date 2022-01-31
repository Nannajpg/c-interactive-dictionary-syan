#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/linea.h"

  char *GetPalabra(struct Linea *Linea)
  {
    return Linea->palabra;
  }

  char *getPalabraRel(struct Linea *Linea)
  {
    return Linea->palabraRel;
  }

  int  GetEsSinonimos(struct linea *Linea)
  {
    return Linea->esSinonimo;
  }

  char SettPalabra(struct linea *Linea, char *palabraN)
  {
    Linea->palabra = palabraN;
  }

  char SettPalabraRel(struct Linea *Linea, char *palabraN)
  {
    Linea->palabraRel = palabraN;
  }

  int SettEsSinonimos(struct Linea *Linea, int value)
  {
      Linea->esSinonimo = value;
  }
