#ifndef string_formating_utils_c
    #define string_formating_utils_c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    char* formatDoubleToString(char* format, double number) {
      char * resultado = (char *) malloc(45);
      snprintf( resultado, 46, format, number );
      return resultado;
    }

#endif /* string_formating_utils_c */
