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
        char* startOfSecond = strchr(wholeSentence, separator);
        if (!startOfSecond) return wholeSentence;

        size_t lengthOfFirst = startOfSecond - wholeSentence;
        char* first = (char*)malloc((lengthOfFirst + 1) * sizeof(char));
        strncpy(first, wholeSentence, lengthOfFirst);
        return first;
    }

    char* getSecondSentenceBySeparator(char* wholeSentence, char separator) {
        char* startOfSecond = strchr(wholeSentence, separator);
        if (!startOfSecond) return NULL;

        return (startOfSecond + 1);
    }

#endif /* string_formating_utils_c */
