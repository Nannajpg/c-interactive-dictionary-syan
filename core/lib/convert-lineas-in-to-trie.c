#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../tad/include/linea.h"
#include "../../tad/include/trie-tree.h"

void convertLineasInToTrie(struct TrieNode *root, struct Linea **lineas, int cantidadLineas)
{
  int = 0;
   for (i = 0; i < cantidadLineas; i++) {
        if (lineas[i]) trieInsertLinea(root, lineas[i]);
   }
}

void trieInsertLinea(struct TrieNode *root, struct Linea *linea)
{
  struct TrieNode *pivot = trieInsertWord(root,GetPalabra(linea));

  if (GetEsSinonimos(linea) == 1)
    trieAddSinonimo(pivot,getPalabraRel(linea));
  else
    trieAddAntonimo(pivot,getPalabraRel(linea));
}
