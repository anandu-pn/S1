#include<stdio.h>
#include<stdlib.h>
//more updated and better version that works
struct node{
    int data;
    struct node * next;
};
struct node* create(struct node *head){
    int z,i;
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory error\n");
        exit(1);
    }
    printf("Enter the data of node :");
    scanf("%d",&z);
    temp->data=z;
    temp->next=NULL;
    if (head == NULL) { 
        return temp; } 
    struct node* current = head; 
    while (current->next != NULL) { 
        current = current->next; 
        } 
    current->next = temp;
    return head;
}
struct node* beg(struct node *head){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory error\n");
        exit(1);
        }
    printf("Enter the data of node :");
    scanf("%d",&temp->data);
    temp->next=head;
    return temp;

}
void  dis(struct node * head){
    struct node * temp = head;
    while(temp !=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}
//this del give me pain
struct node* del(struct node * head){
    int z,count;
    printf("Enter the value to be deleted:");
    scanf("%d",&z);
    struct node * prev = NULL;
    struct node * current = head;
    //do rember this part were dat should not equal to z
    while(current!=NULL && current->data!=z){
        prev = current;
        current = current->next;
    }
    if(current==NULL){
        printf("Element %d not found *",z);
    }
    else if(prev==NULL){//do not use else if , here it removes head node
        head = current->next;
        printf("Removed %d \n",z);
    }
    else{
        prev->next = current->next;
        printf("Removed %d \n",z);
    }
    free(current);
    return head;
}
int main(){
    struct node * head=NULL;
    int n,i,z,choice;
    printf("Enter the number of node to be created:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head=create(head);
    }
    dis(head);
    printf("\n");
    
    while(1){
        printf("\n");
        printf("Enter the choice 1-insert_end 2-Delete 3-display 4-insertion begining \n 5-Exit:  ");
        scanf("%d",&choice);
        switch(choice) { 
        case 1: 
            printf("You selected option 1\n");
            head=create(head);
            dis(head);
            break; 
        case 2: 
            printf("You selected option 2\n\n"); 
            head=del(head);
            dis(head);
            break; 
        case 3: 
            printf("You selected option 3\n\n"); 
            dis(head);
            break; 
        case 4: 
            printf("You selected option 4\n\n"); 
            head=beg(head);
            dis(head);
            break;
        case 5:
            printf("You selected option 5 to exit\n\n");
            return 0;
        default: 
            printf("Invalid choice\n\n");
            break; 
            }
            }

}


