CC=gcc
LD=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11
LDFLAGS=-L. -lfibo
OBJS=main.o fibo.o
TARGET=fibo
LIB=libfibo.a


main.o: main.c fibo.h
	$(CC) $(CFLAGS) -c main.c

fibo.o: fibo.c fibo.h
	$(CC) $(CFLAGS) -c fibo.c

$(LIB): fibo.o
	ar -rcs $(LIB) fibo.o
#libfibo: fibo.o
#	ar -rc libfibo.a fibo.o
#	ranlib libfibo.a fibo.o

# use target 'all' to compile without using the library
all: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# use target 'alllib' to compile using the library
alllib: main.o $(LIB)
	$(CC) main.o -o $(TARGET) $(LDFLAGS)


clean:
	rm -r $(LIB) $(OBJS) $(TARGET)
