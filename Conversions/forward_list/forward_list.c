#include <stdio.h>
#include <stdlib.h>
#include "forward_list.h"

#define empty_list        "List is empty."
#define exit_msg          "Out of memory...Program terminated." 

static const unsigned char node_size = sizeof(node);


void push_front(node **head, signed char data)
{
    node *new_node = (node *) malloc(node_size);
    if(!new_node)
    {
        puts(exit_msg); 
        exit(EXIT_FAILURE); 
    }
    new_node->data = data;
    new_node->next = *head; 
    *head = new_node;
}


void pop_front(node **head)
{
    if(!*head)
    {
		puts(empty_list); 
        return;
    }
    struct node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}
    

int is_empty(node *head)
{
    if(!head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void display(node *head)
{
    for (node *it = head; it; it = it->next)
    {
		printf("%c", it->data);
    }
    puts(""); 
}


void erase(node **head)
{
    if(!*head)
    {
		puts(empty_list); 
        return;
    }
    node *tmp = NULL;
    for (node *it = *head; it; )
    {
    	tmp = it;
        it = it->next; 
        free(tmp);
    }
    *head = NULL; 
}

