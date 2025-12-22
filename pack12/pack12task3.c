#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int val;
    unsigned prior;
    struct Node *left;
    struct Node *right;
}Node;

Node *create(int val){
    Node *new = malloc(sizeof(Node));
    new->val = val;
    new->prior = rand();
    new->left = new->right = NULL;
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
    
    if(val < root->val){
        root->left = insert(root->left, val);
        if(root->left->prior > root->prior)
            root = rotR(root);
    }
    else if(val > root->val){
        root->right = insert(root->right, val);
        if(root->right->prior > root->prior)
            root = rotL(root);
    }

    return root;
}

int find(Node *root, int val){
    while(root){
        if(root->val == val)
            return 1;
        if(val < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

Node *rem(Node *root, int val){
    if(!root)
        return NULL;
    
    if(val < root->val)
        root->left = rem(root->left, val);
    else if(val > root->val)
        root->right = rem(root->right, val);
    else{
        if(!root->left){
            Node *R = root->right;
            free(root);
            return R;
        }
        if(!root->right){
            Node *L = root->left;
            free(root);
            return L;
        }

        if(root->left->prior > root->right->prior){
            root = rotR(root);
            root->right = rem(root->right, val);
        }
        else{
            root = rotL(root);
            root->left = rem(root->left, val);
        }
    }    
    return root;
}

int lower(Node *root, int val, int *res){
    int done = 0;

    while (root)
    {
        if(val <= root->val){
            *res = root->val;
            done = 1;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return done;
}

int main(void){
    int N;
    scanf("%d", &N);

    Node *root = NULL;
    char op[10];
    int val;
    for(int i = 0; i < N; i++){
        scanf("%s %d", op, &val);
        
        if(strcmp(op, "add") == 0){
            if(find(root, val))
                printf("dupe\n");
            else{
                root = insert(root, val);
                printf("added\n");
            }
        }
        else if(strcmp(op, "remove") == 0){
            if(!find(root, val))
                printf("miss\n");
            else{
                root = rem(root, val);
                printf("removed\n");
            }
        }
        else if(strcmp(op, "lower") == 0){
            int res;
            if(lower(root, val, &res))
                printf("%d\n", res);
            else
                printf("###\n");
        }
    }
    return 0;
}