CC = gcc
CFLAGS = -c -Wall -O3 -fsanitize=leak
LD = $(CC)
LDFLAGS = -fsanitize=leak

TARGET = deque
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

