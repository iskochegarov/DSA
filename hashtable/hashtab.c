#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "hashtab.h"

#define HASHTAB_SIZE 1000
#define HASHTAB_MUL 31


struct listnode *hashtab[HASHTAB_SIZE];
// KP_hash 
 
unsigned int KP_hash(char *key) 
{
	unsigned int h = 0; char *p;
	for (p = key; *p != '\0'; p++)
	{
		h = h * HASHTAB_MUL + (unsigned int)*p;
	}
	return h % HASHTAB_SIZE;
}


//ELF_hash
/*
unsigned int ELFhash(char *key) 
{
	unsigned int h = 0, g;
	while(*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000L;
		if(g) 
			h ^= g >> 24;
		h &= ~g;
	}
return h % HASHTAB_SIZE;
}
*/

void hashtab_init (struct listnode **hashtab) {
	int i;
	for (i = 0; i < HASHTAB_SIZE; i++) {
		hashtab[i] = NULL;
	}
}

int hashtab_add (struct listnode **hashtab, char*key, int value) {
	struct listnode *node;
	int index = KP_hash(key) /*ELFhash(key)*/, collis;
	node = malloc (sizeof (*node));
	if(hashtab[index] != NULL) {
			collis++;		
	}
	if (node != NULL) {
		node->key = key;
		node->value = value;
//		printf("value %d ", node->value);
//		printf("ind %d ", index);
		node->next = hashtab[index];
		hashtab[index] = node;
	}
	return collis;
}

struct listnode *hashtab_lookup (struct listnode **hashtab, char *key) {
	int index;
	struct listnode *node;
	index = KP_hash(key); //ELFhash(key);
	for (node = hashtab[index]; node  != NULL; node = node->next) {
		if (strcmp (node->key, key) == 0)
			return node;
	}
	return NULL;
}

void hashtab_delete (struct listnode **hashtab, char *key) {
	int index;
	struct listnode *p, *prev = NULL;
	index = KP_hash(key); //ELFhash(key);
	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp (p->key, key) == 0) {
			if (prev == NULL)
				hashtab[index] = p->next;
			else
				prev->next = p->next; 
			free (p);
			return;
		}
		prev = p;
	}
}
