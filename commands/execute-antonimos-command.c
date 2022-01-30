#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"
#include "../tad/include/trie-tree.h"

void executeAntonimosCommand(Context* context) {
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
