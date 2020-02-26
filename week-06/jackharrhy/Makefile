all: clean sudokuchecker sudokuchecker-threads

sudokuchecker:
	gcc -g -Wall -Wextra -Werror -Wpedantic ./sudokuchecker.c -o ./sudokuchecker.o

sudokuchecker-threads:
	gcc -g -lpthread -Wall -Wextra -Werror -Wpedantic ./sudokuchecker-threads.c -o ./sudokuchecker-threads.o

sample1:
	cat ../test-samples/sudokuchecker/sample1.in | ./sudokuchecker.o
sample2:
	cat ../test-samples/sudokuchecker/sample2.in | ./sudokuchecker.o
sample3:
	cat ../test-samples/sudokuchecker/sample3.in | ./sudokuchecker.o

sample1-threads:
	cat ../test-samples/sudokuchecker/sample1.in | ./sudokuchecker-threads.o
sample2-threads:
	cat ../test-samples/sudokuchecker/sample2.in | ./sudokuchecker-threads.o
sample3-threads:
	cat ../test-samples/sudokuchecker/sample3.in | ./sudokuchecker-threads.o

clean:
	-rm ./sudokuchecker.o
	-rm ./sudokuchecker-threads.o
