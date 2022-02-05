#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/constans.h"
#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeHelpCommand(Context* context) {
    context->error = NO_ERRORS;
    char * texto;

    if (context->environment == ENV_SHELL) {
      texto = "\n"
      "cargar nombre - carga el diccionario desde el archivo nombre.dic\n"
      "s palabra – busca los sinónimos de la palabra\n"
      "a palabra – busca los antónimos de la palabra\n"
      "e expresión – muestras los sinónimos y antónimos de todas las palabras que comienza con expresión\n"
      "ayuda – muestra esta entrada\n"
      "salir – sale de la aplicación\n"
      "";
    }else if (context->environment == ENV_INTERACTIVE) {
      texto = "\n"
      ">cargar nombre - carga el diccionario desde el archivo nombre.dic\n"
      ">s palabra – busca los sinónimos de la palabra\n"
      ">a palabra – busca los antónimos de la palabra\n"
      ">e expresión – muestras los sinónimos y antónimos de todas las palabras que comienza con expresión\n"
      ">ayuda – muestra esta entrada\n"
      ">salir – sale de la aplicación\n"
      ">";
    }

    context->response = (char *) malloc(400);
    snprintf( context->response, 401, "%s", texto );
}
