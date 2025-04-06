#include<stdio.h>

void countingsort(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    int count[max+1];
    for(int i=0;i<max+1;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(int i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }
    int new[n];
    for(int i=n-1;i>=0;i--)
    {
        new[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=new[i];
    }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{
    int arr[]={1,3,2,3,4,1,6,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("array before sorting:");
    print(arr,n);
    countingsort(arr,n);
    printf("\narray after sorting:");
    print(arr,n);
}
