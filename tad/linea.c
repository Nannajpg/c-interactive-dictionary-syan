#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/linea.h"

  char *GetPalabra(struct linea *linea)
  {
    return linea->palabra;
  }

  char *getPalabraRel(struct linea *linea)
  {
    return linea->palabraRel;
  }

  int  GetEsSinonimos(struct linea *linea)
  {
    return linea->esSinonimo;
  }

  char SettPalabra(struct linea *linea, char *palabraN)
  {
    linea->palabra = palabraN;
  }

  char SettPalabraRel(struct linea *linea, char *palabraN)
  {
    linea->palabraRel = palabraN;
  }

  int SettEsSinonimos(struct linea *linea, int value)
  {
      linea->esSinonimo = value;
  }
