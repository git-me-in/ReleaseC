#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    double x;
    double s[N];
    for(int i = 0; i < N; i++){
        scanf("%lf", &x);
        double Rn = x;
        double n = 2;
        int count = 0;
        double T = x;
        while(n < 200){
            T = T * (x * x) / (n * (n + 1));
            if(count % 2 == 0){
                Rn = Rn - T;
            }
            else{
                Rn = Rn + T;
            }
            n = n + 2;
            count++;
        }
        s[i] = Rn;
    }
    for(int i = 0; i < N; i++){
        printf("%0.15lf\n", s[i]);
    }
}