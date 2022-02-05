#ifndef context_h
#define context_h

  #include "./trie-tree.h"

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

  // Constructor
  Context* CreateProgramContext();

  // Metodos basicos
    // Getters
    char *getCommand(Context * context);
    char *getArgument(Context * context);
    char *getResponse(Context * context);
    int isProgramRunning(Context * context);
    int getContextCodeError(Context * context);
    int getEnvironment(Context * context);
    struct TrieNode * getTrieTree(Context * context);
    
    // Setters
    void setCommand(Context * context, char * value);
    void setArgument(Context * context, char * value);
    void setResponse(Context * context, char * value);
    void setIsProgramRunning(Context * context, int value);
    void setContextCodeError(Context * context, int value);
    void setEnvironment(Context * context, int value);
    void setTrieTree(Context * context, struct TrieNode * root);

  // Metodos especiales
  void freeResponseMemory(Context* context);
  void turnOffProgramExecution(Context * context);

#endif /* context_h */
