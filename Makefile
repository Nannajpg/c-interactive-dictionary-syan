vpath %.h ./core/include:./utils/include:./utils/include
vpath %.c ./core:./commands:./utils

TARGET = dictionary
programa =  get-inputed.o string-formating-utils.o\
			command-dispatch.o get-error.o get-command-by-input.o execute-quit-command.o execute-help-command.o\
			add-numeric-value.o execute-program.o interactive-mode.o create-program-context.o main.o

CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) $(programa) -o $(TARGET) -lm

.PHONY: clean
clean:
	@rm -f *.o $(TARGET)
