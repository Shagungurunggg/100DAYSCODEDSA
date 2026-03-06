Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff, exp;
    struct node *next;
};

int main(){
    int n,i;
    struct node *head=NULL,*temp=NULL,*newnode;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d %d",&newnode->coeff,&newnode->exp);
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp=head;
    while(temp){
        if(temp->exp==0)
            printf("%d",temp->coeff);
        else if(temp->exp==1)
            printf("%dx",temp->coeff);
        else
            printf("%dx^%d",temp->coeff,temp->exp);

        if(temp->next)
            printf(" + ");

        temp=temp->next;
    }

    return 0;
}
 

