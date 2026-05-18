#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void graph_init(Graph *g) {
    g->n = 0;
    for (int i = 0; i < MAX_DOCS; i++) g->nodes[i].edges = NULL;
}

int graph_get_index(Graph *g, const char *doc) {
    for (int i = 0; i < g->n; i++)
        if (strcmp(g->nodes[i].doc, doc) == 0) return i;
    int idx = g->n++;
    strncpy(g->nodes[idx].doc, doc, MAX_DOCNAME);
    g->nodes[idx].doc[MAX_DOCNAME-1] = '\0';
    g->nodes[idx].edges = NULL;
    return idx;
}

void graph_add_edge(Graph *g, const char *a, const char *b) {
    int u = graph_get_index(g, a);
    int v = graph_get_index(g, b);
    Edge *e = malloc(sizeof(Edge));
    e->to = v; e->next = g->nodes[u].edges; g->nodes[u].edges = e;
}

void graph_print(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%s -> ", g->nodes[i].doc);
        Edge *e = g->nodes[i].edges;
        while (e) {
            printf("%s ", g->nodes[e->to].doc);
            e = e->next;
        }
        printf("\n");
    }
}