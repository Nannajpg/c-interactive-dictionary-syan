#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"

#include "../tad/include/trie-tree.h"
#include "../tad/include/context.h"
#include "../core/lib/include/create-tree-by-filename.h"

void executeCargarCommand(Context* context) {
  context->error = NO_ERRORS;
  char * fileName = context->commandArgument;

  int errorCode = createTreeByFilename(context->trieTree, fileName);
  if (errorCode == FILE_NOT_EXISTS_ERROR) {
    context->error = errorCode;
    return;
  }

  context->response = "Arbol Trie cargado con exito!";
}
