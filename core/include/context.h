#ifndef context_h
#define context_h

  #include "../../tad/include/trie-tree.h"

  typedef struct context {
      char input[129];
      char* command;
      char* commandArgument;
      char* response;
      int programIsRunning;
      int error;
      int environment;
      struct TrieNode* trieTree;
  } Context;

#endif
