#ifndef linea_h
#define linea_h

  // linea (Estructura)
  struct Linea {
    char *palabra;
    char *palabraRel;
    int esSinonimo;
  };

    // Metodos basicos del TDA linea
  
    struct Linea* crearLinea(char *palabra,char * palabraRel,int esSinonimo);

    char getPalabra(struct Linea *linea);
    char getPalabraRel(struct Linea *linea);
    int  getEsSinonimos(struct Linea *linea);

    char setPalabra(struct Linea *linea, char *palabraN);
    char setPalabraRel(struct Linea *linea, char *palabraN);
    int  setEsSinonimos(struct Linea *linea, int value);

#endif /* linea_h */
