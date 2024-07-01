CC = gcc
TARGET = ifunc_example
SRCS = ifunc_example.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
	./$(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
