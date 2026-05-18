#ifndef GRAPH_H
#define GRAPH_H
#include "common.h"

typedef struct Edge {
    int to;
    struct Edge *next;
} Edge;

typedef struct GNode {
    char doc[MAX_DOCNAME];
    Edge *edges;
} GNode;

typedef struct Graph {
    GNode nodes[MAX_DOCS];
    int n;
} Graph;

void graph_init(Graph *g);
int graph_get_index(Graph *g, const char *doc);
void graph_add_edge(Graph *g, const char *a, const char *b);
void graph_print(Graph *g);

#endif