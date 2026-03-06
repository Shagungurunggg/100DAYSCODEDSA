Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int n,i,x,k;
    struct node *head=NULL,*temp=NULL,*newnode,*prev,*last;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    scanf("%d",&k);

    int len=0;
    temp=head;
    while(temp){
        len++;
        last=temp;
        temp=temp->next;
    }

    k=k%len;
    if(k==0){
        temp=head;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return 0;
    }

    int move=len-k;
    temp=head;

    for(i=1;i<move;i++)
        temp=temp->next;

    head=temp->next;
    temp->next=NULL;
    last->next=head;

    temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
