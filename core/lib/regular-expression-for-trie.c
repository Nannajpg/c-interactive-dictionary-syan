#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// function to display the content of Trie
void display(struct TrieNode* root, TrieNode ** arregloNodos, char* expression, char str[], int level)
{
    if (trieGetisWord(root))
    {
        str[level] = '\0';
        if (funcionRaraMatchExpression(expression, str) {
                agregarNodoAArregloDeNodos(arregloNodos, root);
       }
       // printf(str);
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}
