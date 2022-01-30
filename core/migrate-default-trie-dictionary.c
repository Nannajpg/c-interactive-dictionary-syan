#include "./include/context.h"
#include "../tad/include/trie-tree.h"

void migrateDefaultTrieDictionary(Context* context)
{
  trieInsertWord(context->trieTree, "Manzana");
  /*trieInsertWord(context->trieTree, "Pera");
  trieInsertWord(context->trieTree, "Arepa");
  trieInsertWord(context->trieTree, "Arepas");
  trieInsertWord(context->trieTree, "Marron");
  trieInsertWord(context->trieTree, "Mandarina");
  trieInsertWord(context->trieTree, "Espagetti");*/
}
