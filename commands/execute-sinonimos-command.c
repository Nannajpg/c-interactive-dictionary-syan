#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../tad/include/context.h"

void executeSinonimosCommand(Context* context) {

  setContextCodeError(context, NO_ERRORS);

  char *palabra = getArgument(context);
  struct TrieNode *root = getTrieTree(context);
  struct TrieNode *result = trieSearchWord(root, palabra);
  if (result == NULL){
    setContextCodeError(context, WORD_NOT_FOUND_ERROR);
    return;
  }

  int sizeSinonimos = trieGetSinonimosSize(result);
  int sizeTextoResult = sizeSinonimos*50 + 20;

  char * texto = (char *) malloc(sizeTextoResult);
  // Limpiamos la basura de texto que puede venir de antemano
  if (strlen(texto) > 0) {
    texto[0] = '\0';
  }

  char * textoTmp = (char *) malloc(51);
  char ** arregloCadena = trieGetSinonimos(result);

  for (int i = 0; i < sizeSinonimos; i++) {
      if (i == 0) {
        snprintf( textoTmp, 50, "%s", arregloCadena[i] );
      }else{
        snprintf( textoTmp, 50, ", %s", arregloCadena[i] );
      }
      strcat(texto, textoTmp);
  }

  setResponse(context, 2000, texto);
}
