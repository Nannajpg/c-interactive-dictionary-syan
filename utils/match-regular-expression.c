#ifndef match_regular_expression_c
    #define match_regular_expression_c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <regex.h>

    int matchRegularExpression(char* expression, char* word) {
      regex_t regex;
      int reti;
      char msgbuf[100];

      /* Compilar expression regular */
      reti = regcomp(&regex, expression, 0);
      if (reti) return -2;

      /* Ejecutar expresion regular */
      reti = regexec(&regex, word, 0, NULL, 0);

      if (!reti) return 1;

      if (reti == REG_NOMATCH) return 0;

      regerror(reti, &regex, msgbuf, sizeof(msgbuf));
      regfree(&regex);
      return -1;
    }

#endif
