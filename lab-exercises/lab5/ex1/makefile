STD=-std=c99

gray3 : gray3.o printpgm.o
	gcc -o $@ $^ $(STD)

%.o : %.c
	gcc -c $< $(STD)


#To clean up everything made by this file
.PHONY: clean

clean:
	rm -f *.o gray3
