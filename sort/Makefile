CC=gcc
IFLAGS= -std=c99 -I ../datastruct

all: compile
	$(CC) -o select_sort select_sort.o
	$(CC) -o insert_sort insert_sort.o
	$(CC) -o heap_sort heap.o heap_sort.o
	$(CC) -o merge_sort queue.o link_list.o merge_sort.o
	$(CC) -o quick_sort quick_sort.o

compile:
	$(CC) -c select_sort.c $(IFLAGS)
	$(CC) -c insert_sort.c quick_sort.c $(IFLAGS)
	$(CC) -c ../datastruct/heap.c heap_sort.c $(IFLAGS)	
	$(CC) -c ../datastruct/queue.c ../datastruct/link_list.c \
		merge_sort.c $(IFLAGS)

clean:
	rm -fr *.o
	rm -fr select_sort
	rm -fr insert_sort
	rm -fr heap_sort
	rm -fr merge_sort
	rm -fr quick_sort
