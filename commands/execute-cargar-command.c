#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeCargarCommand(Context* context) {
  /*
    context->commandArgument  <-- La palabra (nombre del archivo)
    context->response         <-- Donde enviar la respuesta
    context->trieTree         <-- El arbol :)
    context->error            <-- Donde enviar errores

    1. Validar que el archivo exista
    2. Funcion para cargar el diccionario por el nombre del archivo (Anna)
    3. Enviar el diccionario a la funcion convertidora en arbol (Jesus)
    4. Sustituir el context->trieTree actual por el nuevo context->trieTree
  */
}
