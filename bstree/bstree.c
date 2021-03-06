#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bstree.h"

struct bstree {
	char *key;
	int value;
	struct bstree *left;
	struct bstree *right;
};

struct bstree *bstree_create (char *key, int value) {
	struct bstree *node;
	node = malloc (sizeof (*node));
	if (node != NULL) {
		node -> key = key;
		node -> value = value;
		node -> left = NULL;
		node -> right = NULL;
	}
	return node;
}

void bstree_add (struct bstree *tree, char *key, int value)
{
	struct bstree *parent, *node;
	if (tree == NULL)
		return;
	for (parent = tree; tree != NULL; ) {
 		parent = tree;
		if (key < tree->key)
			tree = tree->left;
		else if (key > tree->key)
			tree = tree->right;
		else
			return;
	}
	node = bstree_create (key, value);
	if (key < parent->key)
		parent->left = node;
	else
		parent->right = node;
//	printf(" tree2 %s \n", node->key);
//	printf(" tree3 %d \n", node->value);
}

struct bstree *bstree_lookup (struct bstree *tree, char *key) {
	while(tree != NULL) {
		if (key == tree->key) {
			return tree;
		}
		else if (key < tree->key) {
			tree = tree->left;
		} else {
				tree = tree->right;
		}
	}
	return tree;
}

struct bstree *bstree_min (struct bstree *tree) {
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

struct bstree *bstree_max (struct bstree *tree) {
        if (tree == NULL)
                return NULL;
        while (tree->right != NULL)
                tree = tree->right;
        return tree;
}
