#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 8
#define sp 1000001

typedef struct
{
    int len;
    char (*data)[LEN];
}Array;

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    Array *list = malloc(sp * sizeof(Array));

    int ind;
    char val[LEN];

    for(int i = 0; i < N; i++){
        scanf("%d %s", &ind, val);
        if(list[ind].data == NULL){
            list[ind].len = 1;
            list[ind].data = malloc(sizeof(*list[ind].data));
            strcpy(list[ind].data[0], val);
        }
        else{
            char (*tmp)[LEN] = realloc(list[ind].data, (list[ind].len + 1) * sizeof(*list[ind].data));
                if (!tmp) {
                    free(list[ind].data);
                    return 1;
                }
            list[ind].data = tmp;
            strcpy(list[ind].data[list[ind].len], val);
            list[ind].len++;
        }
    }

    for(int i = 0; i < sp; i++){
        if(list[i].data != NULL){
            if(list[i].len > 1){
                for(int k = 0; k < list[i].len; k++)
                    printf("%d %s\n", i, list[i].data[k]);
            }
            else
                printf("%d %s\n", i, list[i].data[0]);
            free(list[i].data);
        }
    }
    free(list);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
