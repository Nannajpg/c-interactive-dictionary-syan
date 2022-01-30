#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/create-program-context.h"
#include "./include/interactive-mode.h"
#include "./include/shell-mode.h"
#include "./include/context.h"

int main(int argQuantity, char* arg[])
{
    Context* context = CreateProgramContext();

    //if (argQuantity < 2) {
      interactiveMode(context);
    /*}else{
      shellMode(context, argQuantity, arg);
    }*/

    return 0;
}
