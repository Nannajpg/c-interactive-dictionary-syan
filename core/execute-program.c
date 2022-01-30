#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "../utils/include/string-formating-utils.h"
#include "./include/get-command-by-input.h"
#include "./include/command-dispatch.h"
#include "./include/context.h"

void dispatchCommandWhenNoErrors(Context* context);

void executeProgram(Context* context) {
  context->error = NO_ERRORS;
  context->response = "";
  context->commandArgument = "";

  char* firstSentence = getFirstSentenceBySeparator(context->input, ' ');
  char* secondSentence = getSecondSentenceBySeparator(context->input, ' ');

  context->command = getCommandByInput(firstSentence, &context->error);
  if (secondSentence) {
    context->commandArgument = secondSentence;
  }

  dispatchCommandWhenNoErrors(context);
}

void dispatchCommandWhenNoErrors(Context* context) {
  if (context->error == NO_ERRORS) {
    commandDispatch(context);
  }
}
