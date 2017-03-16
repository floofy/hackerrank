#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Data structures
 * https://www.hackerrank.com/challenges/dynamic-array
 *
 * Author: Kenny Yee
 */

typedef struct list List;
typedef struct node Node;
    
struct list {
    Node *head;
    size_t size;
};

struct node {
    unsigned int value;
    struct node *next;
};

List *create_list() {
    List *new_list = malloc(sizeof(List));
    if (!new_list)
        return NULL;
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

Node *create_node(unsigned int value) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void append(List *list, unsigned int value) {
    if (list->head == NULL) {
        list->head = create_node(value);
        list->size = 1;
        return;
    }
    Node *ptr;
    for (ptr = list->head; ptr->next != NULL; ptr = ptr->next)
        ;
    
    ptr->next = create_node(value);
    list->size += 1;
}

int getValue(List *list, unsigned int index) {
    int i;
    Node *ptr = list->head;
    for (i=0; i<index; ++i) {
        if (ptr == NULL)
            return -1;
        ptr = ptr->next;
    }
    return ptr->value;
}

int main() {
    
    int N, Q;
    int i;
    int lastAns = 0;
    int t, x, y;
    List *seq;

    scanf("%d %d", &N, &Q);
    List *list[N];
    for(i=0; i<N; ++i) {
        if (!(list[i] = create_list())) {
            puts("create_list(): error allocating");
            return 1;
        }
    }
    
    for(i=0; i<Q; ++i) {
        scanf("%d %d %d", &t, &x, &y);
        seq = list[(x ^ lastAns) % N];
        if (t == 1) {
            append(seq, y);
        } else if (t == 2) {
            if((lastAns = getValue(seq, y%seq->size)) == -1) {
                puts("getValue(): segfault getting value");
                return 2;
            }
            printf("%d\n", lastAns);
        }
    }
    
    return 0;
}