#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    int count;
    unsigned prior;
    struct Node *left;
    struct Node *right;
}Node;

Node *create(int val){
    Node *new = malloc(sizeof(Node));
    new->val = val;
    new->count = 1;
    new->prior = rand();
    new->right = new->left = NULL;
    return new;
}

Node *rotR(Node *n){
    Node *q = n->left;
    n->left = q->right;
    q->right = n;
    return q;
}

Node *rotL(Node *n){
    Node *q = n->right;
    n->right = q->left;
    q->left = n;
    return q;
}

Node *insert(Node *root, int val){
    if(!root)
        return create(val);
    
    if(val == root->val){
        root->count++;
        return root;
    }
    else if(val < root->val){
        root->left = insert(root->left, val);
        if(root->left->prior > root->prior)
            root = rotR(root);
    }
    else{
        root->right = insert(root->right, val);
        if(root->right->prior > root->prior)
            root = rotL(root);
    }

    return root;
}

void inorder(Node *root, FILE *f){
    if(!root)
        return;
    
    inorder(root->left, f);

    for(int i = 0; i < root->count; i++)
        fwrite(&root->val, sizeof(int), 1, f);

    inorder(root->right, f);
}

int main(void){
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    int N;
    fread(&N, sizeof(int), 1, fin);

    Node *root = NULL;
    int x;
    for(int i = 0; i < N; i++){
        fread(&x, sizeof(int), 1, fin);
        root = insert(root, x);
    }

    inorder(root, fout);
    
    fclose(fin);
    fclose(fout);
    return 0;
}