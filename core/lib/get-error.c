#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/errors.h"

char* GetError(int errorCode)
{
     if (errorCode == INVALID_COMMAND_ERROR) return "Accion invalida";
     if (errorCode == UNDEFINED) return "Error indefinido";
     return "";
}
