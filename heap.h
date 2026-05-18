#ifndef HEAP_H
#define HEAP_H
#include "common.h"

typedef struct HeapItem {
    char doc[MAX_DOCNAME];
    int score;
} HeapItem;

typedef struct Heap {
    HeapItem *arr;
    int size;
    int capacity;
} Heap;

Heap* heap_create(int cap);
void heap_free(Heap *h);
void heap_push(Heap *h, const char *doc, int score);
int heap_pop(Heap *h, HeapItem *out);
void heap_clear(Heap *h);

#endif