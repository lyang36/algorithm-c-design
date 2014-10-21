CC=gcc
IFLAGS= -std=c99
LFLAGS= -O3 -Wall

all: 
	$(CC) -c link_list.c binary_tree.c test_btree.c test_link.c $(IFLAGS)
	$(CC) $(LFLAGS) -o test_btree binary_tree.o test_btree.o $(IFLAGS)
	$(CC) $(LFLAGS) -o test_link link_list.o test_link.o

clean:
	rm -f *.o
	rm -fr test_btree
	rm -fr test_link
