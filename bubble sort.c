#include<stdio.h>

void bubblesort(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void print(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{
    int size;
    printf("enter the array size:");
    scanf("%d",&size);
    int a[size];
    printf("enter the array elements\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    bubblesort(a,size);
    print(a,size);
}
