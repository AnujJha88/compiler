parser: expr.c interp.c main.c scanner.c tree.c
	cc -o parser -g expr.c interp.c main.c scanner.c tree.c

clean:
	rm -f scanner *.o
