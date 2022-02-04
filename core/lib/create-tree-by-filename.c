#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../utils/include/booleans.h"

#include "../include/commands.h"
#include "../include/errors.h"
#include "../include/context.h"

#include "../../tad/include/linea.h"
#include "../../tad/include/trie-tree.h"
#include "./include/files-helper.h"

int createTreeByFilename(TrieNode * trieTree, char * fileName) {
  if (!existeArchivo(fileName)) {
    return FILE_NOT_EXISTS_ERROR;
  }

  int cantidadLineas = contarLineasArchivo(fileName);
  struct Linea ** lineas = cargarArchivoPorNombre(fileName);

  //convertLineasIntoTrie(context->trieTree, lineas, cantidadLineas);
  return NO_ERRORS;
}
