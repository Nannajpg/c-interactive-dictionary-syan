#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../tad/include/context.h"

void executeQuitCommand(Context* context) {
    turnOffProgramExecution(context);
}
