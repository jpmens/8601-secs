all: 8601-secs

8601-secs: 8601-secs.c duration.o duration.h
	$(CC) $(CFLAGS) -o 8601-secs 8601-secs.c duration.o

clean:
	rm -f *.o
clobber: clean
	rm -f 8601-secs
