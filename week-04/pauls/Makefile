CC=clang
# CFLAGS=-Wall -Wextra -Werror -Wpedantic --debug
CFLAGS=-Wall -Wextra --debug
SRC=$(wildcard *.c)
OBJS=$(SRC:%.c=%.o)
PROGS=iboard brokenswords busrecursion bussimple cetvrta

all: $(PROGS)

$(OBJS): $(SRC)

iboard: log.o iboard.o

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGS)