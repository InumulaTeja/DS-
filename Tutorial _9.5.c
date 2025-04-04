//Given a sorted array of distinct elements arr [] of size n that is rotated at some unknown 

//point, the task is to find the minimum element in it.
#include <stdio.h>

int findmin(int a[], int n) {
    int i = 0, j = n - 1;

    while (i < n - 1 && a[i] < a[i + 1]) 
    {
        i++;
    }

    while (j > 0 && a[j] > a[j - 1])
    {
        j--;
    }

    if (i < n - 1 && a[i] > a[i + 1])
    {
        return a[i + 1];
    } 
    else if (j > 0 && a[j] < a[j - 1]) 
    {
        return a[j];
    }
    return a[0];
}

int main() 
{
    int ar[] = {3,4,5,0,2};
    int n = sizeof(ar) / sizeof(ar[0]);

    int m = findmin(ar, n);
    printf("Minimum element: %d\n", m);

    return 0;
}
