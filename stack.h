#ifndef STACK_H
#define STACK_H
#include "common.h"

typedef struct SearchResult {
    char query[MAX_WORD];
    char docs[10][MAX_DOCNAME];
    int ndocs;
} SearchResult;

typedef struct StackNode {
    SearchResult res;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

Stack* stack_create();
void stack_push(Stack *s, SearchResult *sr);
int stack_pop(Stack *s, SearchResult *out);
void stack_free(Stack *s);

#endif