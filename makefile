CC = gcc
CFLAGS = -Wall -Iinclude -Isrc
LDFLAGS =

SRCS = src/alloc_funcs.c src/array.c test.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
TARGET = test

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.d: %.c
	$(CC) $(CFLAGS) -MM $< -o $@

-include $(DEPS)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET)
