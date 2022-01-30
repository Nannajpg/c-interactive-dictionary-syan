#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "./include/commands.h"
#include "./include/errors.h"

int isArguableCommandInput(char input[]) {
    if (strcmp(input, CARGAR_COMMAND) == 0) return TRUE;
    if (strcmp(input, SINONIMOS_COMMAND) == 0) return TRUE;
    if (strcmp(input, ANTONIMOS_COMMAND) == 0) return TRUE;
    if (strcmp(input, EXPRESSION_COMMAND) == 0) return TRUE;
    return FALSE;
}
