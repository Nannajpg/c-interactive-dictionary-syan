#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../tad/include/linea.h"
#include "../../tad/include/trie-tree.h"

void trieInsertLinea(struct TrieNode *root, struct Linea *linea);

void convertLineasInToTrie(struct TrieNode *root, struct Linea **lineas, int cantidadLineas)
{
   int i = 0;
   for (i = 0; i < cantidadLineas; i++) {
        if (lineas[i]) trieInsertLinea(root, lineas[i]);
   }
}

void trieInsertLinea(struct TrieNode *root, struct Linea *linea)
{
  struct TrieNode *pivot = trieInsertWord(root,getPalabra(linea));

  if (getEsSinonimos(linea) == 1)
    trieAddSinonimo(pivot,getPalabraRel(linea));
  else
    trieAddAntonimo(pivot,getPalabraRel(linea));
}
