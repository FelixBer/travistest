CFLAGS=-Wall

all:	hello2 helloshared

helloshared:
	gcc -c -fpic printhello.c
	gcc -shared -o libprinthello.so printhello.o
	gcc -L./ -o helloshared  helloshared.c -lprinthello

hello:	hello.o
	gcc hello.o -o hello

hello2:	hello2.o
	gcc hello2.o -o hello2

.c.o:
	gcc -c -o $@ $< $(CFLAGS)

clean:
	rm -f hello.o hello2.o hello hello2 libprinthello.so printhello.o helloshared

