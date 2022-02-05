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
  setContextCodeError(context, NO_ERRORS);
  char * fileName = getArgument(context);

  int errorCode = createTreeByFilename(getTrieTree(context), fileName);
  if (errorCode == FILE_NOT_EXISTS_ERROR) {
    setContextCodeError(context, errorCode);
    return;
  }

  setSimpleResponse(context, "Arbol Trie cargado con exito!");
}
