#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/migrate-default-trie-dictionary.h"
#include "./include/interactive-mode.h"
#include "./include/shell-mode.h"
#include "./include/constans.h"
#include "./lib/include/files-helper.h"
#include "../tad/include/linea.h"
#include "../tad/include/context.h"

int main(int argQuantity, char* arg[])
{
    Context* context = CreateProgramContext();

    migrateDefaultTrieDictionary(context);

    if (argQuantity < 2) {
      runInteractiveMode(context);
    }else{
      runShellMode(context, argQuantity, arg);
    }

    return 0;
}
