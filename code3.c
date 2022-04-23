// delete a node at nth position
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head; // global
void Insert(int data)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = head;
    head = temp1;
}
void Print()
{
    struct Node *temp = head;
    printf("List is\n");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int n) // n is position
{
    struct Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    if (temp1->next == NULL || temp1 == NULL)
    {
        printf("Invalid position");
    }

    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
int main()
{
    head = NULL; // empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    int n;
    printf("Enter a position\n");
    scanf("%d", &n);
    Delete(n);
    Print();
}