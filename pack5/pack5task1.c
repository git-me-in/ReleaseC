#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    double x;
    double s[N];
    for(int i = 0; i < N; i++){
        scanf("%lf", &x);
        double Rn = 1.0;
        double n = 1.0;
        double T = 1.0;
        int negr = 0;
        if (x < 0){
            negr++;
            x = -x;
        }
        while(n < 200){
            T = T * x / n;
            Rn = Rn + T;
            if(T < 1e-16){
                break;
            }
            n++;
        }
        if(negr != 0){
            Rn = 1.0 / Rn;
        }
        s[i] = Rn;
    }

    for(int i = 0; i < N; i++){
        printf("%0.15g\n", s[i]);
    }
    
    return 0;
}