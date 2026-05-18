#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack* stack_create() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void stack_push(Stack *s, SearchResult *sr) {
    StackNode *n = malloc(sizeof(StackNode));
    n->res = *sr;
    n->next = s->top;
    s->top = n;
}

int stack_pop(Stack *s, SearchResult *out) {
    if (!s->top) return 0;
    StackNode *n = s->top;
    *out = n->res;
    s->top = n->next;
    free(n);
    return 1;
}

void stack_free(Stack *s) {
    StackNode *c = s->top;
    while (c) {
        StackNode *t = c;
        c = c->next;
        free(t);
    }
    free(s);
}