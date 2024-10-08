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

    void inorder(struct node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

int isBST(struct node* root){
   static struct node *prev = NULL;
    if(root!= NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
        
    }
    else{
            return 1;
        }
}
struct node* searchIter(struct node* root,int key){
    while(root!=NULL){
        if(key==root->data){
            return root;
        }

else if(key<root->data){
    root = root->left;
    
}
else{
    root = root->right;
}
    }
return NULL;
}
void insert(struct node *root,int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("cannot insert %d,alrady in BST",key);
            return;
        }
        else if(key<root->data){
            root= root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}



         int main(){
                // Constructing the root node
                struct node *p = createNode(5);
                struct node *p1 = createNode(3);
                struct node *p2 = createNode(6);
                struct node *p3 = createNode(1);
                struct node *p4 =  createNode(4);


                // Linking the root node with the left and right
                p->left = p1;
                p->right = p2;
                p1->left = p3;
                p1->right = p4;
                
                insert(p,7);
                printf("%d",p->right->right->data);


                return 0;
            }
            
        