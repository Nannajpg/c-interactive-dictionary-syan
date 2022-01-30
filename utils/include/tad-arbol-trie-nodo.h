#ifndef TADArbolTrie_Nodo_H
    #define TADArbolTrie_Nodo_H

    #include <stdio.h>

    typedef struct nodoTrie {
        struct nodoTrie* hijos[27];
        char value;
        int isEnd;
        char** sinonimos;
        char** antonimos;
    } ArbolTrieNodo;

#endif /* TADArbolTrie_Nodo_H */
