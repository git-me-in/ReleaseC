#include <stdio.h>
#define not 16

void swap(char *ch1, char *ch2)
{
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

union Onion
{
    int N;
    char a[4];
};

void readBE()
{
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    char s[3];

    union Onion box;
    int le = 0, be = 0;
    _Bool swapped = 0;
    // N = countN(fin, &le, &be, N);

    fread(box.a, sizeof(char), 4, fin);
    if (box.N > 10000)
    {
        swapped = 1;
        swap(&(box.a[0]), &(box.a[3]));
        swap(&(box.a[1]), &(box.a[2]));
    }
    // printf("here - %d", box.N);

    int sum = 0;

    union Onion t;
    for (int i = 0; i < box.N; i++)
    {
        fread(t.a, sizeof(char), 4, fin);
        if (swapped)
        {
            swap(&(t.a[0]), &(t.a[3]));
            swap(&(t.a[1]), &(t.a[2]));
            sum = sum + t.N;
        }
        else
        {
            sum = sum + t.N;
        }
    }

    if (swapped)
    {
        unsigned char bytes[4];
        bytes[0] = (sum >> 24) & 0xFF;
        bytes[1] = (sum >> 16) & 0xFF;
        bytes[2] = (sum >> 8) & 0xFF;
        bytes[3] = sum & 0xFF;
        fwrite(bytes, sizeof(unsigned char), 4, fout);
    }
    else
    {
        fwrite(&sum, sizeof(int), 1, fout);
    }

    // fwrite(ptr, sizeof(int), 1, fout);
    // printf("%d", );
}