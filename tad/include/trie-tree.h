#ifndef trie_tree_h
    #define trie_tree_h

    // Tamaño del alfabeto
    #define ALPHABET_SIZE (26)

    // Convierte el caracter actual en codigo ASCII
    // Solo pensado para letras de la a-z y en minusculas
    #define CHAR_TO_INDEX(c) ((int)c - (int)'a')

    // TrieNode (Estructura)
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        char** sinonimos;
        char** antonimos;
        int isWord;
    };

    // Metodos basicos del TrieTree
    int trieGetSinonimosSize(struct TrieNode *trieNode);
    int trieGetAntonimosSize(struct TrieNode *trieNode);
    char** trieGetSinonimos(struct TrieNode *trieNode);
    char** trieGetAntonimos(struct TrieNode *trieNode);
    void trieAddSinonimo(struct TrieNode *trieNode, char* newSinonimo);
    void trieAddAntonimo(struct TrieNode *trieNode, char* newAntonimo);

    // Metodos especiales del TrieTree
    struct TrieNode *trieCreateTree(void);
    void trieInsertWord(struct TrieNode *root, const char *word);
    struct TrieNode* trieSearchWord(struct TrieNode *root, const char *word);

#endif /* trie_tree_h */
