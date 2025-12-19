#include <stdio.h>
#include <stdlib.h>

typedef struct Stalin{
    int data;
    struct Stalin *next;
}gensec;

gensec *circle(int n){
    gensec *head = NULL;
    gensec *prev = NULL;
    for (int i = 1; i <= n; i++)
    {
        gensec *node = malloc(sizeof(gensec));
        node->data = i;
        node->next = NULL;

        if(head == NULL)
            head = node;
        else
            prev->next = node;
        prev = node;
    }
    
    prev->next = head;
    return head;
}

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);

    // int ans = 0;
    // for(int i = 1; i < n + 1; i++)
    //     ans = (ans + k) % i;

    gensec *head = circle(n);

    gensec *cur = head;
    gensec *prev = head;

    while (prev->next != head)
        prev = prev->next;
    
    while (cur->next != cur)
    {
        for(int i = 1; i < k; i++){
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;
        free(cur);

        cur = prev->next;
    }

    int ans = cur->data;
    free(cur);
    printf("%d", ans);

    return 0;
}

