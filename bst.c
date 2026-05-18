#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "list.h"

static WordNode* new_node(const char *word, const char *doc) {
    WordNode *n = malloc(sizeof(WordNode));
    if (!n) return NULL;
    strncpy(n->word, word, MAX_WORD);
    n->word[MAX_WORD-1] = '\0';
    n->left = n->right = NULL;
    n->occ_head = occ_create(doc);
    return n;
}

WordNode* bst_insert(WordNode *root, const char *word, const char *doc) {
    if (!root) return new_node(word, doc);
    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        occ_add_or_inc(root->occ_head, doc);
    } else if (cmp < 0) {
        root->left = bst_insert(root->left, word, doc);
    } else {
        root->right = bst_insert(root->right, word, doc);
    }
    return root;
}

WordNode* bst_search(WordNode *root, const char *word) {
    if (!root) return NULL;
    int cmp = strcmp(word, root->word);
    if (cmp == 0) return root;
    if (cmp < 0) return bst_search(root->left, word);
    return bst_search(root->right, word);
}

void bst_inorder(WordNode *root) {
    if (!root) return;
    bst_inorder(root->left);
    printf("%s -> ", root->word);
    occ_print(root->occ_head);
    bst_inorder(root->right);
}

void free_bst(WordNode *root) {
    if (!root) return;
    free_bst(root->left);
    free_bst(root->right);
    occ_free(root->occ_head);
    free(root);
}