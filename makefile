CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: photomagic.o test.o FibLFSR.o PhotoMagic test

test: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

PhotoMagic: photomagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o PhotoMagic test
