#include <stdio.h>
#include <string.h>

// sort for numbers {1,2,4,8}
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

// function for summing bytes
int add(int sum, int x)
{
    if (x == 1)
        return sum + 1;

    if (sum == 0)
        return x + x;

    if (sum % x != 0)
        sum = ((sum / x) + 1) * x;

    return sum + x;
}

int Bsum(int arr[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum = add(sum, arr[i]);
    return sum;
}

int Wsum(int arr[], int N)
{
    int sum = 0;
    int L = 0, R = N - 1;
    while (L <= R)
    {
        if (L != R)
            sum = add(sum, arr[R]);
        sum = add(sum, arr[L]);
        L++, R--;
    }
    return sum;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    char stuff[50];

    int LP32[50], ILP32[50], LLP64[50], LP64[50];
    int i = 0;

    scanf("%s %s %s", stuff, stuff, stuff); // skipping "struct {" and reading first type

    while (strcmp(stuff, "};") != 0)
    {
        int sLP32, sILP32, sLLP64, sLP64;

        if (!strcmp(stuff, "char"))
            sLP32 = sILP32 = sLLP64 = sLP64 = 1;
        else if (!strcmp(stuff, "short"))
            sLP32 = sILP32 = sLLP64 = sLP64 = 2;
        else if (!strcmp(stuff, "int"))
        {
            sLP32 = 2;
            sILP32 = sLLP64 = sLP64 = 4;
        }
        else if (!strcmp(stuff, "long"))
        {
            sLP32 = 4;
            sILP32 = sLLP64 = 4;
            sLP64 = 8;
        }
        else if (!strcmp(stuff, "float"))
            sLP32 = sILP32 = sLLP64 = sLP64 = 4;
        else
            sLP32 = sILP32 = sLLP64 = sLP64 = 8;

        scanf("%s", stuff);
        if (stuff[0] == '*')
        { // pointer
            sLP32 = 4;
            sILP32 = 4;
            sLLP64 = 8;
            sLP64 = 8;
            scanf("%s", stuff);
        }

        LP32[i] = sLP32;
        ILP32[i] = sILP32;
        LLP64[i] = sLLP64;
        LP64[i] = sLP64;
        i++;
        scanf("%s", stuff);
    }

    count_sort(LP32, i);
    count_sort(ILP32, i);
    count_sort(LLP64, i);
    count_sort(LP64, i);

    printf("%d %d\n", Bsum(LP32, i), Wsum(LP32, i));
    printf("%d %d\n", Bsum(ILP32, i), Wsum(ILP32, i));
    printf("%d %d\n", Bsum(LLP64, i), Wsum(LLP64, i));
    printf("%d %d", Bsum(LP64, i), Wsum(LP64, i));

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}