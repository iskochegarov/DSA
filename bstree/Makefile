bstree: bstree_main.o bstree.o 
	gcc -o bstree bstree_main.o bstree.o 

bstree_main.o: bstree_main.c
	gcc -c bstree_main.c 

bstee.o: bstree.c
	gcc -c bstree.c 

.PHONY: clean
clean:
	rm -f bstree hashtab *.o