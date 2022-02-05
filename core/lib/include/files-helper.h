#ifndef files_helper_h
#define files_helper_h 
 
  int existeArchivo(char fname[]);                       //Verifica si existe el archivo  
  int contarLineasArchivo(char fname[]);
  struct Linea ** cargarArchivoPorNombre(char fname[]);  //Leer el archivo

#endif