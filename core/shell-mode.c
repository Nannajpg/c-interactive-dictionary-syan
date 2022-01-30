#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "../utils/include/get-inputed.h"
#include "../utils/include/booleans.h"

#include "./lib/include/errors-helper.h"
#include "./lib/include/get-error.h"
#include "./include/execute-program.h"
#include "./include/context.h"
#include "./include/shell-mode.h"
#include "./include/is-arguable-command.h"

void shellMode(Context* context, int argQuantity, char* arg[]);

void runShellMode(Context* context, int argQuantity, char* arg[]) {
  context->enverioment = ENV_SHELL;
  shellMode(context, argQuantity, arg);
}

void shellMode(Context* context, int argQuantity, char* arg[]) {
  char* errorDisplay = "";
  char* lastResponse = "";
  int hasError = FALSE;

  for (int i = 1; i < argQuantity; i++) {

    strcpy(context->input, arg[i]);
    if (isArguableCommandInput(arg[i]) && (i + 1) < argQuantity) {
      strcat(context->input, " ");
      i++;
      strcat(context->input, arg[i]);
    }

    executeProgram(context);

    if (isInvalidCommandError(INVALID_COMMAND_ERROR)) {
      printf("Comando o accion invalida '%s' en el argumento %i\n", context->input, i);
      hasError = TRUE;
      break;
    }else{
      errorDisplay = GetError(context->error);
      if (strlen(errorDisplay) > 0) {
        hasError = TRUE;
        printf("Error en argumento '%s' numero %i: %s\n", context->input, i, errorDisplay);
        break;
      }

      if (strlen(context->response) > 0) lastResponse = context->response;
    }

    if (!context->programIsRunning) {
      hasError = TRUE;
      break;
    }
  }

  if (strlen(lastResponse) > 0 && !hasError) {
    printf("%s\n", lastResponse);
    free(lastResponse);
  }

}
