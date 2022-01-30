#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./include/context.h"

Context* CreateProgramContext()
{
    Context* context = (Context *) malloc(sizeof(Context));
    context->command = NO_COMMAND;
    context->commandArgument = "";
    context->response = "";
    context->programIsRunning = TRUE;
    context->error = NO_ERRORS;

    return context;
}
