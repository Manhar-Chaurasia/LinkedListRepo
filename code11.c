//push, pop, top, display stack using array
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
int ar[MAX_SIZE];
int top=-1;
void Push(int x)
{
    if (top==MAX_SIZE-1)
    {
        printf("Stack overflow\n");
        return;
    }
    ar[++top]=x;
}
void Pop()
{
    if (top==-1)
    {
        printf("Stack underflow\n");
        return;
    }
    top--;
}
int Top()
{
    return ar[top];
}
void Display()
{
    printf("Stack:\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d  ",ar[i]);
    }
}
int main()
{
    Push(2);
    Push(3);
    Display();
}
