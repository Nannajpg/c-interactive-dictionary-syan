#ifndef get_inputed_c
    #define get_inputed_c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "../core/include/errors.h"
    #include "../core/include/constans.h"

    char * getInputed(int *error)
    {
        // TODO: replace 129 for MAX_LENGTH+1
        char input[MAX_LENGTH] = "";
        char * inputChar = (char *) malloc(sizeof(char) * MAX_LENGTH);
        *error = NO_ERRORS;
        fgets(input, sizeof(input), stdin);
        /* Si NO encuentra un line break en el receiver
         * elimina el sobrante del fgetc en stdin */
        if(strchr(input, '\n')) {
            // Elimina el '\n' al final del receiver
            input[strcspn(input, "\n")] = 0;
        }else{
            // Se excedio la cantidad maxima de caracteres
            *error = INPUT_MAX_LENGTH_ERROR;
            while(fgetc(stdin)!='\n');//<--- LIMPIA EL SOBRANTE
        }
        fflush(stdin);
        strcpy(inputChar, input);
        return inputChar;
    }

#endif /* get_inputed_c */
