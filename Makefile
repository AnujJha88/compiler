scanner: main.c scanner.c
	cc -o scanner -g main.c scanner.c

clean:
	rm -f scanner *.o
