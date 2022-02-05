#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/commands.h"
#include "../../include/errors.h"

#include "../../../tad/include/context.h"
#include "../../../tad/include/trie-tree.h"

int createTreeByFilename(struct TrieNode * trieTree, char * fileName);
