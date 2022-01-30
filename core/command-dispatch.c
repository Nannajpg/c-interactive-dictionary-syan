#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "./include/commands.h"

#include "../commands/include/add-numeric-value.h"
#include "../commands/include/execute-quit-command.h"
#include "./include/context.h"

int isCommand(Context* context, char* command);

void commandDispatch(Context* context) {
    if (isCommand(context, CARGAR_COMMAND)) addNumericValue(context);
    //else if (isCommand(context, SINONIMOS_COMMAND)) addNumericValue(context);
    //else if (isCommand(context, ANTONIMOS_COMMAND)) addNumericValue(context);
    //else if (isCommand(context, EXPRESSION_COMMAND)) addNumericValue(context);
    //else if (isCommand(context, AYUDA_COMMAND)) addNumericValue(context);
    else if (isCommand(context, QUIT_COMMAND)) executeQuitCommand(context);
}

int isCommand(Context* context, char* command) {
  if (strcmp(context->command, command) == 0) return TRUE;
  return FALSE;
}
