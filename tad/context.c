#ifndef context_c
#define context_c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#include "../utils/include/booleans.h"
//
#include "../core/include/commands.h"
#include "../core/include/constans.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"
//
#include "./include/trie-tree.h"
#include "./include/context.h"

  Context* CreateProgramContext()
  {
      Context* context = (Context *) malloc(sizeof(Context));
      context->command = NO_COMMAND;
      context->commandArgument = "";
      context->response = "";
      context->programIsRunning = TRUE;
      context->environment = ENV_UNDEFINED;
      context->error = NO_ERRORS;
      context->trieTree = trieCreateTree();

      return context;
  }

  // Metodos basicos
    // Getters
      char * getCommand(Context * context){
        return context->command;
      }

      char * getArgument(Context * context){
        return context->commandArgument;
      }

      char * getResponse(Context * context){
        return context->response;
      }

      char [129] getInput(Context * context){
        return context->input;
      }

      int isProgramRunning(Context * context){
        return context->programIsRunning;
      }

      int getContextCodeError(Context * context){
        return context->error;
      }

      int getEnvironment(Context * context){
        return context->environment;
      }
      
      struct TrieNode * getTrieTree(Context * context){
        return context->trieTree;
      }

    // Setters
      void setCommand(Context * context, char * value){
        context->command = value;
      }

      void setArgument(Context * context, char * value){
        context->commandArgument = value;
      }

      void setSimpleResponse(Context * context, char * value){
        context->response = value;
      }

      void setInput(Context * context, char value[129]){
        context->input = value;
      }

      void setIsProgramRunning(Context * context, int value){
        context->programIsRunning = value;
      }

      void setContextCodeError(Context * context, int value){
        context->error = value;
      }

      void setEnvironment(Context * context, int value){
        context->environment = value;
      }

      void setTrieTree(Context * context, struct TrieNode * root){
        context->trieTree = root;
      }

  // Metodos especiales
    void setResponse(Context * context, int size, char * value){
        setResponseSize(context, size);
        snprintf( context->response, size, "%s", value );
    }

    void freeResponseMemory(Context* context) {
      if (strlen(context->response) > 0) {
        context->response[0] = '\0';
        free(context->response);
        context->response = NULL;
      }
    }

    void turnOffProgramExecution(Context * context) {
      context->programIsRunning = FALSE;
    }

    void setResponseSize(Context * context, int size){
        context->response = (char *) malloc(size);
    }



#endif
