#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./include/get-command-by-input.h"
#include "./include/command-dispatch.h"
#include "./include/context.h"

void executeProgram(Context* context) {
  context->error = NO_ERRORS;
  context->response = "";
  context->commandArgument = "";

  char* firstSentence = getFirstSentence(context->input);
  char* secondSentence = getSecondSentence(context->input);

  context->command = getCommandByInput(firstSentence, &context->error);
  if (secondSentence) {
    context->commandArgument = secondSentence;
  }

  printf("\n DEBUG: %s is First %s is Second \n", firstSentence, secondSentence);

  if (context->error == NO_ERRORS && strcmp(context->command, QUIT_COMMAND) != 0) {
    commandDispatch(context);
  }
}

char* getFirstSentence(char* wholeSentence) {
    char* startOfSecond = strchr(wholeSentence, ' ');
    size_t lengthOfFirst = startOfSecond - wholeSentence;
    char* first = (char*)malloc((lengthOfFirst + 1) * sizeof(char));
    strncpy(first, wholeSentence, lengthOfFirst);
    return first;
}

char* getSecondSentence(char* wholeSentence) {
    char* startOfSecond = strchr(wholeSentence, ' ');
    size_t lengthOfFirst = startOfSecond - wholeSentence;
    size_t lengthOfSecond = wholeSentence - lengthOfFirst;
    char* second = (char*)malloc((lengthOfSecond + 1) * sizeof(char));
    strncpy(second, (wholeSentence + lengthOfFirst + 1), lengthOfSecond);
    return second;
}
