#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "bst.h"
#include "heap.h"
#include "stack.h"
#include "queue.h"
#include "graph.h"

void tokenize_and_index(const char *path, const char *docname, WordNode **root);
void search_and_print(const char *word, WordNode *root, Heap *heap, SearchResult *sr);
void build_document_graph(WordNode *root, Graph *g);

int main() {
    WordNode *root = NULL;
    Heap *heap = heap_create(128);
    Stack *history = stack_create();
    Queue *q = q_create();
    Graph g; graph_init(&g);

    printf("Mini Search Engine By Noobs\n");
    printf("Uploaded docs: data/doc1.txt, data/doc2.txt, data/doc3.txt\n");

    int choice; char buf[256];
    while (1) {
        printf("\n");
        printf(" .-------------------------------------------------------.\n");
        printf(" |               MINI SEARCH ENGINE MENU                 |\n");
        printf(" +-------------------------------------------------------+\n");
        printf(" |  1. Load & Index Documents                            |\n");
        printf(" |  2. Show Indexed Words                                |\n");
        printf(" |  3. Search a Word                                     |\n");
        printf(" |  4. Queue Multiple Searches                           |\n");
        printf(" |  5. Show Search History                               |\n");
        printf(" |  6. Undo Last Search                                  |\n");
        printf(" |  7. Show Document Graph                               |\n");
        printf(" |  8. Exit                                              |\n");
        printf(" +-------------------------------------------------------+\n");
        printf("    Enter Choice: ");
        
        if (scanf("%d", &choice) != 1) break;
        getchar();

        if (choice == 1) {
            tokenize_and_index("data/doc1.txt", "doc1.txt", &root);
            tokenize_and_index("data/doc2.txt", "doc2.txt", &root);
            tokenize_and_index("data/doc3.txt", "doc3.txt", &root);
            printf("Index built.\n");
            build_document_graph(root, &g);
        } else if (choice == 2) {
            if (!root) { printf("Index empty. Load docs first.\n"); continue; }
            bst_inorder(root);
        } else if (choice == 3) {
            printf("Enter word: ");
            if (!fgets(buf, sizeof(buf), stdin)) continue;
            buf[strcspn(buf, "\n")] = 0;
            if (strlen(buf) == 0) continue;
            SearchResult sr;
            search_and_print(buf, root, heap, &sr);
            if (sr.ndocs > 0) stack_push(history, &sr);
        } else if (choice == 4) {
            printf("Enter queries separated by commas: ");
            if (!fgets(buf, sizeof(buf), stdin)) continue;
            buf[strcspn(buf, "\n")] = 0;
            char *p = strtok(buf, ",");
            while (p) {
                while (*p == ' ') p++;
                q_enqueue(q, p);
                p = strtok(NULL, ",");
            }
            char qbuf[MAX_WORD];
            while (q_dequeue(q, qbuf)) {
                SearchResult sr;
                search_and_print(qbuf, root, heap, &sr);
                if (sr.ndocs > 0) stack_push(history, &sr);
            }
        } else if (choice == 5) {
            StackNode *c = history->top; int i = 1;
            if (!c) { printf("History empty.\n"); continue; }
            while (c) {
                printf("%d) '%s' -> %d docs\n", i++, c->res.query, c->res.ndocs);
                c = c->next;
            }
        } else if (choice == 6) {
            SearchResult prev;
            if (stack_pop(history, &prev)) printf("Undo: removed '%s'\n", prev.query);
            else printf("Nothing to undo.\n");
        } else if (choice == 7) {
            graph_print(&g);
        } else if (choice == 8) break;
        else printf("Unknown option.\n");
    }

    free_bst(root);
    heap_free(heap);
    stack_free(history);
    q_free(q);
    printf("Bye.\n");
    return 0;
}