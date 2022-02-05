#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"

#include "../tad/include/trie-tree.h"
#include "../tad/include/context.h"

void executeAntonimosCommand(Context* context) {

  setContextCodeError(context, NO_ERRORS);

  char *palabra = setCommand(context, commandArgument);
  struct TrieNode *root = getTrieTree(context);
  struct TrieNode *result = trieSearchWord(root, palabra);
  char * texto = (char *) malloc(2000);
  // Limpiamos la basura de texto que puede venir de antemano
  if (strlen(texto) > 0) {
    texto[0] = '\0';
  }

  char * textoTmp = (char *) malloc(51);

  if (result == NULL){
    setContextCodeError(context, WORD_NOT_FOUND_ERROR);
    return;
  }

  int size = trieGetAntonimosSize(result);
  char ** arregloCadena = trieGetAntonimos(result);

  for (int i = 0; i < size; i++) {
      if (i == 0) {
        snprintf( textoTmp, 50, "%s", arregloCadena[i] );
      }else{
        snprintf( textoTmp, 50, ", %s", arregloCadena[i] );
      }
      strcat(texto, textoTmp);
  }

  setResponse(context, 2000, texto);
}
