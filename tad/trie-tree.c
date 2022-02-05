#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./include/trie-tree.h"
#include "../utils/include/string-formating-utils.h"

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

  int trieIsWord(struct TrieNode *trieNode)
  {
      return trieNode->isWord;
  }

  int areStringInArray(char ** stringArray, int arraySize, char * cadena) {
    for (int i = 0; i < arraySize; i ++) {
      if (strcmp(stringArray[i], cadena) == 0) {
        return 1;
      }
    }
    return 0;
  }

  void trieAddSinonimo(struct TrieNode *trieNode, char* newSinonimo)
  {
      int currentSize = trieGetSinonimosSize(trieNode);
      if (currentSize > 0) {
        if (areStringInArray(trieNode->sinonimos, currentSize, newSinonimo)) return;
      }

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
      if (areStringInArray(trieNode->antonimos, currentSize, newAntonimo)) return;
    }

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

// Char a entero
int charToInt(char letra) {
  return (int) letra - 48;
}

// Eliminar tilde de caracter
char removeTilde(char vocal) {
  int vocalesConNumber[34]={
    -175,
    -176,
    -173,
    -174,
    -169,
    -143,
    -144,
    -141,
    -142,
    -137,
    -167,
    -166,
    -135,
    -134,
    -135,
    -136,
    -163,
    -131,
    -132,
    -159,
    -157,
    -156,
    -155,
    -127,
    -125,
    -126,
    -124,
    -123,
    -150,
    -148,
    -118,
    -119,
    -116,
    -119,
  };

  //AAAACaaaacEEeeeeIiiNOOOnooooUUuuuu
  char vocalesSin[34]="AAAACaaaacEEeeeeIiiNOOOnooooUUuuuu";
  for (int i=0;i<34;i++){
    int vocalInt = charToInt(vocal);
    if (vocalesConNumber[i] == vocalInt) {
      return vocalesSin[i];
    }
  }

  return vocal;
}

// si no hay nada en el espacio se inserta la letra
// si la letra es prefijo del nodo se inserta en la siguiente hoja
struct TrieNode *trieInsertWord(struct TrieNode *root, const char *word)
{
    int level;
    int length = strlen(word);
    int index;

    struct TrieNode *pivot = root;
    //printf("%s\n", word);
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(removeTilde(tolower(word[level])));

        //printf("%c --> %c ll %d\n", word[level], removeTilde(tolower(word[level])), index);
        //printf("%d\n", index);

        if (index >= 0 && index <= ALPHABET_SIZE) {
          if (!pivot->children[index])
              pivot->children[index] = trieCreateNode();

          pivot = pivot->children[index];
        }
    }
    // Se marca el nodo como una palabra
    pivot->isWord = 1;
    return pivot;
}

// Search regresa 1 si la palabra esta presente en el arbol trie
struct TrieNode* trieSearchWord(struct TrieNode *root, const char *word)
{
    int level;
    int length = strlen(word);
    int index;
    struct TrieNode *pivot = root;
    //printf("TO SEARCH %s\n", word);

    for (level = 0; level < length; level++)
    {
        //printf("%c\n", word[level]);
        index = CHAR_TO_INDEX(removeTilde(tolower(word[level])));
        //printf("%d\n", index);

        if (index >= 0 && index <= ALPHABET_SIZE) {
          if (!pivot->children[index])
              return 0;

          pivot = pivot->children[index];
        }
    }

    if (pivot->isWord) return pivot;

    return NULL;
}
