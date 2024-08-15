#include<stdio.h>

void printArray(int* A, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",A[i]);

    }
    printf("\n");
}

void selectionSort(int *A, int n){
    int indexOfMin, temp;
    printf("Running selection sort ...\n");
    for(int i=0;i<n-1;i++)
    {
        indexOfMin = i;
        for(int j = i+1; j<n; j++)
        {
            if(A[j]<A[indexOfMin]){
                indexOfMin = j;

            }
        }
    

    // swap a[i] and a[indexofmin]
    temp = A[i];
    A[i] = A[indexOfMin];
    A[indexOfMin] = temp;
    }


}

int main(){
    // input Array (there will be total n-1 passes. 5-1 = 4 in this case
    // 00 01 02 03 04
    // |03,05,02,13,12

    // after 1st pass 
    // 00 01 02 03 04
    // 02,|05,03,13,12

    // after second pass
    // 00 01 02 03 04 05
    // 02,03,|05,13,12

    // after third pass 
    // 00 01 02 03 04 
    // 02,03,05,|13,12

    // after fourth pass
    // 00 01 02 03 04
    // 02,03,05,12,|13

int A[] = {3,5,2,13,12};
int n=5;
    printArray(A,n);
    printf("\n");
    selectionSort(A,n);
    printf("\n");
    printArray(A,n);

    return 0;
}