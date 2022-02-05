#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../tad/include/trie-tree.h"
#include "./include/trie-array-helper.h"
#include "../../utils/include/match-regular-expression.h"

// function to display the content of Trie
void display(struct TrieNode* root, struct TrieNode ** arregloNodos, char* expression, char* str, int level);
void display(struct TrieNode* root, struct TrieNode ** arregloNodos, char* expression, char* str, int level)
{
    if (trieIsWord(root))
    {
        str[level] = '\0';
        if (matchRegularExpression(expression, str)){
                printf(str);
                trieArrayAddNodo(arregloNodos, root);
       }
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], arregloNodos, expression, str, level + 1);
        }
    }
}
