#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/context.h"
#include "../tad/include/trie-tree.h"

void migrateDefaultTrieDictionary(Context* context)
{

  trieInsertWord(context->trieTree, "Manzana");
  trieInsertWord(context->trieTree, "Pera");
  trieInsertWord(context->trieTree, "Arepa");
  trieInsertWord(context->trieTree, "Arepas");
  trieInsertWord(context->trieTree, "Marron");
  trieInsertWord(context->trieTree, "Mandarina");
  trieInsertWord(context->trieTree, "Espagetti");

  /*struct TrieNode* manzana = trieSearchWord(context->trieTree, "Manzana");
  int sinonimosSize = trieGetSinonimosSize(manzana);
  int antonimosSize = trieGetAntonimosSize(manzana);
  char** sinonimos = trieGetSinonimos(manzana);

  printf("\n--- sinonimosSize %d\n", sinonimosSize);
  printf("\n--- antonimosSize %d\n", antonimosSize);

  int i;
  for (i = 0; i < sinonimosSize; i++) {
    printf("%s\n", sinonimos[i]);
  }*/
}
