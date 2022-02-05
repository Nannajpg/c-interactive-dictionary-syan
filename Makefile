vpath %.h ./core/include:./core/lib/include:./utils/include:./utils/include:./tad/include
vpath %.c ./core:./core/lib:./commands:./utils:./tad

TARGET = dictionary
programa = 	match-regular-expression.o linea.o trie-tree.o files-helper.o\
						convert-lineas-in-to-trie.o get-inputed.o string-formating-utils.o\
						create-tree-by-filename.o migrate-default-trie-dictionary.o\
						command-dispatch.o get-error.o errors-helper.o get-command-by-input.o\
						execute-quit-command.o\
						execute-sinonimos-command.o execute-antonimos-command.o\
						execute-expression-command.o\
						execute-help-command.o execute-cargar-command.o is-arguable-command.o\
						execute-program.o\
						interactive-mode.o shell-mode.o create-program-context.o main.o

CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) $(programa) -o $(TARGET) -lm

.PHONY: clean
clean:
	@rm -f *.o $(TARGET)
