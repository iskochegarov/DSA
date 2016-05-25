#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "bstree.h"

#define LINE_SIZE 1200

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

char *words[200000];

int read_words(char *filename) 
{
	int i = 0;
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
    	perror("Can't open file");
        exit(EXIT_FAILURE);
    }
	char wordmass[LINE_SIZE];

    while (fgets(wordmass, LINE_SIZE, fp)) {
		words[i] = strdup(wordmass);
		words[i] = malloc(strlen(wordmass) * sizeof(char) + 1);
		strcpy(words[i], wordmass);
		i++;
	}
	fclose(fp);
	return i-1;
}

int main(int argc, char *argv[]) 
{
	int i, w, size;
	double t;
	size = read_words(argv[1]);
	struct bstree *tree, *node; 
	tree = bstree_create(words[0], 0); 
  	
  	for (i = 1; i <= size; i++) {  
		bstree_add(tree, words[i], i); 
	}
	
    for(i = 10000; i <= size; i = i + 10000) {
		w = getrand(0, i-1);
		t = wtime();
		
		//bstree_lookup(tree, words[w]);
		node = bstree_max(tree);
		t = wtime() - t;
		printf("%d %.6f\n", i, t);
	}
	
    for(i = 0; i <= size; i++) {
		free(words[i]);	
	}
	
    return 0;
}
