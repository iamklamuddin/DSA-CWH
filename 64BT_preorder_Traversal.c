#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node* createNode(int data){
    struct node* n; // creating a node pointer
    n = (struct node * ) malloc(sizeof(struct node));
    // Allocation memory in the heap
    n->data = data; // setting the data 
    n->left = NULL; // setting the l and r children  
    n->right = NULL; // setting the l and r children 

    return n;
}

    void preorder (struct node* root){
        if(root != NULL){
            printf("%d",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

         int main(){
                // Constructing the root node
                struct node *p = createNode(4);
                struct node *p1 = createNode(1);
                struct node *p2 = createNode(6);
                struct node *p3 = createNode(5);
                struct node *p4 =  createNode(2);

                // Linking the root node with the left and right
                p->left = p1;
                p->right = p2;
                p1->left = p3;
                p1->right = p4;

                preorder(p);
                return 0;
            }
            
        
    




}

