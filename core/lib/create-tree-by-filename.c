#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../utils/include/booleans.h"

#include "../include/commands.h"
#include "../include/errors.h"

#include "../../tad/include/linea.h"
#include "../../tad/include/trie-tree.h"
#include "../../tad/include/context.h"

#include "./include/files-helper.h"
#include "./include/convert-lineas-in-to-trie.h"

int createTreeByFilename(struct TrieNode * trieTree, char * fileName) {
  if (!existeArchivo(fileName)) {
    return FILE_NOT_EXISTS_ERROR;
  }

  int cantidadLineas = contarLineasArchivo(fileName);
  struct Linea ** lineas = cargarArchivoPorNombre(fileName);

  convertLineasInToTrie(trieTree, lineas, cantidadLineas);

  free(lineas);
  lineas = NULL;

  return NO_ERRORS;
}
