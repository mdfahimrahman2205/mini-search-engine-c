#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

Heap* heap_create(int cap) {
    Heap *h = malloc(sizeof(Heap));
    h->arr = malloc(sizeof(HeapItem) * cap);
    h->size = 0;
    h->capacity = cap;
    return h;
}

void heap_free(Heap *h) {
    if (!h) return;
    free(h->arr);
    free(h);
}

static void swap(HeapItem *a, HeapItem *b) {
    HeapItem t = *a; *a = *b; *b = t;
}

void heap_push(Heap *h, const char *doc, int score) {
    if (h->size >= h->capacity) return;
    int i = h->size++;
    strncpy(h->arr[i].doc, doc, MAX_DOCNAME);
    h->arr[i].doc[MAX_DOCNAME-1] = '\0';
    h->arr[i].score = score;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p].score >= h->arr[i].score) break;
        swap(&h->arr[p], &h->arr[i]);
        i = p;
    }
}

int heap_pop(Heap *h, HeapItem *out) {
    if (h->size == 0) return 0;
    *out = h->arr[0];
    h->size--;
    if (h->size > 0) h->arr[0] = h->arr[h->size];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, largest = i;
        if (l < h->size && h->arr[l].score > h->arr[largest].score) largest = l;
        if (r < h->size && h->arr[r].score > h->arr[largest].score) largest = r;
        if (largest == i) break;
        swap(&h->arr[i], &h->arr[largest]);
        i = largest;
    }
    return 1;
}

void heap_clear(Heap *h) { h->size = 0; }