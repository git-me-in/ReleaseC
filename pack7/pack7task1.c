#include <stdio.h>
#include <string.h>

void count_sort(int arr[], int n)
{
    int cnt[4] = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cnt[0]++;
        else if (arr[i] == 2)
            cnt[1]++;
        else if (arr[i] == 4)
            cnt[2]++;
        else
            cnt[3]++;
    }
    int k = 0;
    while (cnt[0]--)
        arr[k++] = 1;
    while (cnt[1]--)
        arr[k++] = 2;
    while (cnt[2]--)
        arr[k++] = 4;
    while (cnt[3]--)
        arr[k++] = 8;
}

int Bsum(int arr[], int N)
{
    int Bsum1 = 0;
    for (int k = 0; k < N; k++)
    {
        if (arr[k] == 1)
        {
            Bsum1 = Bsum1 + arr[k];
        }
        else if (arr[k] == 2)
        {
            if (Bsum1 == 0)
            {
                Bsum1 = Bsum1 + 2;
                Bsum1 = Bsum1 + arr[k];
            }
            else if (Bsum1 % arr[k] != 0)
            {
                Bsum1 = ((Bsum1 / arr[k]) + 1) * arr[k];
                Bsum1 = Bsum1 + arr[k];
            }
            else
            {
                Bsum1 = Bsum1 + arr[k];
            }
        }
        else if (arr[k] == 4)
        {
            if (Bsum1 == 0)
            {
                Bsum1 = Bsum1 + 4;
                Bsum1 = Bsum1 + arr[k];
            }
            else if (Bsum1 % arr[k] != 0)
            {
                Bsum1 = ((Bsum1 / arr[k]) + 1) * arr[k];
                Bsum1 = Bsum1 + arr[k];
            }
            else
            {
                Bsum1 = Bsum1 + arr[k];
            }
        }
        else if (arr[k] == 8)
        {
            if (Bsum1 == 0)
            {
                Bsum1 = Bsum1 + 8;
                Bsum1 = Bsum1 + arr[k];
            }
            else if (Bsum1 % arr[k] != 0)
            {
                Bsum1 = ((Bsum1 / arr[k]) + 1) * arr[k];
                Bsum1 = Bsum1 + arr[k];
            }
            else
            {
                Bsum1 = Bsum1 + arr[k];
            }
        }
    }

    return Bsum1;
}

int Wsum(int arr[], int N)
{
    int Wsum1 = 0;
    int R = N - 1, L = 0;
    while (L <= R)
    {
        if (L == R)
        {
            if (arr[L] == 1)
            {
                Wsum1 = Wsum1 + arr[L];
            }
            else if (arr[L] == 2)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 2;
                    Wsum1 = Wsum1 + arr[L];
                }
                else if (Wsum1 % arr[L] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[L]) + 1) * arr[L];
                    Wsum1 = Wsum1 + arr[L];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[L];
                }
            }
            else if (arr[L] == 4)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 4;
                    Wsum1 = Wsum1 + arr[L];
                }
                else if (Wsum1 % arr[L] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[L]) + 1) * arr[L];
                    Wsum1 = Wsum1 + arr[L];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[L];
                }
            }
            else if (arr[L] == 8)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 8;
                    Wsum1 = Wsum1 + arr[L];
                }
                else if (Wsum1 % arr[L] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[L]) + 1) * arr[L];
                    Wsum1 = Wsum1 + arr[L];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[L];
                }
            }
        }
        else
        {
            // R side
            if (arr[R] == 1)
            {
                Wsum1 = Wsum1 + arr[R];
            }
            else if (arr[R] == 2)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 2;
                    Wsum1 = Wsum1 + arr[R];
                }
                else if (Wsum1 % arr[R] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[R]) + 1) * arr[R];
                    Wsum1 = Wsum1 + arr[R];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[R];
                }
            }
            else if (arr[R] == 4)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 4;
                    Wsum1 = Wsum1 + arr[R];
                }
                else if (Wsum1 % arr[R] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[R]) + 1) * arr[R];
                    Wsum1 = Wsum1 + arr[R];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[R];
                }
            }
            else if (arr[R] == 8)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 8;
                    Wsum1 = Wsum1 + arr[R];
                }
                else if (Wsum1 % arr[R] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[R]) + 1) * arr[R];
                    Wsum1 = Wsum1 + arr[R];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[R];
                }
            }

            // L side
            if (arr[L] == 1)
            {
                Wsum1 = Wsum1 + arr[L];
            }
            else if (arr[L] == 2)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 2;
                    Wsum1 = Wsum1 + arr[L];
                }
                else if (Wsum1 % arr[L] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[L]) + 1) * arr[L];
                    Wsum1 = Wsum1 + arr[L];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[L];
                }
            }
            else if (arr[L] == 4)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 4;
                    Wsum1 = Wsum1 + arr[L];
                }
                else if (Wsum1 % arr[L] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[L]) + 1) * arr[L];
                    Wsum1 = Wsum1 + arr[L];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[L];
                }
            }
            else if (arr[L] == 8)
            {
                if (Wsum1 == 0)
                {
                    Wsum1 = Wsum1 + 8;
                    Wsum1 = Wsum1 + arr[L];
                }
                else if (Wsum1 % arr[L] != 0)
                {
                    Wsum1 = ((Wsum1 / arr[L]) + 1) * arr[L];
                    Wsum1 = Wsum1 + arr[L];
                }
                else
                {
                    Wsum1 = Wsum1 + arr[L];
                }
            }
        }

        R--;
        L++;
    }

    return Wsum1;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char type[7][8] = {"char", "short", "int", "long", "float", "int64_t", "double"};
    char end[3] = "};";

    int LP32[50];
    int ILP32[50];
    int LLP64[50];
    int LP64[50];
    int i = 0;

    char stuff[50];
    scanf("%s %s %s", stuff, stuff, stuff);

    while (strcmp(stuff, end) != 0)
    {
        if (strcmp(stuff, type[0]) == 0)
        { // char
            LP32[i] = 1;
            ILP32[i] = 1;
            LLP64[i] = 1;
            LP64[i] = 1;
        }
        else if (strcmp(stuff, type[1]) == 0)
        { // short
            LP32[i] = 2;
            ILP32[i] = 2;
            LLP64[i] = 2;
            LP64[i] = 2;
        }
        else if (strcmp(stuff, type[2]) == 0)
        { // int
            LP32[i] = 2;
            ILP32[i] = 4;
            LLP64[i] = 4;
            LP64[i] = 4;
        }
        else if (strcmp(stuff, type[3]) == 0)
        { // long
            LP32[i] = 4;
            ILP32[i] = 4;
            LLP64[i] = 4;
            LP64[i] = 8;
        }
        else if (strcmp(stuff, type[4]) == 0)
        { // float
            LP32[i] = 4;
            ILP32[i] = 4;
            LLP64[i] = 4;
            LP64[i] = 4;
        }
        else if (strcmp(stuff, type[5]) == 0)
        { // int64_t
            LP32[i] = 8;
            ILP32[i] = 8;
            LLP64[i] = 8;
            LP64[i] = 8;
        }
        else if (strcmp(stuff, type[6]) == 0)
        { // double
            LP32[i] = 8;
            ILP32[i] = 8;
            LLP64[i] = 8;
            LP64[i] = 8;
        }
        scanf("%s", stuff);
        if (stuff[0] == '*')
        { // pointer
            LP32[i] = 4;
            ILP32[i] = 4;
            LLP64[i] = 8;
            LP64[i] = 8;
            scanf("%s", stuff);
        }
        i++;
        scanf("%s", stuff);
    }

    // for(int k = 0; k < i; k++){
    //     printf("%d %d %d %d\n", LP32[k], ILP32[k], LLP64[k], LP64[k]);
    // }

    count_sort(LP32, i);
    count_sort(ILP32, i);
    count_sort(LLP64, i);
    count_sort(LP64, i);

    // for(int k = 0; k < i; k++){
    //     printf("%d %d %d %d\n", LP32[k], ILP32[k], LLP64[k], LP64[k]);
    // }

    printf("%d %d\n", Bsum(LP32, i), Wsum(LP32, i));
    printf("%d %d\n", Bsum(ILP32, i), Wsum(ILP32, i));
    printf("%d %d\n", Bsum(LLP64, i), Wsum(LLP64, i));
    printf("%d %d", Bsum(LP64, i), Wsum(LP64, i));

    fclose(stdin);
    fclose(stdout);
    // int ptr;
    // printf("size - %d", sizeof(ptr));
    return 0;
}