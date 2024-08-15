#include<stdio.h>
#include<stdlib.h>

struct circulorQueue{
    int size;
    int r;
    int f;
    int* arr;
    
};

int isEmpty(struct circulorQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct circulorQueue *q){
    if((q->r+1)%q->size== q->f){
        return 1;

    }
    return 0;
} 

void enqueue(struct circulorQueue *q,int val){
    if(isFull(q)){
        printf("The queue is full");

    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    printf("enqued element %d\n",val);

    }
}

int dequeue(struct circulorQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("The queue is empty");

    }
    else{
        q->f = (q->f+1)%q->size;
        a= q->arr[q->f];

    }
    return a;
}

int main(){
    struct circulorQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

     // enqueue few element
     enqueue(&q,12);
     enqueue(&q,15);
     enqueue(&q,1);
     printf("dequeing element %d\n",dequeue(&q));
     printf("dequeing element %d\n",dequeue(&q));
     printf("dequeing element %d\n",dequeue(&q));
     enqueue(&q,45);
     enqueue(&q,45);
     enqueue(&q,45);

     if(isEmpty(&q)){
         printf("queue is empty\n");

     }
     if(isFull(&q)){
         printf("queue is full\n");

     }
     return 0;
}
