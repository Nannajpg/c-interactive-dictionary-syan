#ifndef file_upload_h
#define file_upload_h

  int existe_archivo(char fname[]);                          //verifica si existe el archivo  
  long int fsize(char fname[]);                              //tamano del archivo
  struct Linea ** cargar_archivo(char fname[],long int size,int num);  //leer el archivo
  int cont_Lineas(char fname[]);
  struct Linea* crearLinea(char *palabra,char * palabraRel,int esSinonimo);

#endif
