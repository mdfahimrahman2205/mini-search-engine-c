#ifndef LIST_H
#define LIST_H
#include "common.h"

Occurrence* occ_create(const char *doc);
void occ_add_or_inc(Occurrence *head, const char *doc);
void occ_print(Occurrence *head);
void occ_free(Occurrence *head);
int occ_get_freq(Occurrence *head, const char *doc);

#endif