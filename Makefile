CC=gcc
LDFLAGS=-Wall -g3
CFLAGS=-Wall -g3 -I$(CURDIR)/src

SOURCES=src/demo.c
OBJECTS=$(SOURCES:.c=.o)

tests: test/testsuite

demo.o: src/demo.c
	$(CC) $(CFLAGS) -c $< -o $@

test/testsuite.o: test/testsuite.c
	$(CC) $(CFLAGS) -I$(CURDIR) -c $< -o $@

.PHONY: test/testsuite clean

test/testsuite: $(OBJECTS) test/testsuite.o
	$(CC) $(LDFLAGS) $? -o $@
	./test/testsuite

clean:
	rm -rf $(OBJECTS) test/testsuite.o demo test/testsuite

