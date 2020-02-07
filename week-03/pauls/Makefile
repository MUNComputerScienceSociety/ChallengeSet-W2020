CC=clang
# CFLAGS=-Wall -Wextra -Werror -Wpedantic
CFLAGS=-Wall -Wextra -O3
SRC=jumbled.c
OBJS=jumbled.o
PROGS=jumbled 

all: $(PROGS)

jumbled: jumbled.o

$(OBJS): $(SRC)

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGS)