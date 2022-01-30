#ifndef context_h
#define context_h

  typedef struct context {
      char input[129];
      char* command;
      char* commandArgument;
      char* response;
      int programIsRunning;
      int error;
      int enverioment;
  } Context;

#endif
