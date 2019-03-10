/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

//defining a struct as containing a value,
//and a pointer to the next node
typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    Node *head = *list; //creater another reference to head
    //Node *head = NULL;
    if (head == NULL) return -1;
    int thing = (*list)->val;
    *list = (*list)->next; //whatever list is pointing to, make it point to the next node in the list
    free(head); //free the first node, but not the rest!
    //printf("Your value: %i\n", thing);

    return thing;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
     Node *head = *list; //creater another reference to head
     Node *newhead = make_node(val, head); //makes a node
     //int thing = (*list)->val;
     *list = newhead; //*list is a pointer to a Node, newhead is a pointer to a Node
     //free(head); //free the first node, but not the rest!
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    Node *head = *list;
    int previous;
    while (1) {
      int thing = head->val;
      //printf("value is %i\n",thing);
      if (thing == val){
        Node **newlist = &head;
        pop(newlist);
        push(newlist, 1);
        //head->val = 4;
        break;
      }
      head = head->next;
    }
    ///free(head);
    // FILL THIS IN!
    return 1;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    // FILL THIS IN!
}


int main() {
    Node *head = make_node(1, NULL); //makes a node
    head->next = make_node(2, NULL); //head is the original node, next is pointer to the following nodes
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);
    //head->next->next->next->next = make_node(5, NULL); //example if wanted to extend

    //list is a pointer to the head, which is a pointer to a node

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    printf("Removing %i\n", retval);
    print_list(list);

    push(list, retval+10);
    printf("Pushing 11 to front \n");
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    //remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);

    return 0;
}
