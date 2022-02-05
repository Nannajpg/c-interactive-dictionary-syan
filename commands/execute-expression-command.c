#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"
#include "../core/lib/include/trie-array-helper.h"
#include "../core/lib/include/regular-expression-for-trie.h"

void executeExpressionCommand(Context* context) {
  struct TrieNode ** arregloNodos = NULL;
  char  str[200];
  arregloNodos = display(context->trieTree, arregloNodos, context->commandArgument, str, 0);
  int cantidadNodos = trieArrayGetLength(arregloNodos);

  for (int i = 0; i < cantidadNodos; i++) {
    char ** antonimos = trieGetAntonimos(arregloNodos[i]);
    int antonimosSize = trieGetAntonimosSize(arregloNodos[i]);
    char ** sinonimos = trieGetSinonimos(arregloNodos[i]);
    int sinonimosSize = trieGetSinonimosSize(arregloNodos[i]);
    for (int k = 0; k < antonimosSize; k++) {
      printf("%s, ", antonimos[k]);
    }
    for (int j = 0; j < sinonimosSize; j++) {
      printf("%s, ", sinonimos[j]);
    }
  }

}
