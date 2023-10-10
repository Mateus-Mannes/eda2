CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

all: ./output/program

TARGET = main

./output/program: $(TARGET).o arvore_avl.o fila.o
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).o: $(TARGET).c arvore_avl.h
	$(CC) $(CFLAGS) -c $^

arvore.o: arvore_avl.c arvore_avl.h fila.h
	$(CC) $(CFLAGS) -c $^

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f ./*.o ./output/$(TARGET)
