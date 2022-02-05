#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "./include/commands.h"
#include "./include/errors.h"

int isValidInput(char input[]) {
    if (strcmp(input, CARGAR_COMMAND) == 0) return TRUE;
    if (strcmp(input, SINONIMOS_COMMAND) == 0) return TRUE;
    if (strcmp(input, ANTONIMOS_COMMAND) == 0) return TRUE;
    if (strcmp(input, EXPRESSION_COMMAND) == 0) return TRUE;
    if (strcmp(input, AYUDA_COMMAND) == 0) return TRUE;
    if (strcmp(input, QUIT_COMMAND) == 0) return TRUE;
    if (strcmp(input, SINONIMOS_LARGE_COMMAND) == 0) return TRUE;
    if (strcmp(input, ANTONIMOS_LARGE_COMMAND) == 0) return TRUE;
    if (strcmp(input, EXPRESSION_LARGE_COMMAND) == 0) return TRUE;
    return FALSE;
}


char* getCommandByInput(char *input, int *error) {
    *error = NO_ERRORS;

    if (!isValidInput(input)) {
        *error = INVALID_COMMAND_ERROR;
        return NO_COMMAND;
    }

    if (strcmp(input, CARGAR_COMMAND) == 0) return CARGAR_COMMAND;
    if (strcmp(input, SINONIMOS_COMMAND) == 0) return SINONIMOS_COMMAND;
    if (strcmp(input, ANTONIMOS_COMMAND) == 0) return ANTONIMOS_COMMAND;
    if (strcmp(input, EXPRESSION_COMMAND) == 0) return EXPRESSION_COMMAND;
    if (strcmp(input, SINONIMOS_LARGE_COMMAND) == 0) return SINONIMOS_COMMAND;
    if (strcmp(input, ANTONIMOS_LARGE_COMMAND) == 0) return ANTONIMOS_COMMAND;
    if (strcmp(input, EXPRESSION_LARGE_COMMAND) == 0) return EXPRESSION_COMMAND;
    if (strcmp(input, AYUDA_COMMAND) == 0) return AYUDA_COMMAND;
    if (strcmp(input, QUIT_COMMAND) == 0) return QUIT_COMMAND;

    return IMPOSIBLE_COMMAND;
}
