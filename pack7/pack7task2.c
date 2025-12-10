#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *data;
    int next;
} Node;

void addNode(Node **list, int *N, int *F){
    int position;
    int c = *N + 1;
    *list = realloc(*list, sizeof(Node) * c);

    (*list)[c - 1].data = malloc(8);

    scanf("%d %s", &position, (*list)[c - 1].data);

    if(position == -1){
        (*list)[c - 1].next = *F;
        *F = c - 1;
    }
    else{
        (*list)[c - 1].next = (*list)[position].next;
        (*list)[position].next = c - 1;
    }
    *N = c;
}

char *delNode(Node **list, int *F){
    int position;
    scanf("%d", &position);
    if(position == -1){
        printf("%s\n", (*list)[*F].data);
        free((*list)[*F].data);
        *F = (*list)[*F].next;
    }
    else{
        int ex = (*list)[position].next;
        (*list)[position].next = (*list)[ex].next;
        printf("%s\n", (*list)[ex].data);
        free((*list)[ex].data);
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    int N, F, Q; 

    for(int i = 0; i < T; i++){ // doing tests(T times)
        scanf("%d %d %d", &N, &F, &Q);
        Node *list = malloc(sizeof(Node) * N);
        
        for(int j = 0; j < N; j++){ // fillin the list with data
            list[j].data = (char*)malloc(sizeof(char) * 8);
            scanf("%s %d", list[j].data, &list[j].next);
        }

        int count = Q;
        int operation;
        while(count != 0){  // performing operations
            scanf("%d", &operation);
            if(operation == 0){ // adding to the list
                addNode(&list, &N, &F);
                printf("%d\n", N - 1);
            }
            if(operation == 1){ // deleting from the list
                delNode(&list, &F);
            }
            count--;
        }
        printf("===\n");

        int p = F;
        while(p != -1){
            printf("%s\n", list[p].data);
            p = list[p].next;
        }
        printf("===\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
