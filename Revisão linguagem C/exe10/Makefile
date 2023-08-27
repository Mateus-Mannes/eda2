CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

TARGET = resolucao1

.PHONY: all clean

all: ./output/$(TARGET)

./output/$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ./*.o ./output/$(TARGET)
