// Insertion sort
#include <stdio.h>
#include <stdlib.h>
void Insertion_Sort(int A[], int n)
{
    int key, j;
    // loop for every next element
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // loop for each pass
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
void Print_arr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
}
int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Before insertion sort:\n");
    Print_arr(A, n);
    Insertion_Sort(A, n);
    printf("\nAfter insertion sort:\n");
    Print_arr(A, n);
    return 0;
}
