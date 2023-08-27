CC = gcc
CFLAGS = -Wall -Wextra

TARGET = resolucao1

.PHONY: all clean

all: ./output/$(TARGET)

./output/$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ./*.o ./output/$(TARGET)
