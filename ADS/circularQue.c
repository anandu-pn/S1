#include<stdio.h>
#include<stdio.h>
#define max 10
int stack[max],rear=-1,front=-1;
int isfull(){
    if(front==(rear+1)%max){
        printf("\nstack isfull");
        return 1;
    }
    return 0;
}
int isempty(){
    if(front==-1 || front==rear+1){
        printf("stack is empty");
        return 1;
    }
    return 0;
}
void enque(int n){
    if(isempty()){
        front=rear=0;
        stack[rear]=n;
        return;
    }
    if(isfull()){
        return;
    }
    rear++;
    stack[rear%max]=n;
}
void deque(){
    if(isempty()){
        front=rear=-1;
        return;
    }
    if(front==rear){
        front=rear=-1;
    }
    int element=stack[front];
    front=(front+1)%max;
    printf("%d removed\n",element);
}
void dis(){
    printf("\n");
    int i=front;;
    do{
        printf("%d",stack[i]);
        i=(i+1)%max;
    }while(i!=rear+1);
}
int main(){
    int i,choice;
    while(1){
        printf("\nEnter the choice: 1-enque 2-deque 3-isfull 4-isempty 5-display 6-exit:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("\nenter the number:");
                scanf("%d",&i);
                printf("\n selected enque operation:");
                enque(i);
                break;
            case 2:
                /*printf("\nenter the number");
                scanf("%d",&i);*/
                printf("\n selected deque operation");
                deque();
                break;
            case 3:
                printf("\n selected isfull operation");
                isfull();
                break;
            case 4:
                printf("\n selected isempty operation");
                isempty(i);
                break;
            case 5:
                printf("\n selected display operation");
                dis();
                break;
            case 6:
                printf("\nyou seleceted exit");
                return 0;
                break;
            default:
                break;
        }
    }
}