#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/linea.h"

struct Linea* crearLinea(char *palabra,char * palabraRel,int esSinonimo) {
  struct Linea *pNode = NULL;
  pNode = (struct Linea *) malloc(sizeof(struct Linea));
  //pNode->palabra = palabra;
  pNode->palabraRel = malloc(sizeof(pNode->palabraRel )*100);
  pNode->palabra = malloc(sizeof(pNode->palabra )*100);
  strcpy(pNode->palabraRel , palabraRel);
  strcpy(pNode->palabra , palabra);
  pNode->esSinonimo = esSinonimo;
   
  return pNode;
}

  char *getPalabra(struct Linea *linea){
    return linea->palabra;
  }

  char *getPalabraRel(struct Linea *linea){
    return linea->palabraRel;
  }

  int getEsSinonimos(struct Linea *linea){
    return linea->esSinonimo;
  }

  char setPalabra(struct Linea *linea, char *palabraN){
    linea->palabra = palabraN;
  }

  char setPalabraRel(struct Linea *linea, char *palabraN){
    linea->palabraRel = palabraN;
  }

  int setEsSinonimos(struct Linea *linea, int value){
      linea->esSinonimo = value;
  }
