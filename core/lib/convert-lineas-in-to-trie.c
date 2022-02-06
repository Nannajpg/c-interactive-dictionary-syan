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
        if (lineas[i]) {
          trieInsertLinea(root, lineas[i]);
        }
   }
}

void trieAddSinonimoOrAntonimo(struct TrieNode * nodo, int esSinonimo, char * palabra) {
  if (esSinonimo)
    trieAddSinonimo(nodo,palabra);
  else
    trieAddAntonimo(nodo,palabra);
}

void trieInsertLinea(struct TrieNode *root, struct Linea *linea)
{
  char * palabra = getPalabra(linea);
  char * palabraRel = getPalabraRel(linea);
  int esSinonimo = getEsSinonimos(linea);

  struct TrieNode *pivot = trieInsertWord(root,palabra);

  trieAddSinonimoOrAntonimo(pivot, esSinonimo, palabraRel);

  struct TrieNode *pivotRel = trieInsertWord(root,palabraRel);

  trieAddSinonimoOrAntonimo(pivotRel, esSinonimo, palabra);
}
