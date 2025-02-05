CC = gcc
CFLAGS = -Wall
TARGET = VotingApp

SRC = main.c voting.c
OBJ = obj/main.o obj/voting.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean