#ifndef BST_H
#define BST_H
#include "common.h"

WordNode* bst_insert(WordNode *root, const char *word, const char *doc);
WordNode* bst_search(WordNode *root, const char *word);
void bst_inorder(WordNode *root);
void free_bst(WordNode *root);

#endif