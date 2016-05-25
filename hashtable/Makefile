hashtab: hash_main.o hashtab.o
	gcc -o hashtab hash_main.o hashtab.o
	
hash_main.o: hash_main.c
	gcc -c hash_main.c
	
hashtab.o: hashtab.c
	gcc -c hashtab.c

.PHONY: clean
clean:
	rm -f bstree hashtab *.o
