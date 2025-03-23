all: iso8601-duration

iso8601-duration: iso8601-duration.c duration.o duration.h
	$(CC) $(CFLAGS) -o iso8601-duration iso8601-duration.c duration.o

clean:
	rm -f *.o
clobber: clean
	rm -f iso8601-duration
