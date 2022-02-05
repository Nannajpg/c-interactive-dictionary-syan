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
    /* code */
    /*trieGetSinonimosSize
      trieGetAntonimosSize
      trieGetSinonimos
      trieGetAntonimos*/
    char ** antonimos = trieGetAntonimos(arregloNodos[i]);
    int antonimosSize = trieGetAntonimosSize(arregloNodos[i]);
    char ** sinonimos = trieGetSinonimos(arregloNodos[i]);
    int sinonimosSize = trieGetSinonimosSize(arregloNodos[i]);
    printf("\n");
    for (int k = 0; k < antonimosSize; k++) {
      printf("%s, ", antonimos[k]);
    }
    for (int j = 0; j < sinonimosSize; j++) {
      printf("%s, ", sinonimos[j]);
    }
  }
  /*
    context->commandArgument  <-- La palabra
    context->response         <-- Donde enviar la respuesta
    context->trieTree         <-- El arbol :)
    context->error            <-- Donde enviar errores
    trieSearchWord()          <-- Funcion para buscar palabra dentro del arbol (Retorna un TrieNode)

    La idea seria mostrar los antonimos dentro de ese TrieNode enviandolos por context->response
  */
  /*
    El string que debe ingresarse en context->response debera ser parecido a:
    "manzana, perro, gato"
    No deberia hacerse un printf() desde aqui, si no agregar un string al context->response()

    Recomiendo usar snprintf o strcat

    Para acceder a los antonimos u sinonimos debera usarse los metodos:
    - int trieGetSinonimosSize(struct TrieNode *trieNode); //Obtiene la cantidad de sinonimos
    - int trieGetAntonimosSize(struct TrieNode *trieNode); //Obtiene la cantidad de antonimos
    - char** trieGetSinonimos(struct TrieNode *trieNode); //Obtiene el arreglo de sinonimos
    - char** trieGetAntonimos(struct TrieNode *trieNode); //Obtiene el arreglo de antonimos
  */
}
