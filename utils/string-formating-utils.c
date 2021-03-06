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

    char* getFirstSentenceBySeparator(char* wholeSentence, char separator) {
        char *sp;

        sp = strchr(wholeSentence, separator);
        if (!sp) return wholeSentence;

        return strndup(wholeSentence, sp-wholeSentence); /* Copy chars until space */
    }

    char* getSecondSentenceBySeparator(char* wholeSentence, char separator) {
        char* startOfSecond = strchr(wholeSentence, separator);
        if (!startOfSecond) return NULL;

        return (startOfSecond + 1);
    }

    char* getFirstSecondSentenceBySeparator(char* wholeSentence, char separator) {
        return getFirstSentenceBySeparator(getSecondSentenceBySeparator(wholeSentence, separator), separator);
    }

#endif /* string_formating_utils_c */
