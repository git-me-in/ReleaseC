#include <stdio.h>

int softError(int val, int size)
{
    if (val > 0x10FFFF)
        return 0;
    if (val >= 0xD800 && val <= 0xDFFF)
        return 0;

    // Overlong encoding
    if (size == 1 && val > 0x7F)
        return 0;
    ;
    if (size == 2 && (val < 0x80 || val > 0x7FF))
        return 0;
    if (size == 3 && (val < 0x800 || val > 0xFFFF))
        return 0;
    if (size == 4 && (val < 0x10000 || val > 0x10FFFF))
        return 0;

    return 1;
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    int b, size;
    b = fgetc(fin);
    while (b != EOF)
    {
        int val;
        if ((b & 0b10000000) == 0)
        {
            // symbol takes 1 byte
            size = 1;
            if (softError(b, size) == 0)
            {
                val = 0xFFFD;
                fwrite(&val, sizeof(int), 1, fout);
            }
            else
                fwrite(&b, sizeof(int), 1, fout);
        }
        else if ((b & 0b11100000) == 0b11000000)
        {
            // symbol takes 2 bytes
            size = 2;

            val = (b & 0b00011111) << 6;

            b = fgetc(fin);
            if ((b & 0b11000000) != 0b10000000)
                break;
            val |= (b & 0b00111111);

            if (softError(val, size) == 0)
            {
                val = 0xFFFD;
                fwrite(&val, sizeof(int), 1, fout);
            }
            else
                fwrite(&val, sizeof(int), 1, fout);
        }
        else if ((b & 0b11110000) == 0b11100000)
        {
            // symbol takes 3 bytes
            size = 3;

            val = (b & 0b00001111) << 12;

            b = fgetc(fin);
            if ((b & 0b11000000) != 0b10000000)
                break;
            val |= (b & 0b00111111) << 6;

            b = fgetc(fin);
            if ((b & 0b11000000) != 0b10000000)
                break;
            val |= (b & 0b00111111);

            if (softError(val, size) == 0)
            {
                val = 0xFFFD;
                fwrite(&val, sizeof(int), 1, fout);
            }
            else
                fwrite(&val, sizeof(int), 1, fout);
        }
        else if ((b & 0b11111000) == 0b11110000)
        {
            // symbol takes  4 bytes
            size = 4;

            val = (b & 0b00000111) << 18;

            b = fgetc(fin);
            if ((b & 0b11000000) != 0b10000000)
                break;
            val |= (b & 0b00111111) << 12;

            b = fgetc(fin);
            if ((b & 0b11000000) != 0b10000000)
                break;
            val |= (b & 0b00111111) << 6;

            b = fgetc(fin);
            if ((b & 0b11000000) != 0b10000000)
                break;
            val |= (b & 0b00111111);

            if (softError(val, size) == 0)
            {
                val = 0xFFFD;
                fwrite(&val, sizeof(int), 1, fout);
            }
            else
                fwrite(&val, sizeof(int), 1, fout);
        }
        else
        {
            // harsh mistake
            break;
        }
        b = fgetc(fin);
    }
    return 0;
}
