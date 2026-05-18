#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Occurrence* occ_create(const char *doc) {
    Occurrence *h = malloc(sizeof(Occurrence));
    if (!h) return NULL;
    strncpy(h->doc, doc, MAX_DOCNAME);
    h->doc[MAX_DOCNAME-1] = '\0';
    h->freq = 1;
    h->next = NULL;
    return h;
}

void occ_add_or_inc(Occurrence *head, const char *doc) {
    if (!head) return;
    Occurrence *cur = head;
    while (cur) {
        if (strcmp(cur->doc, doc) == 0) {
            cur->freq++;
            return;
        }
        if (!cur->next) break;
        cur = cur->next;
    }
    Occurrence *n = malloc(sizeof(Occurrence));
    strncpy(n->doc, doc, MAX_DOCNAME);
    n->doc[MAX_DOCNAME-1] = '\0';
    n->freq = 1;
    n->next = NULL;
    cur->next = n;
}

void occ_print(Occurrence *head) {
    Occurrence *c = head;
    while (c) {
        printf("%s(%d) ", c->doc, c->freq);
        c = c->next;
    }
    printf("\n");
}

void occ_free(Occurrence *head) {
    Occurrence *c = head;
    while (c) {
        Occurrence *t = c;
        c = c->next;
        free(t);
    }
}

int occ_get_freq(Occurrence *head, const char *doc) {
    Occurrence *c = head;
    while (c) {
        if (strcmp(c->doc, doc) == 0) return c->freq;
        c = c->next;
    }
    return 0;
}