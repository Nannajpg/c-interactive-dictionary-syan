#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "../tad/include/context.h"

#include "../utils/include/string-formating-utils.h"
#include "./include/get-command-by-input.h"
#include "./include/command-dispatch.h"

void dispatchCommandWhenNoErrors(Context* context);

void executeProgram(Context* context) {
  setContextCodeError(context, NO_ERRORS);
  setSimpleResponse(context, "");
  setArgument(context, "");

  char* firstSentence = getFirstSentenceBySeparator(getInput(context), ' ');
  char* secondSentence = getSecondSentenceBySeparator(getInput(context), ' ');

  setCommand(context, getCommandByInput(firstSentence, &getContextCodeError(context)));
  if (secondSentence) {
    setArgument(context, secondSentence);
  }

  dispatchCommandWhenNoErrors(context);
}

void dispatchCommandWhenNoErrors(Context* context) {
  if (getContextCodeError(context) == NO_ERRORS) {
    commandDispatch(context);
  }
}
