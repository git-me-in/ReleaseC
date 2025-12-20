#include <stdio.h>
#include <stdlib.h>
#define SIZE 2000003

typedef struct Node
{
    int key;
    struct Node *next;
}Node;

Node *table[SIZE];

unsigned hash(int x){
    unsigned h = (unsigned)x;
    h ^= h >> 16;
    return h % SIZE;
}

int check(int x){
    unsigned ind = hash(x);
    Node *temp = table[ind];
    while (temp)
    {
        if(temp->key == x)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void ATHT(int x){
    unsigned ind = hash(x);
    Node *temp = malloc(sizeof(Node));
    temp->key = x;
    temp->next = table[ind];
    table[ind] = temp;
}

int main(void){
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    int N;
    fread(&N, sizeof(int), 1, fin);

    int res[N];
    int k = 0;
    for(int i = 0; i < N; i++){
        int x;
        fread(&x, sizeof(int), 1, fin);
        
        if(!check(x)){
            ATHT(x);
            res[k++] = x;
        }
    }

    fwrite(&k, sizeof(int), 1, fout);
    fwrite(res, sizeof(int), k, fout);

    fclose(fin);
    fclose(fout);

    return 0;
}