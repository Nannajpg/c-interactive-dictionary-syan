#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../tad/include/trie-tree.h"
#include "../tad/include/context.h"
#include "./lib/include/create-tree-by-filename.h"

void migrateDefaultTrieDictionary(Context* context)
{
  int errorCode = createTreeByFilename(context->trieTree, "default.dic");
  if (errorCode == FILE_NOT_EXISTS_ERROR) {
    printf("Error al cargar diccionario por defecto\n");
    return;
  }
}
