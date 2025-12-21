#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

typedef void (*callback)(void *cntx, int *value);

void arrayForeach(void *cntx, callback func, int arr[], int n){
    for(int i = 0; i < n; i++){
        func(cntx, &arr[i]);
    }
}

void nodeForeach(void *cntx, callback func, Node *head){
    Node *temp = head;
    while(temp){
        func(cntx, &temp->value);
        temp = temp->next;
    }
}

void sumEv(void *cntx, int *value){
    int *sum = (int *)cntx;
    if(*value % 2 == 0){
        *sum = *sum + *value;
    }
}

int main(void){
    int N;
    scanf("%d", &N);

    int arr[N];
    Node *head = NULL;
    Node *tail = NULL;

    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);

        Node *temp = malloc(sizeof(Node));
        temp->value = arr[i];
        temp->next = NULL;

        if(!head){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    int sumArr = 0;
    arrayForeach(&sumArr, sumEv, arr, N);

    int sumNode = 0;
    nodeForeach(&sumNode, sumEv, head);

    printf("%d %d\n", sumArr, sumNode);

    Node *cur = head;
    while (cur)
    {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    return 0;
}