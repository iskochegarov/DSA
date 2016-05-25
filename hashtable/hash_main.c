#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "hashtab.h"

#define LINE_SIZE 1200
#define HASHTAB_SIZE 1000

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

void read_words(char *filename) 
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
}

int main(int argc, char *argv[])
{
	int i, w, j, collisions = 0;
	double t;
	read_words(argv[1]);
	struct listnode *node;
	hashtab_init(hashtab);

	for(i = 10000; i <= 200000; i += 10000) {
  		for (j = 0; j <= i ; j++) {
		    hashtab_add(hashtab, words[j], j);
		}
		w = getrand(0, i);
		t = wtime();
		/*collisions = */hashtab_lookup(hashtab, words[w]);
		t = wtime() - t;
		//printf("%d %d \n", i, collisions);
		printf("%d %.6f \n", i, t);
	}
	
	return 0;
}
