CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

all: ./output/program

TARGET = exe3

./output/program: $(TARGET).o arvore.o fila.o
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).o: $(TARGET).c arvore.h
	$(CC) $(CFLAGS) -c $^

arvore.o: arvore.c arvore.h fila.h
	$(CC) $(CFLAGS) -c $^

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f ./*.o ./output/$(TARGET)
