#include <stdio.h>

typedef struct Label_s
{
    char name[16];
    int age;
} Label;

typedef struct NameStats_s
{
    int cntTotal;
    int cntLong;
} NameStats;

typedef struct AgeStats_s
{
    int cntTotal;
    int cntAdults;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
    oNames->cntTotal = cnt;
    oNames->cntLong = 0;

    oAges->cntTotal = cnt;
    oAges->cntAdults = 0;
    oAges->cntKids = 0;

    for (int i = 0; i < cnt; i++)
    {
        int n = 0;
        while (arr[i].name[n] != '\0')
        {
            n++;
        }
        if (n > 10)
        {
            oNames->cntLong++;
        }
        if (arr[i].age > 17)
        {
            oAges->cntAdults++;
        }
        if (arr[i].age < 14)
        {
            oAges->cntKids++;
        }
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    Label person[N];
    NameStats Names;
    AgeStats Ages;

    char leftovers[4];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", person[i].name);
        scanf("%d", &person[i].age);
        scanf("%s", leftovers);
    }
    calcStats(person, N, &Names, &Ages);
    printf("names: total = %d\n"
           "names: long = %d\n"
           "ages: total = %d\n"
           "ages: adult = %d\n"
           "ages: kid = %d",
           Names.cntTotal, Names.cntLong, Ages.cntTotal, Ages.cntAdults, Ages.cntKids);
}