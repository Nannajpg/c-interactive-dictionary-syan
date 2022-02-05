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
  context->error = NO_ERRORS;
  struct TrieNode ** arregloNodos = NULL;
  char * str = (char *) malloc(51);
  char * texto = (char *) malloc(2000);
  arregloNodos = trieGetNodesMatchRegex(context->trieTree, arregloNodos, context->commandArgument, str, 0);
  int cantidadNodos = trieArrayGetLength(arregloNodos);
  char * textoTmp = (char *) malloc(51);
  int wordsWritten = 0;

  for (int i = 0; i < cantidadNodos; i++) {
    char ** antonimos = trieGetAntonimos(arregloNodos[i]);
    int antonimosSize = trieGetAntonimosSize(arregloNodos[i]);
    char ** sinonimos = trieGetSinonimos(arregloNodos[i]);
    int sinonimosSize = trieGetSinonimosSize(arregloNodos[i]);
    for (int k = 0; k < antonimosSize; k++) {
      if (wordsWritten <= 0) {
        snprintf( textoTmp, 50, "%s", antonimos[k] );
      }else{
        snprintf( textoTmp, 50, ", %s", antonimos[k] );
      }
      wordsWritten++;
      strcat(texto, textoTmp);
    }
    for (int j = 0; j < sinonimosSize; j++) {
      if (wordsWritten <= 0) {
        snprintf( textoTmp, 50, "%s", sinonimos[j] );
      }else{
        snprintf( textoTmp, 50, ", %s", sinonimos[j] );
      }
      wordsWritten++;
      strcat(texto, textoTmp);
    }
  }

  context->response = (char *) malloc(2001);
  snprintf( context->response, 2000, "%s", texto );
}
