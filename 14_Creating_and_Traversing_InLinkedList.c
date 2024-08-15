#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data; 
    struct Node *next;

};
void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
      printf("Element: %d\n", ptr->data);
        ptr = ptr->next;

        
    }

}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // ALLOCATE MEMORY FOR NODES IN THE LINKEDLIST
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // LINK FIRST AND SECOND NODE
    head->data = 7;
    head->next = second;
    // LINK SECOND AND THIRD NODE
    second->data = 11;
    second->next = third;
    // THIRD AND FORTH NODES
    third->data = 41;
    third->next = fourth;
    // TERMINATE THE LIST AT THE THIRD NODE
    fourth->data = 66;
    fourth->next = NULL;
    linkedlistTraversal(head);
    return 0;
}




