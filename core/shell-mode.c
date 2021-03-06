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
#include "./include/shell-mode.h"
#include "./include/is-arguable-command.h"

#include "../tad/include/context.h"

void shellMode(Context* context, int argQuantity, char* arg[]);

void runShellMode(Context* context, int argQuantity, char* arg[]) {
  setEnvironment(context, ENV_SHELL);
  shellMode(context, argQuantity, arg);
}

void shellMode(Context* context, int argQuantity, char* arg[]) {
  char* errorDisplay = "";
  char* lastResponse = "";
  int hasError = FALSE;

  for (int i = 1; i < argQuantity; i++) {

    strcpy(getInput(context), arg[i]);
    if (isArguableCommandInput(arg[i]) && (i + 1) < argQuantity) {
      strcat(getInput(context), " ");
      i++;
      strcat(getInput(context), arg[i]);
    }

    executeProgram(context);

    if (isInvalidCommandError(getContextCodeError(context))) {
      printf("Comando o accion invalida '%s' en el argumento %i\n", getInput(context), i);
      hasError = TRUE;
      break;
    }else{
      errorDisplay = GetError(getContextCodeError(context));
      if (strlen(errorDisplay) > 0) {
        hasError = TRUE;
        printf("Error en argumento '%s' numero %i: %s\n", getInput(context), i, errorDisplay);
        break;
      }

      if (strlen(getResponse(context)) > 0) lastResponse = getResponse(context);
    }

    if (!isProgramRunning(context)) {
      hasError = TRUE;
      break;
    }
  }

  if (strlen(lastResponse) > 0 && !hasError) {
    printf("%s\n", lastResponse);
    free(lastResponse);
  }
}
