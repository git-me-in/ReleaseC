#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 8

typedef struct Node
{
    int num;
    char *data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *current;
    struct List *next;
} List;

Node *createNode(char *data, int num)
{
    Node *node = malloc(sizeof(Node));
    node->data = malloc(LEN);
    strcpy(node->data, data);
    node->num = num;
    node->next = NULL;
    return node;
}

List *createList()
{
    List *list = malloc(sizeof(List));
    list->current = NULL;
    list->next = NULL;
    return list;
}

void pushNode(Node **head, char *data, int num)
{
    Node *node = createNode(data, num);

    if (*head == NULL)
    {
        *head = node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
}

void pushList(List **head)
{
    List *list = createList();

    if (*head == NULL)
    {
        *head = list;
        return;
    }

    List *temp = *head;
    while (temp->next != 0)
        temp = temp->next;

    temp->next = list;
}

void printList(List *head)
{
    while (head != NULL)
    {
        Node *temp = head->current;
        while (temp != NULL)
        {
            printf("%d %s\n", temp->num, temp->data);
            temp = temp->next;
        }
        head = head->next;
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);
    Node *arr = malloc(sizeof(N));

    int ind;
    char val[LEN];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &ind, val);
        arr[i].num = ind;
        arr[i].data = malloc(LEN);
        strcpy(arr[i].data, val);
    }

    List *list = NULL;
    for (int i = 0; i < N; i++)
    {
        pushList(&list);
    }

    List *curList = list;
    int taken = 0, k = 1;
    while (taken < N)
    {
        int old = taken;
        for (int i = 0; i < N; i++)
        {
            if (arr[i].num == k)
            {
                pushNode(&curList->current, arr[i].data, arr[i].num);
                taken++;
            }
        }
        k++;
        if (old < taken)
            curList = curList->next;
    }

    printList(list);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
3 qwerty
3 string
6 good
1 a
3 ab
2 hello
5 world
*/