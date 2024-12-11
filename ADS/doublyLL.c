#include<stdio.h>
#include<stdlib.h>
//to build a doubly link list
//here used pointer to pointer method in function
struct node{
    int data;
    struct node *prv;
    struct node *next;
};
void createbeg(struct node ** head){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("memory not allocated");
    }
    printf("Enter the data of the node:");
    scanf("%d",&temp->data);
    temp->prv=NULL;
    temp->next=*head;
    if(*head!=NULL){
    (*head)->prv=temp;
    }
    *head=temp;
}
//this function is quite problamatic since it was not written by by me but it works
void createAny(struct node ** head,struct node ** prv){
    int p,i=1;
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memmory allocation failed");
        return;
    }
    printf("enter the position of element to be added:");
    scanf("%d",&p);
    printf("\nenter the element to be added:");
    scanf("%d",&temp->data);
    struct node * current=*head;
    while (current != NULL && i < p - 1) { 
        current = current->next; 
        i++; }
    if(p==1){
        createbeg(head);
        return;
    }
    else if(current==NULL || p<1){
        printf("\n invalid position");
        free(temp);
        return;
    }
    temp->next = current->next; 
    temp->prv = current; 
    if (current->next != NULL) { 
        current->next->prv = temp; } 
    current->next = temp; 
    if (temp->next == NULL) { 
        *prv = temp; } 

    
}
void creatend(struct node ** head,struct node ** prv){
    struct node * temp=(struct node *) malloc(sizeof(struct node));
    int z;
    if (temp==NULL){
        printf("memmory allocation failed");
    }
    printf("\n Enter the data to be inserted:");
    scanf("%d",&z);
    temp->data=z;
    temp->next=NULL;
    if(*head==NULL){
        temp->prv=NULL;
        *head=temp;
    }
    else{
        (*prv)->next=temp;
        temp->prv=*prv;
    }
    *prv=temp;
}
void  dis(struct node * head){
    struct node * temp = head;
    printf("The list is :");
    while(temp !=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}
void delbeg(struct node ** head){
    struct node * temp=*head;
    if(temp==NULL){
        printf("\n list is empty\n");
        return;
    }
    if(temp->next!=NULL){
        (temp->next)->prv=NULL;
    }
    *head=(temp)->next;
    printf("\n%d is deleted\n",temp->data);
    free(temp);
}
void delend(struct node ** head){
    if(*head==NULL){
        printf("\n list is empty");
        return;
    }
    struct node * temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->prv!=NULL){
        (temp->prv)->next=NULL;
    }
    else{
        *head=NULL;
    }
    printf("\n%d is removed from list\n",temp->data);
    free(temp);
}
void delAny(struct node ** head){
    struct node * current=*head;
    if(current==NULL){
        printf("\nList is empty");
        return;
    }
    printf("Enter the position of elemnt to deleted:");
    int pos,i=1;
    scanf("%d",&pos);
    while (current != NULL && i < pos) { 
        current = current->next; 
        i++; }
    if(pos==1){
        delbeg(head);
        return;
    }
    else if(current==NULL || pos<1){
        printf("\n invalid position");
        return;
    }
    else{
        if(current->prv!=NULL){
            (current->prv)->next=(current->next);
        }
        if(current->next!=NULL){
            (current->next)->prv=(current->prv);
            }
        printf("\n%d is removed from list\n",current->data);
        free(current);
        }
}
void search(struct node * head){
    struct node * temp=head;
    printf("\nEnter the element to be found:");
    int z,i=1;
    scanf("%d",&z);
    if(temp==NULL){
        printf("\nthe list empty nothin to search\n");
    }
    while(temp!=NULL && temp->data!=z){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("\nThe element not found\n");
        return;
    }
    else{
        printf("\nThe element %d is found at %d\n",z,i);
    }
}
int main(){
    struct node * head=NULL;
    struct node * prv=NULL;
    struct node * h[2];
    int i,n,choice;
    printf("enter the number of node to be created:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        creatend(&head,&prv);
    }
    dis(head);
        while(1){
        printf("\n");
        printf("Enter the choice \n1-insert_end 2-Inser_beg 3-display 4-insert at any POSg \n 5-delete_end 6-delete_beg 7-delete_at any pos\n8-search 9-Exit:  ");
        scanf("%d",&choice);
        switch(choice) { 
        case 1: 
            printf("You selected option 1\n");
            creatend(&head,&prv);
            dis(head);
            break; 
        case 2: 
            printf("You selected option 2 insert at beg\n\n"); 
            createbeg(&head);
            dis(head);
            break; 
        case 3: 
            printf("You selected option 3\n\n"); 
            dis(head);
            break; 
        case 4: 
            printf("You selected option 4\n\n"); 
            createAny(&head,&prv);
            dis(head);
            break;
        case 5: 
            printf("You selected option 5 to delete end\n\n"); 
            delend(&head);
            dis(head);
            break;
        case 6: 
            printf("You selected option 6 delete at begining\n\n"); 
            delbeg(&head);
            dis(head);
            break;
        case 7: 
            printf("You selected option 7 delete at any position\n\n"); 
            delAny(&head);
            dis(head);
            break;
        case 8:
            printf("You selected option 8 to search\n\n");
            search(head);
            break;
        case 9:
            printf("You selected option 9 to exit\n\n");
            return 0;
        default: 
            printf("Invalid choice\n\n");
            break; 
            }
            }
}