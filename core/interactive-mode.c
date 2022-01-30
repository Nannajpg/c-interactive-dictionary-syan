#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "../utils/include/get-inputed.h"
#include "../utils/include/booleans.h"

#include "./include/execute-program.h"
#include "./include/get-error.h"
#include "./include/context.h"
#include "./include/interactive-mode.h"

void interactiveMode(Context* context);

void runInteractiveMode(Context* context) {
  context->enverioment = ENV_INTERACTIVE;
  interactiveMode(context);
}

void displayErrorWhenHasMaxLengthError(Context* context) {
  if(context->error == INPUT_MAX_LENGTH_ERROR)
      printf("Error: se ha ingresado mas caracteres de los permitidos\n      solo se tomaran caracteres hasta el limite permitido (%d)\n", MAX_LENGTH);
}

int isInvalidCommandError(int errorCode) {
    return (errorCode == INVALID_COMMAND_ERROR);
}

void displayErrorWhenHasError(int errorCode) {
    char* errorDisplay = "";
    // Error displayer
    errorDisplay = GetError(errorCode);
    if (strlen(errorDisplay) > 0) printf(">%s\n", errorDisplay);
}

void displayResponseWhenHasResponse(char* response) {
    // Response of Command (If is Neccesary)
    if (strlen(response) > 0) printf(">%s\n", response);
}

void freeResponseMemory(Context* context) {
  if (strlen(context->response) > 0) free(context->response);
}

void continueWhenProgramIsRunning(Context* context) {
  // Vuelve a ejecutar el interactiveModeExecution si es que el
  // programa sigue corriende
  if (context->programIsRunning == TRUE)
    interactiveMode(context);
}

void displayExecutionOutputs(Context* context) {
  if (isInvalidCommandError(context->error)) {
    printf(">Accion invalida.\n");
  }else{
    displayErrorWhenHasError(context->error);
    displayResponseWhenHasResponse(context->response);
  }
}

void getAndResolveInput(Context* context) {
  printf("DICT>");

  getInputed(context->input, &context->error);

  displayErrorWhenHasMaxLengthError(context);
}

void interactiveMode(Context* context) {
  getAndResolveInput(context);

  executeProgram(context);

  displayExecutionOutputs(context);

  freeResponseMemory(context);

  continueWhenProgramIsRunning(context);
}
