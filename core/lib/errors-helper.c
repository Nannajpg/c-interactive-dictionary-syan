#include "../include/errors.h"

int isInvalidCommandError(int errorCode) {
    return (errorCode == INVALID_COMMAND_ERROR);
}
