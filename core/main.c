#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/create-program-context.h"
#include "./include/interactive-mode.h"
#include "./include/shell-mode.h"
#include "./include/context.h"
#include "./include/constans.h"

int main(int argQuantity, char* arg[])
{
    Context* context = CreateProgramContext();

    if (argQuantity < 2) {
      runInteractiveMode(context);
    }else{
      runShellMode(context, argQuantity, arg);
    }

    return 0;
}
