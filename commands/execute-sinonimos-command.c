#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeSinonimosCommand(Context* context) {
  /*
    context->commandArgument  <-- La palabra
    context->response         <-- Donde enviar la respuesta
    context->trieTree         <-- El arbol :)
    context->error            <-- Donde enviar errores
    trieSearchWord()          <-- Funcion para buscar palabra dentro del arbol (Retorna un TrieNode)

    La idea seria mostrar los sinonimos dentro de ese TrieNode enviandolos por context->response
  */
}
