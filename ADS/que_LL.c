#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * enq(struct node * head){
    int z;
    struct node * temp=(struct node *) malloc(sizeof(struct node));
    struct node * current=head;
    printf("Enter the data of the node:");
    scanf("%d",&z);
    temp->data=z;
    temp->next=NULL;
    if (head==NULL){
        temp->next=NULL;
        return temp;
    }
    else{
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
        return head;
    }
}
struct node * dq(struct node * head){
    if(head==NULL){
        printf("Que is empty nothing to remove\n");
        return NULL;
    }
    else{
        struct node * temp;
        printf("%d is removed \n",head->data);
        temp=head->next;
        free(head);
        return temp;
    }

}
void dis(struct node * head){
    struct node * current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");   
}
int main(){
    int i,n,choice;
    struct node * head=NULL;
    struct node * rear=NULL;
    printf("Enter the number of elemnts in the stack:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head=enq(head);
    }
   
    while(1){
         printf("Enter the choice 1-Enque 2-Deque 3-Display 4-exit:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("You selected Enque operations\n");
                head=enq(head);
                
                break;
            case 2:
                printf("You selected Deque operations\n");
                head=dq(head);
                break;
            case 3:
                printf("You selected display operations\n");
                dis(head);
                break;
            case 4:
                printf("You selected exit\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}