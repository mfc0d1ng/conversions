#ifdef FORWARD_LIST_H
#error "multiple inclusion of 'forward_list.h'"
#endif

#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

struct node
{
    signed char data;
    struct node *next;
};

typedef struct node node;
typedef struct node* forward_list;


/* Add data to the front of the %forward_list. */
extern void push_front(node **head, signed char data);

/* Remove first element. This is a typical %stack operation.  
 * It shrinks the %forward_list by one. */
extern void pop_front(node **head); 

/* Return true if the %forward_list is empty. */
extern int is_empty(node *head);

/* Display content of the %forward_list. */
extern void display(node *head);

/* Free the memory allocated for the %forward_list. */
extern void erase(node **head); 

#endif
