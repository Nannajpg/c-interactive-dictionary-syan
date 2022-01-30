#ifndef trie_tree_h
    #define trie_tree_h

    // Tamaño del alfabeto
    #define ALPHABET_SIZE (26)

    // Convierte el caracter actual en codigo ASCII
    // Solo pensado para letras de la a-z y en minusculas
    #define CHAR_TO_INDEX(c) ((int)c - (int)'a')

    // TrieNode
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        char** sinonimos;
        char** antonimos;
        int isWord;
    };

    struct TrieNode *trieCreateTree(void);
    void trieInsertWord(struct TrieNode *root, const char *word);
    struct TrieNode* trieSearchWord(struct TrieNode *root, const char *word);

#endif /* trie_tree_h */
