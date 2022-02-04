#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./include/file_upload.h"
#include "../tad/include/linea.h"
#include "../utils/include/string-formating-utils.h"

int existe_archivo(char fname[]) { 
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

int cont_Lineas(char fname[]){
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

struct Linea ** cargar_archivo(char fname[],long int size, int num) {
    FILE *archivo = fopen(fname,"r"); 
    char c[size];
    int i = 0;
    struct Linea ** listaLineas = NULL;
    listaLineas = (struct Linea **)malloc(sizeof(listaLineas) * (num+2));//structs xp

    if(archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return NULL;
    }         
    else {  
        while(!feof(archivo)) {
            fgets(c,65,archivo);  
                c[strcspn(c, "\r\n")] = 0; 
                    if(c[0] == 'S') { 
                        
                        listaLineas[i] = crearLinea(getFirstSentenceBySeparator((c+2),' '),getSecondSentenceBySeparator((c+2),' '), 1);
                    }
                    else if(c[0] == 'A'){
                         listaLineas[i] = crearLinea(getFirstSentenceBySeparator((c+2),' '),getSecondSentenceBySeparator((c+2),' '), 0);
                    }
                    i++;
                //printf("%s\n",getSecondSentenceBySeparator((c+2),' ')); 

        }listaLineas[i] = NULL;
    }
    return listaLineas;             
}
