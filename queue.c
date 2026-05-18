#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue* q_create() {
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void q_enqueue(Queue *q, const char *s) {
    QNode *n = malloc(sizeof(QNode));
    strncpy(n->query, s, MAX_WORD);
    n->query[MAX_WORD-1] = '\0';
    n->next = NULL;
    if (!q->rear) q->front = q->rear = n;
    else { q->rear->next = n; q->rear = n; }
}

int q_dequeue(Queue *q, char *out) {
    if (!q->front) return 0;
    QNode *n = q->front;
    strncpy(out, n->query, MAX_WORD);
    out[MAX_WORD-1] = '\0';
    q->front = n->next;
    if (!q->front) q->rear = NULL;
    free(n);
    return 1;
}

void q_free(Queue *q) {
    char tmp[MAX_WORD];
    while (q_dequeue(q, tmp));
    free(q);
}