#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x - y);
}

int main(void){
    int A, usA = 0;
    scanf("%d", &A);

    int a[A];
    for(int i = 0; i < A; i++){
        scanf("%d", &a[i]);
        if((i > 0) && (a[i - 1] > a[i])) usA++;
    }

    int B, usB = 0;
    scanf("%d", &B);

    int b[B];
    for(int i = 0; i < B; i++){
        scanf("%d", &b[i]);
        if((i > 0) && (b[i - 1] > b[i])) usB++;
    }

    if(usA > 0) qsort(a, A, sizeof(int), cmp);
    if(usB > 0) qsort(b, B, sizeof(int), cmp);

    int c[B], k = 0;
    c[k] = 0;
    for(int i = 0; i < A; i++){
        int x = 0;
        for(int j = 0; j < B; j++){
            if(a[i] == b[j]) x++;
        }
        if(x == 0){
            if(i == 0){
                c[k] = a[i];
                k++;
            }
            else if(a[i - 1] != a[i]){
                c[k] = a[i];
                k++;
            }
        }
    }

    printf("%d\n", k);
    for(int i = 0; i < k; i++) printf("%d ", c[i]);
}