#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "./include/commands.h"

#include "../tad/include/context.h"

#include "../commands/include/execute-cargar-command.h"
#include "../commands/include/execute-sinonimos-command.h"
#include "../commands/include/execute-antonimos-command.h"
#include "../commands/include/execute-expression-command.h"
#include "../commands/include/execute-quit-command.h"
#include "../commands/include/execute-help-command.h"


int isCommand(Context* context, char* command);

void commandDispatch(Context* context) {
    if (isCommand(context, CARGAR_COMMAND)) executeCargarCommand(context);
    else if (isCommand(context, SINONIMOS_COMMAND)) executeSinonimosCommand(context);
    else if (isCommand(context, ANTONIMOS_COMMAND)) executeAntonimosCommand(context);
    else if (isCommand(context, EXPRESSION_COMMAND)) executeExpressionCommand(context);
    else if (isCommand(context, AYUDA_COMMAND)) executeHelpCommand(context);
    else if (isCommand(context, QUIT_COMMAND)) executeQuitCommand(context);
}

int isCommand(Context* context, char* command) {
  if (strcmp(context->command, command) == 0) return TRUE;
  return FALSE;
}
