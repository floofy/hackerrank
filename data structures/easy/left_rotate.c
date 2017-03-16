#include <stdio.h>
#include <stdlib.h>

/* Data Structure
 * https://www.hackerrank.com/challenges/array-left-rotation
 *
 * Author: Kenny Yee
 */

typedef struct node Node;
typedef struct list List;

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
    int size; 
};

void free_list(List *list) {
    Node *cur, *prev;
    if (!list)
        return;
    else if (!list->head) {
        free(list);
        return;
    }

    while (list->head->next != NULL) {
        prev = list->head;
        cur = list->head->next;

        for (; cur->next != NULL; prev = prev->next, cur = cur->next)
            ;

        free(cur);
        prev->next = NULL;
    } 

   free(list->head); 
   free(list);
}

void print_list(List *list) {
    Node *ptr = list->head;

    while(ptr != NULL) {
        printf("%d%s", ptr->value, (ptr->next != NULL) ? " " : "\n");
        ptr = ptr->next;
    }
}

Node *create_node(int value) {
    Node *new_node;
    
    if (!(new_node = malloc(sizeof(Node))))
        return NULL;

    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

List *create_list() {
    List *new_list;

    if (!(new_list = malloc(sizeof(List))))
        return NULL;

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

int get_new_head_tail(List *list_ptr, 
                      Node **new_head, 
                      Node **new_tail, 
                      size_t index) {
    /* For shifting array, gives back what new head at index and what the new
     * tail should be. Index is the index in the list that is the new head. 
     * Returns 0 in failure and nonzero on success. 
     */
    if (index == 0) {
        *new_head = list_ptr->head;
        *new_tail = list_ptr->tail; 
        return 0;
    }

    int i;
    Node *ptr;
    
    if (!(ptr = list_ptr->head))
        return -1;
    
    for (i=0; i<index - 1; ++i) { 
        ptr = ptr->next;
        if (!ptr) 
            return i+1;
    }

    *new_head = ptr->next;
    *new_tail = ptr;

    if (!new_head || !new_tail)
        return -2;

    return 0;
}

int shift(List *list_ptr, unsigned int amount, size_t size) {
    /* Shifts list
     * 
     */
    Node *new_head, *new_tail, *tail;
    int ret, shift_mod = amount % size;

    if ((ret = get_new_head_tail(list_ptr, &new_head, &new_tail, shift_mod)) != 0)
        return ret;

    tail = list_ptr->tail;
    new_tail->next = NULL;

    if (shift_mod != 0)
        tail->next = list_ptr->head;;

    list_ptr->head = new_head;
    return 0;
}

int append(List *list_ptr, int value) {
    if (list_ptr->head == NULL) {
        if(!(list_ptr->head = create_node(value)))
            return 1;
        list_ptr->tail = list_ptr->head;
        list_ptr->size = 1;
        return 0;
    }

    if (!(list_ptr->tail->next = create_node(value)))
        return 2;
    else {
        list_ptr->tail = list_ptr->tail->next;
        ++list_ptr->size;
    }

    return 0;
}

int scan_list(List *list, size_t size) {
    if (size == 0)
        return 0;

    int value, count = 1;
    size_t i;

    if (scanf("%d", &value) != 1)
        return 0;
    
    if (append(list, value) != 0)
        return 0;

    for (i=0; i<size-1; ++i) {
        if (scanf("%d", &value) != 1)
            return count;

        if (append(list, value) != 0)
            return count;

        ++count;
    }

    return count;
}

int main(int argc, char *argv[]) {
    /* User inputs n, d, where n is the size of array and d is left rotate
     * shifts then enters the array contents. 
     */
    int n, d;
    int i;
    List *list = create_list();

    scanf("%d %d", &n, &d);

    if ((i = scan_list(list, n)) != n) {
        printf("scan_list(): Error. Scanned %d instead of %d\n", i, n);
        return -1;
    } 

    if ((i=shift(list, d, n)) != 0) {
        printf("shift(): Error %d shifting list\n", i);
        return i; 
    }

    print_list(list);
    // free_list(list);     # runs too slow, need double linked list
    return 0;
}

