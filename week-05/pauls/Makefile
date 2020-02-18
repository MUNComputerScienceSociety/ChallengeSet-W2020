CC=clang
# CFLAGS=-Wall -Wextra -Werror -Wpedantic --debug
CFLAGS=-Wall -Wextra -Wpedantic
LDLIBS=-lpthread
SRC=$(wildcard *.c)
OBJS=$(SRC:%.c=%.o)
PROGS=unlockpattern

all: $(PROGS)

$(OBJS): $(SRC)

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGS)