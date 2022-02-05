#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../tad/include/context.h"

void executeSinonimosCommand(Context* context) {

  context->error = NO_ERRORS;

  char *palabra = context->commandArgument;
  struct TrieNode *root = context->trieTree;
  struct TrieNode *result = trieSearchWord(root, palabra);
  char * texto = (char *) malloc(2000);
  // Limpiamos la basura de texto que puede venir de antemano
  if (strlen(texto) > 0) {
    texto[0] = '\0';
  }

  char * textoTmp = (char *) malloc(51);

  if (result == NULL){
    context->error = WORD_NOT_FOUND_ERROR;
    return;
  }

  int size = trieGetSinonimosSize(result);
  char ** arregloCadena = trieGetSinonimos(result);

  for (int i = 0; i < size; i++) {
      if (i == 0) {
        snprintf( textoTmp, 50, "%s", arregloCadena[i] );
      }else{
        snprintf( textoTmp, 50, ", %s", arregloCadena[i] );
      }
      strcat(texto, textoTmp);
  }

  context->response = (char *) malloc(2000);
  snprintf( context->response, 2000, "%s", texto );
}
