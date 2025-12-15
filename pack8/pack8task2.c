#include <stdio.h>

int binSearch(int arr[], int N, int X){
    int lft = 0;
    int rgt = N - 1;

    while(lft <= rgt){
        int mid = lft + (rgt - lft) / 2;

        if(arr[mid] == X){
            while ((arr[mid] == arr[mid + 1]) && ((mid + 1) <= rgt))
            {
                mid = mid + 1;
            }
            return mid;
        }
        else if(arr[mid] < X)
            lft = mid + 1;
        else
            rgt = mid - 1;
    }
    return -1;
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    int Q;
    scanf("%d", &Q);

    int X, Y, R;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &X);
        if(i == 0)
            Y = X;
        else
            Y = X + R;
        
        R = binSearch(arr, N, Y);
        // R = binSearch(arr, N, X);
        printf("%d\n", R);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}