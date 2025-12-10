#include <stdio.h>
#include <math.h>
#define Pi 3.14159265358979323846

// double koren(double x)
// {
//     if(x == 0){
//         return 0.0;
//     }
//     if(x < 0){
//         x = -x;
//     }
//     double t = x;
//     double res = x;
//     int iter = 500;
//     for (int i = 0; i < iter; i++)
//     {
//         t = 0.5 * (t + x / t);
//         res = t;
//     }
//     return res;
// }

// double mycos(double Ax, double Ay, double Bx, double By, double Cx, double Cy){
//     double ans;
//     double AB, BC, CA;
//     double sum1, sum2, sum3;


//     AB = sqrt((Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay));
//     BC = sqrt((Cx - Bx) * (Cx - Bx) + (Cy - By) * (Cy - By));
//     CA = sqrt((Ax - Cx) * (Ax - Cx) + (Ay - Cy) * (Ay - Cy));
//     ans = (pow(AB, 2) + pow(CA, 2) - pow(BC, 2)) / (2 * AB * CA);
//     return ans;
// }

// double arccos(double x){
//     double n = 1.0;
//     double T = x, Rn = x;
//     while (n < 1000000)
//     {
//         T = T * (x * x) * (2 * n - 1) * (2 * n - 1) / (2 * n * (2 * n + 1)); 
//         Rn = Rn + T;
//         n++;
//     }
//     if (x >= 0.99999999999){
//         printf("%0.20g\n", 0);
//         return 0;  // arccos(1) = 0
//     }
//     if (x <= -0.99999999999){
//         printf("%0.20g\n", 180);
//         return 0;  // arccos(-1) = 180
//     }
//     Rn = (Pi / 2 - Rn) * 180 / Pi;
//     printf("%0.20g\n", Rn);
//     return 0;
// }

// int main(void)
// {
//     int Q;
//     scanf("%d", &Q);

//     double x;
//     for (int i = 0; i < Q; i++)
//     {
//         x = cos();
//         printf("%0.20g\n", x);
//         if (x < -1.0 || x > 1.0){
//             return 0.0 / 0.0;
//         }
//         arccos(x);
//     }
//     return 0;
// }

// Функция косинуса через ряд Тейлора
// double cosine(double x) {
//     double sum = 1.0;
//     double term = 1.0;
//     int sign = -1;
    
//     for (int n = 1; n < 50; n++) {
//         term *= (x * x) / ((2*n - 1) * (2*n));
//         sum += sign * term;
//         sign = -sign;
//     }
//     return sum;
// }

// double cosine_small(double y) {
//     return 1.0 - (y * y)/2 * (1.0 - (y * y)/12 * (1.0 - (y * y)/30));
// }

// Арккосинус методом бисекции
// double arccos_bisection(double x) {
//     // if (x >= 1.0) return 0.0;
//     // if (x <= -1.0) return Pi * 180 / Pi;
//     // if (x >= 0.9999) return (koren(2 * (1 - x))) * 180 / Pi;
//     // if (x <= -0.9999) return (Pi - koren(2 * (1 + x))) * 180 / Pi;
//     double low = 0.0;
//     double high = Pi;
//     double mid, cos_mid;
    
//     for (int i = 0; i < 50; i++) {
//         mid = (low + high) / 2;
//         cos_mid = cosine(mid);
        
//         if (cos_mid > x) {
//             low = mid;
//         } else {
//             high = mid;
//         }
//     }
    
//     return (low + high) / 2;
// }

int main() {
    int Q;
    scanf("%d", &Q);

    double result[Q];
    double Ax, Ay, Bx, By, Cx, Cy;
    for (int i = 0; i < Q; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy);

        double AB_x = Bx - Ax;
        double AB_y = By - Ay;
        double AC_x = Cx - Ax;
        double AC_y = Cy - Ay;

        double dot = AB_x * AC_x + AB_y * AC_y;
        double vec = AB_x * AC_y - AB_y * AC_x;

        result[i] = atan2(fabs(vec), dot);
    }
    for (int i = 0; i < Q; i++)
    {
        printf("%0.20g\n", result[i] * 180 / Pi);
    }
    
    return 0;
}