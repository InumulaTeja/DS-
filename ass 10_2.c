#include <stdio.h>

 int merge(int a[],int l,int mid,int h,int n)
{
    int i=l,j=mid+1,k=l;
    int merarr[n];
    int count=0;
    while(i<=mid && j<=h)
    {
        if(a[i]<=a[j])
        {
            merarr[k++]=a[i++];
        }
        else
        {
            merarr[k++]=a[j++];
            count=count+(mid-i+1);
        }
    }
    while(i<=mid)
    {
        merarr[k++]=a[i++];
    }
    while(j<=h)
    {
        merarr[k++]=a[j++];
    }
    for(int s=l;s<=h;s++)
    {
        a[s]=merarr[s];
    }
    return count;
}
int  mergesort(int a[],int l,int h,int n)
{
    if(l>=h)
    {
        return 0;
    }
    int mid=(l+h)/2;
    int count=0;
    count+=mergesort(a,l,mid,n);
    count+=mergesort(a,mid+1,h,n);
    count+=merge(a,l,mid,h,n);
    return count;
}
int main() {
    int n;
    printf("enter the value of n:");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l=0,h=n-1;
    int count=mergesort(a,l,h,n);
    printf("%d",count);
}
