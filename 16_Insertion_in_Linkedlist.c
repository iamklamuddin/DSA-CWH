#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * next;

};
void linkedListTravelsal(struct Node *ptr){
    while(ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// case 1
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;

}
// case2
struct Node * insertAtIndex(struct Node *head,int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;

    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;

}
// case 3
struct Node * insetAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    while(p->next!=NULL){
        p = p->next;

    }
    p->next = ptr;
    ptr->next = NULL;
    return head;

}
// case 4
struct Node * insertAtAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;

}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node  *fourth;
    // allocate memory for node in linkedlist in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // link 1st and second node
    head->data = 7;
    head->next = second;
    // link 2nd and third node 
    second->data = 11;
    second->next = third;
    // link 3rd and forth node
    third->data = 41;
    third->next = fourth;
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("linkedlist before insertion\n");
    linkedListTravelsal (head);
    // head = insertAtFirst(head,56) ;
    // head = insertAtIndex(head,56,1);
    // head = insertAtIndex(head,56);
    head = insertAtAfterNode(head,third,45);
    printf("\nLinkedlist after insertion\n");
    linkedListTravelsal(head);
    return 0;

} 




