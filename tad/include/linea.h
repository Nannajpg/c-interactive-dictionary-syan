#ifndef linea_h
    #define linea_h


    // linea (Estructura)
struct Linea
  {
      char *palabra;
      char *palabraRel;
      int esSinonimo;
  };

    // Metodos basicos del TDA linea
    char GetPalabra(struct Linea *linea);
    char GetPalabraRel(struct Linea *linea);
    int  GetEsSinonimos(struct Linea *linea);

    char SettPalabra(struct Linea *linea, char *palabraN);
    char SettPalabraRel(struct Linea *linea, char *palabraN);
    int  SettEsSinonimos(struct Linea *linea, int value);

#endif /* linea_h */
