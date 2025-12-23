#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 8

typedef struct{
    long long ind;
    char data[LEN];
}Stng;

void sort(Stng a[], int N){
    for(int i = 1; i < N; i++){
        Stng tmp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].ind > tmp.ind)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    Stng arr[10000];

    for(int i = 0; i < N; i++){
        scanf("%lld %s", &arr[i].ind, arr[i].data);
    }

    sort(arr, N);

    for(int i = 0; i < N; i++){
        printf("%lld %s\n", arr[i].ind, arr[i].data);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}