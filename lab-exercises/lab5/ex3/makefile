CC=gcc
CCFLAGS=-Wall
LIBS=-lm

mycode: main.o complexmath.o validate.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LIBS)

%.o : %.c
	$(CC) $(CCFLAGS) -c $^

.PHONY: clean

clean:
	rm -f *.o mycode
