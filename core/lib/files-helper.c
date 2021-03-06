#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./include/files-helper.h"
#include "../../tad/include/linea.h"
#include "../../utils/include/string-formating-utils.h"

struct Linea ** cargarArchivo(char fname[],long int size, int num);

long int fsize(char fname[]);   //tamano del archivo
struct Linea ** cargarArchivo(char fname[],long int size, int num);

int existeArchivo(char fname[]) {
    if(access(fname, F_OK) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

long int fsize(char fname[]) {
    FILE* archivo = fopen(fname, "r");

    if(archivo != NULL) {

        fseek(archivo, 0L, SEEK_END);
        long int size = ftell(archivo);
        fclose(archivo);
        return size;
    }
    else {
        return -1;
    }
}

int contarLineasArchivo(char fname[]){
    FILE *archivo = fopen(fname,"r");
    int cont = 0;
    char linea[65];

    if(archivo == NULL) {
        return -1;
    }
    else {
        while(!feof(archivo)) {
            fgets(linea,65,archivo);
            cont++;
        }
    return cont;
    }
}

struct Linea ** cargarArchivoPorNombre(char fname[]) {
   int size = fsize(fname);
   int num = contarLineasArchivo(fname);
   return cargarArchivo(fname, size, num);
};

int getSpacesInString(char * word) {
  int spaces = 0;
  for(int i = 0; word[i] != '\0'; i++)
  {
      if (word[i] == ' ')
      {
           spaces++;
      }
  }
  return spaces;
}

struct Linea ** cargarArchivo(char fname[],long int size, int num) {
    FILE *archivo = fopen(fname,"r");
    char c[size];
    int i = 0;
    struct Linea ** listaLineas = NULL;
    listaLineas = (struct Linea **)malloc(sizeof(listaLineas) * (num+2));

    if(archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return NULL;
    }
    else {
        while(!feof(archivo)) {
            fgets(c,65,archivo);
                c[strcspn(c, "\r\n")] = 0;
                    if (getSpacesInString(c) >= 2 && (c[0] == 'S' || c[0] == 'A' || c[0] == 's' || c[0] == 'a')) {
                      if(c[0] == 'S' || c[0] == 's') {
                          listaLineas[i] = crearLinea(getFirstSentenceBySeparator((c+2),' '),getFirstSecondSentenceBySeparator((c+2),' '), 1);
                      }
                      else if(c[0] == 'A' || c[0] == 'a'){
                           listaLineas[i] = crearLinea(getFirstSentenceBySeparator((c+2),' '),getFirstSecondSentenceBySeparator((c+2),' '), 0);
                      }
                      i++;
                    }
        }listaLineas[i] = NULL;
    }
    return listaLineas;
}
