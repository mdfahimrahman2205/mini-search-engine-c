#ifndef COMMON_H
#define COMMON_H

#define MAX_WORD 128
#define MAX_DOCNAME 128
#define MAX_DOCS 64
#define MAX_PATH 256

typedef struct Occurrence {
    char doc[MAX_DOCNAME];
    int freq;
    struct Occurrence *next;
} Occurrence;

typedef struct WordNode {
    char word[MAX_WORD];
    Occurrence *occ_head;
    struct WordNode *left, *right;
} WordNode;

#endif