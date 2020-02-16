all: clean sudokuchecker

sudokuchecker:
	gcc -g -lpthread -Wall -Wextra -Werror -Wpedantic ./sudokuchecker.c -o ./sudokuchecker.o

sample1:
	cat ../test-samples/sudokuchecker/sample1.in | ./sudokuchecker.o
sample2:
	cat ../test-samples/sudokuchecker/sample2.in | ./sudokuchecker.o
sample3:
	cat ../test-samples/sudokuchecker/sample3.in | ./sudokuchecker.o

clean:
	-rm ./sudokuchecker
