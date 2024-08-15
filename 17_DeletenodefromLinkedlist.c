#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void linkedListTravelsal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element %d\n",ptr->data);
        ptr = ptr->next;
    }
}
// case 1: deleting the first element from the linkedlist 
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// case2: delete the element at the given index
struct Node * deleteAtIndex(struct Node * head,int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;


}
// case 3: delete the last element
struct Node * deleteAtLast(struct Node * head){
    struct Node *p= head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q= q->next;

    }

    p->next = NULL;
    free(q);
    return head;

}
// case 4: delete the element with a given value
struct Node *deleteByValue(struct Node * head,int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!= value && q->next!=NULL){
        p = p->next;
        q = q->next;

    }
    if(q->data == value){
        p->next = q->next;
        free(q);

    }
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    // Allocate memory for node in linkedlist
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second node
    head->data = 4;
    head->next = second;
    // Link second and third
    second->data = 3;
    second->next = third;
    // link third and fourth
    third->data = 8;
    third->next = fourth;
    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    // printf("Linked list before deletion\n");
    // linkedListTravelsal(head);
    // head = deleteFirst(head);
    // head = deleteAtIndex(head,2);
    head = deleteAtLast(head);
    printf("Linked list after deletion\n");
    linkedListTravelsal(head);
    return 0;

}