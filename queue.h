#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"

typedef struct QNode {
    char query[MAX_WORD];
    struct QNode *next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

Queue* q_create();
void q_enqueue(Queue *q, const char *s);
int q_dequeue(Queue *q, char *out);
void q_free(Queue *q);

#endif