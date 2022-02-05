#ifndef files_helper_h
#define files_helper_h 
 
  int existeArchivo(char fname[]);                       //verifica si existe el archivo  
  int contarLineasArchivo(char fname[]);
  struct Linea ** cargarArchivoPorNombre(char fname[]);  //leer el archivo
  //struct Linea ** cargarArchivo(char fname[],long int size,int num);    //leer el archivo
  //struct Linea* crearLinea(char *palabra,char * palabraRel,int esSinonimo);

#endif