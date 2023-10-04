CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

all: ./output/program

TARGET = exe1

./output/program: $(TARGET).o arvore.o
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).o: $(TARGET).c arvore.h
	$(CC) $(CFLAGS) -c $^

arvore.o: arvore.c arvore.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f ./*.o ./output/$(TARGET)
