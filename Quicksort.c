#include<stdio.h>


int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i=i+1;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    i++;
    int s=a[i];
    a[i]=a[high];
    a[high]=s;
    return i;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pindex=partition(a,low,high);
        quicksort(a,low,pindex-1);
        quicksort(a,pindex+1,high);
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
    printf("enter the value of n:");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int low=0,high=n-1;
    quicksort(a,low,high);
    print(a,n);
}
