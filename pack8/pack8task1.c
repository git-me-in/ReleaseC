#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stroka
{
    int len;
    char *data;
    struct stroka *next;
}st;

st *createst(char *data, int L)
{
    st *s = malloc(sizeof(st));
    s->data = malloc(L + 1);
    strcpy(s->data, data);
    s->len = L;
    s->next = NULL;
    return s;
}

void addst(st **head){
    st *s = malloc(sizeof(st));
    scanf("%d", &s->len);
    s->data = malloc(s->len + 1);
    scanf("%s", s->data);
    s->next = NULL;

    if(*head == NULL){
        *head = s;
        return;
    }

    st *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = s;
}

void delst(st **head){
    int pos;
    scanf("%d", &pos);
    
    st *temp = *head;
    for(int i = 0; i < pos; i++)
        temp = temp->next;
    
    free(temp->data);
}

void printst(st **head){
    int pos;
    scanf("%d", &pos);
    
    st *temp = *head;
    for(int i = 0; i < pos; i++)
        temp = temp->next;
    
    printf("%s\n", temp->data);
}

void findst(st **head){
    int pos;
    char sym;
    scanf("%d %c", &pos, &sym);
    // char sym;
    // scanf("%c", &sym);
    
    st *temp = *head;
    for(int i = 0; i < pos; i++)
        temp = temp->next;
    
    int sum = 0;
    for(int i = 0; i < temp->len; i++)
        if(temp->data[i] == sym) sum++;
    printf("%d\n", sum);
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    st *head = NULL;

    int op;
    int ind = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &op);
        if(op == 0){
            addst(&head);
            ind++;
        }
        else if(op == 1){
            delst(&head);
        }
        else if(op == 2){
            printst(&head);
        }
        else if(op == 3){
            findst(&head);
        }
    }

    // while (head->next != NULL){
    //     if(head->data != NULL) free(head->data);
    //     head = head->next;
    // }

    fclose(stdin);
    fclose(stdout);
    return 0;
}