#ifndef linea_h
    #define linea_h


    // linea (Estructura)
struct linea
  {
      char *palabra;
      char *palabraRel;
      int esSinonimo;
  };

    // Metodos basicos del TDA linea
    char GetPalabra(struct linea *linea);
    char GetPalabraRel(struct linea *linea);
    int  GetEsSinonimos(struct linea *linea);

    char SettPalabra(struct linea *linea, char *palabraN);
    char SettPalabraRel(struct linea *linea, char *palabraN);
    int  SettEsSinonimos(struct linea *linea, int value);

#endif /* linea_h */
