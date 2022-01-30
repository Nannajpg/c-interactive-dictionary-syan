#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./include/trie-tree.h"

struct TrieNode *trieCreateNode(void);

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
void trieInsertWord(struct TrieNode *root, const char *word)
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

    // Se agregan sus sinonimos y antonimos (ESTO ES DE PRUEBA)
    pivot->antonimos = malloc(sizeof(*pivot->antonimos) * 10);
    pivot->sinonimos = malloc(sizeof(*pivot->sinonimos) * 10);
    pivot->antonimos[0] = "hola";
    pivot->antonimos[1] = "uwu";
    pivot->sinonimos[0] = "prueba";
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
