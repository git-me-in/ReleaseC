#include <stdio.h>

char reverse(char *s, int len){
    char t;
    int half;
    if((len - 1) % 2 == 0) half = (len - 1)/2; 
    else half = (len - 1)/2 + 1;
    for(int i = 0; i < half; i++){
        t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
    s[len] = '\0';
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        char st[101];
        scanf("%s", st);
        int i = 0;
        while (st[i] != '\0')
        {
            i++;
        }
        reverse(st, i);
        printf("%s\n", st);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}