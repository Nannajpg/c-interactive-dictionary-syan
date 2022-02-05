#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../tad/include/trie-tree.h"

int trieArrayGetLength(struct TrieNode ** trieArray)
{
    int arrayLen = 0;
    if (trieArray)
      while (trieArray[arrayLen] != NULL){
        arrayLen++;
      };
    return arrayLen;
}

void trieArrayAddNodo(struct TrieNode ** trieArray, struct TrieNode * trieNode)
{
    int currentSize = trieArrayGetLength(trieArray);
    if (currentSize > 0) {
      trieArray = realloc(trieArray, sizeof(trieArray) * (currentSize+2));
    }else{
      trieArray = malloc(sizeof(trieArray) * 2);
    }
    trieArray[currentSize] = trieNode;
    trieArray[currentSize+1] = NULL;
}
