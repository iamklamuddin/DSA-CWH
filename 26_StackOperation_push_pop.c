#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;

};
int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;

    }
    else{
        return 0;
    }
}
int isFull(struct stack* ptr){
    if(ptr->top ==ptr->size-1){
        return 1;
    }
    else{
        return 0;

    }
}
void push(struct stack* ptr,int val){
    if(isFull(ptr)){
        printf("Stack is Overflow\n");

    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop (struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack is underflow\n");
        return -1;

    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;

    }
}
int main(){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top= -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int ));
    printf("Stack has been craeted succesfully\n");
    printf("Before pushing , %d\n",isFull(sp));
    printf("Before pushing , %d\n",isEmpty(sp));
    
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);
    push(sp,7);
    push(sp,8);
printf("")

    

    return 0;


}