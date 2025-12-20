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

    List *list = calloc(N, sizeof(List));

    int ind;
    char val[8];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &ind, val);
        pushNode(&list[ind].current, val, ind);
    }

    for (int i = 0; i < N; i++)
    {
        if (list[i].current != NULL)
        {
            while (list[i].current != NULL)
            {
                printf("%d %s\n", list[i].current->num, list[i].current->data);
                list[i].current = list[i].current->next;
            }
        }
    }

    printList(list);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
