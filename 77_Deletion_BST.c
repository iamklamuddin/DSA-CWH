#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node));
    // memory allocation in the heap
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;

}

void preorder(struct node* root){
    if(root!= NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!= NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
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
        if(isBST(root->left)){
            return 0;

        }
        if(prev!= NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }

}

struct node * searchIter(struct node* root,int key){
    while(root!= NULL){
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
        if(key== root->data){
            printf("cannot insert %d alrady in bst",key);
            return;
        }
        else if(key<root->data){
            root = root->left;
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

struct node *inorderpredecessor(struct node* root){
    root = root->left;
    while(root->right!= NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root,int value){

    struct node* ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL &&root->right==NULL){
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if(value<root->data){
        root->left = deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right = deleteNode(root->right,value);

    }

    // deletion strategy when the node is found
    else{
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left,ipre->data);
    }
    return root;
}

int main(){
    
    // Construting the root node using funtion
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the root node with left and right  children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // inorder(p);
    printf("\n");
    deleteNode(p,6);
    inorder(p);

    return 0;
}
