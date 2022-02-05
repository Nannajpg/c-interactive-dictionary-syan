#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"
#include "./include/context.h"
#include "../tad/include/trie-tree.h"

Context* CreateProgramContext()
{
    Context* context = (Context *) malloc(sizeof(Context));
    context->command = NO_COMMAND;
    context->commandArgument = "";
    context->response = "";
    context->programIsRunning = TRUE;
    context->environment = ENV_UNDEFINED;
    context->error = NO_ERRORS;
    context->trieTree = trieCreateTree();

    return context;
}
