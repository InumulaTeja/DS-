#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* createnode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node* linkedlist()
{
    int n,data;
    struct node* head=NULL,*temp=NULL,*newnode;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the data of node %d:",i+1);
        scanf("%d",&data);
        newnode=createnode(data);
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }
    return head;
}
struct node* bubblesort(struct node*head)
{
    int t;
    struct node*end=NULL,*ptr;
    while(end!=head->next)
    {
        ptr=head;
        while(ptr->next!=end)
        {
            if(ptr->data > ptr->next->data)
            {
            int temp=ptr->data;
            ptr->data=ptr->next->data;
            ptr->next->data=temp;
            }
            ptr=ptr->next;
        }
        end=ptr;
    }
}
void print(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main()
{
    struct node* head=NULL;
    head=linkedlist();
    printf("linked list before sorting\n");
    print(head);
    printf("\nlinked list after sorting\n");
    bubblesort(head);
    print(head);
}
