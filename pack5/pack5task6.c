#include <stdio.h>

typedef struct LongNum_s
{
    int len;
    int arr[5000];
}LongNum;

void popa(LongNum *ans, int m){
    int prod = 0, i = 0;
    long long int carry = 0;
    while (i < ans->len)
    {
        prod = (ans->arr[i] * m) + carry;
        ans->arr[i] = prod % 10;
        carry = prod / 10;
        i++;
    }

    while (carry > 0)
    {
        ans->arr[i] = carry % 10;
        carry = carry / 10;
        i++;
    }
    
    ans->len = i;
}

int main(void){
    LongNum digit;
    digit.arr[0] = 1;
    digit.len = 1;

    int N;
    scanf("%d", &N);

    for(int i = 1; i < N + 1; i++){
        popa(&digit, i);
    }

    for(int i = digit.len - 1; i > -1; i--){
        printf("%d", digit.arr[i]);
    }
    //printf("\n%d", digit.len);
}
