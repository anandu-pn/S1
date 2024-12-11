#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * push(struct node * head){
    int z;
    struct node * temp=(struct node *) malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memmory allocation failed\n");
        exit(1);
    }
    printf("Enter data of node:");
    scanf("%d",&z);
    temp->data=z;
    temp->next=NULL;
    if(head==NULL){
        return temp;
        exit(0);
    }
    struct node * current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;
    return head;
}
struct node * pop(struct node * head){
    int i;
    if(head==NULL){
        printf("\nStack is empty nothing to remove\n");
        return NULL;
    }
    struct node * prv=NULL;
    struct node * current=head;
    while(current->next!=NULL){
        prv=current;
        current=current->next;
    }
    if(head->next==NULL){
        printf("%d is removed\n",head->data);
        free(head);
        return NULL;
    }
    else{
        printf("%d is removed\n",current->data);
        prv->next=NULL;
    }
    free(current);
    return head;
}
void peek(struct node * head){
    struct node * current =head;
    if(head==NULL){
        printf("Node is empty\n");
    }
    else{
        while(current->next!=NULL){
            current=current->next;
        }
        printf("the last element is %d\n",current->data);
    }

}
void dis(struct node * head){
    int i;
    struct node * current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
int main(){
    struct node * head=(struct node *) malloc(sizeof(struct node));
    head=NULL;
    int n,i,choice;
    printf("Enter the number of node to be created: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head=push(head);
        
    }
    dis(head);
    while(1){
        printf("\nEnter option 1-Display 2-PUSH 3-POP 4-peek 5-Exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                dis(head);
                break;
            case 2:
                head=push(head);
                break;
            case 3:
                head=pop(head);
                break;
            case 4:
                printf("You selected Peek operation");
                peek(head);
                break;
            case 5:
                printf("Program will be exited\n");
                return 0;
            default:
                printf("you Entered wrong choice\n");
                break;
        }
    }
}