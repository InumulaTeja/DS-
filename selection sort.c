#include<stdio.h>

void selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int si=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[si])
            {
                si=j;
            }
        }
        int temp=a[i];
        a[i]=a[si];
        a[si]=temp;
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
    int n;
    printf("enter the total number of elements in array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
    printf("sorted array\n");
    print(a,n);
}
