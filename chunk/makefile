CC = g++
CFLAGS = -c -Wall -O3
LD = $(CC)

TARGET = deque-ch
OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

