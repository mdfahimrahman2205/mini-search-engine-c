#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "bst.h"
#include "heap.h"
#include "stack.h"
#include "queue.h"
#include "graph.h"

void tokenize_and_index(const char *path, const char *docname, WordNode **root) {
    FILE *f = fopen(path, "r");
    if (!f) { printf("Cannot open %s\n", path); return; }
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        int n = strlen(line);
        char w[MAX_WORD]; int wi = 0;
        for (int i = 0; i <= n; i++) {
            char c = line[i];
            if (isalpha((unsigned char)c)) {
                w[wi++] = tolower((unsigned char)c);
            } else {
                if (wi > 0) {
                    w[wi] = '\0';
                    *root = bst_insert(*root, w, docname);
                    wi = 0;
                }
            }
        }
    }
    fclose(f);
}

void search_and_print(const char *word, WordNode *root, Heap *heap, SearchResult *sr) {
    sr->ndocs = 0;
    strncpy(sr->query, word, MAX_WORD);
    
    WordNode *n = bst_search(root, word);
    
    if (!n) { printf("No results for '%s'\n", word); return; }
    
    Occurrence *oc = n->occ_head;
    while (oc) {
        heap_push(heap, oc->doc, oc->freq);
        oc = oc->next;
    }
    HeapItem it; int idx = 0;
    while (heap_pop(heap, &it) && idx < 10) {
        printf("%d) %s (freq=%d)\n", idx+1, it.doc, it.score);
        strncpy(sr->docs[idx], it.doc, MAX_DOCNAME);
        sr->ndocs = ++idx;
    }
    heap_clear(heap);
}

static void connect_pairs(Occurrence *head, Graph *g) {
    for (Occurrence *a = head; a; a = a->next) {
        for (Occurrence *b = a->next; b; b = b->next) {
            graph_add_edge(g, a->doc, b->doc);
            graph_add_edge(g, b->doc, a->doc);
        }
    }
}

void build_document_graph(WordNode *root, Graph *g) {
    if (!root) return;
    build_document_graph(root->left, g);
    connect_pairs(root->occ_head, g);
    build_document_graph(root->right, g);
}