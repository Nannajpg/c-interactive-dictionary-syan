#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./include/get-command-by-input.h"
#include "./include/command-dispatch.h"
#include "./include/context.h"


char* getFirstSentence(char* wholeSentence, char separator) {
    char* startOfSecond = strchr(wholeSentence, separator);
    if (!startOfSecond) return wholeSentence;

    size_t lengthOfFirst = startOfSecond - wholeSentence;
    char* first = (char*)malloc((lengthOfFirst + 1) * sizeof(char));
    strncpy(first, wholeSentence, lengthOfFirst);
    return first;
}

char* getSecondSentence(char* wholeSentence, char separator) {
    char* startOfSecond = strchr(wholeSentence, separator);
    if (!startOfSecond) return NULL;

    return (startOfSecond + 1);
}

void dispatchCommandWhenNoErrors(Context* context) {
  if (context->error == NO_ERRORS) {
    commandDispatch(context);
  }
}

void executeProgram(Context* context) {
  context->error = NO_ERRORS;
  context->response = "";
  context->commandArgument = "";

  char* firstSentence = getFirstSentence(context->input, ' ');
  char* secondSentence = getSecondSentence(context->input, ' ');

  context->command = getCommandByInput(firstSentence, &context->error);
  if (secondSentence) {
    context->commandArgument = secondSentence;
  }

  dispatchCommandWhenNoErrors(context);
}
