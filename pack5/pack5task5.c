#include <stdio.h>

typedef struct LongNum_s
{
    int len;
    int arr[500];
}LongNum;

void pochti_popa(LongNum *one, LongNum *two){
    int i = 0, tsum = 0, carry = 0;
    while(i < two->len){
        if(i < one->len){
            tsum = one->arr[i] + two->arr[i] + carry;
            one->arr[i] = two->arr[i];
            if(tsum > 9){    
                two->arr[i] = tsum % 10;
                carry = tsum / 10;
            }
            else{
                two->arr[i] = tsum;
                carry = 0;
            }
        }
        else{
            one->arr[i] = two->arr[i];
            two->arr[i] = two->arr[i] + carry;
            carry = 0;
        }
        //printf("%d - %d\n", i, two->arr[i]);
        i++;
    }
    one->len = two->len;
    if(carry != 0){
        two->arr[i] = carry;
        //printf("%d - %d\n", i, two->arr[i]);
        two->len = i + 1;
    }
    //printf("len = %d\n", two->len);
}

int main(void){
    LongNum first;
    LongNum second;

    first.len = 1;
    second.len = 1;
    first.arr[0] = 1;
    second.arr[0] = 1;

    // printf("len before = %d", second.arr[0]);
    int N;
    scanf("%d", &N);
    for(int i = 2; i < N; i++){
        //printf("%d: ", i);
        pochti_popa(&first, &second);
    }

    int L = second.len;
    for(int i = L - 1; i > - 1; i--){
        printf("%d", second.arr[i]);
    }
    // for (int i = 0; i < L; i++)
    // {
    //     printf("%d", second.arr[i]);
    // }
    
    return 0;
}
