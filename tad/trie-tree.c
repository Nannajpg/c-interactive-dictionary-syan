#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./include/trie-tree.h"

struct TrieNode * trieCreateNode(void);

/*METODOS BASICOS*/

  int trieGetSinonimosSize(struct TrieNode *trieNode)
  {
      int arrayLen = 0;
      if (trieNode->sinonimos)
        while (trieNode->sinonimos[arrayLen] != NULL){
          arrayLen++;
        };
      return arrayLen;
  }

  int trieGetAntonimosSize(struct TrieNode *trieNode)
  {
      int arrayLen = 0;
      if (trieNode->antonimos)
        while (trieNode->antonimos[arrayLen] != NULL){
          arrayLen++;
        };
      return arrayLen;
  }

  char** trieGetSinonimos(struct TrieNode *trieNode)
  {
      return trieNode->sinonimos;
  }

  char** trieGetAntonimos(struct TrieNode *trieNode)
  {
      return trieNode->antonimos;
  }

  int trieGetisWord(struct TrieNode *trieNode)
  {
      return trieNode->isWord;
  }

  void trieAddSinonimo(struct TrieNode *trieNode, char* newSinonimo)
  {
      int currentSize = trieGetSinonimosSize(trieNode);
      if (currentSize > 0) {
        trieNode->sinonimos = realloc(trieNode->sinonimos, sizeof(trieNode->sinonimos) * (currentSize+2));
      }else{
        trieNode->sinonimos = malloc(sizeof(trieNode->sinonimos) * 2);
      }
      trieNode->sinonimos[currentSize] = newSinonimo;
      trieNode->sinonimos[currentSize+1] = NULL;
  }

  void trieAddAntonimo(struct TrieNode *trieNode, char* newAntonimo)
  {
    int currentSize = trieGetAntonimosSize(trieNode);
    if (currentSize > 0) {
      trieNode->antonimos = realloc(trieNode->antonimos, sizeof(trieNode->antonimos) * (currentSize+2));
    }else{
      trieNode->antonimos = malloc(sizeof(trieNode->antonimos) * 2);
    }
    trieNode->antonimos[currentSize] = newAntonimo;
    trieNode->antonimos[currentSize+1] = NULL;
  }

/*METODOS AVANZADOS*/

// Creacion e inicializacion de un nuevo arbol
struct TrieNode *trieCreateTree(void) {
  return trieCreateNode();
}

// Creacion e inicializacion del nuevo nodo
struct TrieNode *trieCreateNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isWord = 0;
        pNode->sinonimos = NULL;
        pNode->antonimos = NULL;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

// si no hay nada en el espacio se inserta la letra
// si la letra es prefijo del nodo se inserta en la siguiente hoja
struct TrieNode *trieInsertWord(struct TrieNode *root, const char *word)
{
    int level;
    int length = strlen(word);
    int index;

    struct TrieNode *pivot = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(tolower(word[level]));
        if (!pivot->children[index])
            pivot->children[index] = trieCreateNode();

        pivot = pivot->children[index];
    }
    // Se marca el nodo como una palabra
    pivot->isWord = 1;
    return pivot;

    // Se agregan sus sinonimos y antonimos (ESTO ES DE PRUEBA)
    /*trieAddAntonimo(pivot, "hola");
    trieAddAntonimo(pivot, "uwu");

    trieAddSinonimo(pivot, "prueba");
    trieAddSinonimo(pivot, "macho");
    trieAddSinonimo(pivot, "pecho");
    trieAddSinonimo(pivot, "pelkudo");
    trieAddSinonimo(pivot, "asd");
    trieAddSinonimo(pivot, "refresco");*/
}

// Search regresa 1 si la palabra esta presente en el arbol trie
struct TrieNode* trieSearchWord(struct TrieNode *root, const char *word)
{
    int level;
    int length = strlen(word);
    int index;
    struct TrieNode *pivot = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(tolower(word[level]));

        if (!pivot->children[index])
            return 0;

        pivot = pivot->children[index];
    }

    if (pivot->isWord) return pivot;

    return NULL;
}
