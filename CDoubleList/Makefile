SRC= $(wildcard ./src/**/*.c) $(wildcard ./src/*.c)
CFLAGS = -Wall -Wextra
CFLAGS += -Wundef -Wshadow -Wpointer-arith -Wcast-align 
CFLAGS += -Wwrite-strings -Waggregate-return 
CFLAGS += -Wstrict-prototypes 
CFLAGS += -ggdb

OBJ=$(SRC:.c=.o)
BIN=bin

all: dirs test
	echo $(SRC)
	echo $(OBJ)
run: clean all
	./$(BIN)/test

dirs:
	mkdir -p ./$(BIN)

%.o:%.c
	$(CC) -o $@ -c $^ $(CFLAGS)

test:$(OBJ)
	$(CC) -o $(BIN)/test $^ $(LDFLAGS)


clean:
	rm -rf $(BIN) $(OBJ)
