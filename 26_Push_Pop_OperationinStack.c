#include<stdio.h>
#include<stdlib.h>
struct stack {
    int size;
    int top;
    int *arr;

};
int isEmpty(struct stack* ptr){
    if(ptr->top ==-1){
        return 1;

    }
    else{
        return 0;

    }
}
 int isFull(struct stack* ptr){
     if(ptr->top == ptr->size -1){
         return 1;

     }
     else {
         return 0;

     }
 }

 void push(struct stack* ptr, int val){
     if(isFull(ptr)){
         printf("Stack overflow! cannot push %d to the stack\n",val);

     }
     else{
         ptr->top++;
         ptr->arr[ptr->top] = val;
     }
 }

 int pop(struct stack* ptr){
     if(isEmpty(ptr)){
         printf("Stack underflow can not pop from the stack\n");
         return -1;


     }
     else{
         int val = ptr->arr[ptr->top];
         ptr->top--;
         return val;

     }
 }

 int main(){
     struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
     sp->size= 10;
     sp->top = -1;
     sp->arr = (int *)malloc(sp->size * sizeof (int));
     printf("stack has been created succesful\n");
     printf("before pushing , Full: %d\n", isFull(sp));
     printf("Before pushing,Empty: %d\n", isEmpty(sp));
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6);
    printf("after pushing , Full: %d\n", isFull(sp));
    printf("after pushing,Empty: %d\n", isEmpty(sp));





     return 0;
 }