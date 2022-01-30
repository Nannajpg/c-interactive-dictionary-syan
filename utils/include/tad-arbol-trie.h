#ifndef TADArbolTrie_H
    #define TADArbolTrie_H

    #include <stdio.h>
    #include "./tad-arbol-trie-nodo.h"

    typedef struct ArbolTrie {
        struct ArbolTrieNodo* hijos[27];
    } ArbolTrie;

    ArbolTrie* CrearArbol();

#endif /* TADArbolTrie_H */
