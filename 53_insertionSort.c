#include<stdio.h>

void printArray(int* A,int n){
    for(int i=0;i<n;i++)
    {
        printf("%d",A[i]);

    }
    printf("\n");
}

void insertionSort(int *A,int n){
    int key,j;
    // loop for passes
    for(int i=1;i<=n-1;i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;

        }
        A[j+1] = key;
    }

}

int main(){

    // -1  0  1  2  3  4
    //     12,|54,65,07,23,09 --> i = 1, key = 54, j = 0;
    //    12, |54,65,07,23,09 --> ist pass done(i=1) 

   //    12, 54,|65,07,23,09 --> i=2,key = 65,j=1;
   //    12, 54,|65,07,23,09 --> 2nd pass done (i=2) 

   //   12, 54,65,|07,23,09 --> i=3,key = 7,j=2
   //   12, 54,65,|65,23,09 --> i=3,key = 7,j=1
   //   12, 54,54,|65,23,09 --> i=3,key = 7,j=0
   //   12, 12,54,|65,23,09 --> i=3,key = 7,j=-1
   //   07, 12,54,|65,23,09 --> i=3,key = 7,j=-1 3rd pass done(i=3) 

   // fast forwarding  4rth and 5th pass will give
   //  07, 12,54,65,|23,09 --> i=4,key = 23, j=4
   //  07, 12,23,54,|65,09 --> after the fourth pass

   //  07, 12,23,54,65,|09 -->
   //  07, 09,12,23,54,65| -->

   


    
    int A[] = {12,54,65,7,23,9};
    int n = 6;
    printArray(A,n);
    insertionSort(A,n);
    printf("\n");
    printArray(A,n);

    return 0;
     
}