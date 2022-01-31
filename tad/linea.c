#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/linea.h"

  char *GetPalabra(struct Linea *linea)
  {
    return linea->palabra;
  }

  char *GetPalabraRel(struct Linea *linea)
  {
    return linea->palabraRel;
  }

  int GetEsSinonimos(struct Linea *linea)
  {
    return linea->esSinonimo;
  }

  char SettPalabra(struct Linea *linea, char *palabraN)
  {
    linea->palabra = palabraN;
  }

  char SettPalabraRel(struct Linea *linea, char *palabraN)
  {
    linea->palabraRel = palabraN;
  }

  int SettEsSinonimos(struct Linea *linea, int value)
  {
      linea->esSinonimo = value;
  }
