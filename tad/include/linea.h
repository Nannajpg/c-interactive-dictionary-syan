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
    char GetPalabra(struct Linea *Linea);
    char GetPalabraRel(struct Linea *Linea);
    int  GetEsSinonimos(struct Linea *Linea);

    char SettPalabra(struct Linea *linea, char *palabraN);
    char SettPalabraRel(struct Linea *Linea, char *palabraN);
    int  SettEsSinonimos(struct Linea *Linea, int value);

#endif /* linea_h */
