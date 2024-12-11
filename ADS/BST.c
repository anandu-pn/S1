#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
//bug 
//when same element is entered progran stops fix it
void createNode(struct node ** root){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    struct node * current= *root;
    struct node * prv=NULL;
    int z;
    printf("\n Enter the value of node:");
    scanf("%d",&z);
    temp->data=z;
    temp->left=NULL;
    temp->right=NULL;
    if(*root==NULL){
        *root=temp;
    }
    else{
        //to find parent node of that node
        while(current!=NULL){
            if(current->data<z){
                prv=current;
                current=current->right;
            }
            else if(current->data>z){
                prv=current;
                current=current->left;
            }
        }
        //to create node to the right of parent node
        if(prv->data<z){
            prv->right=temp;
        }
        // to create node to the left of parent node
        else if(prv->data>z){
            prv->left=temp;
        }
    }
}

void search(struct node ** root){
    struct node * current = *root;
    int i,z;
    printf("\n Enter the value of node to search:");
    scanf("%d",&z);
    while(current->data!=z && current!=NULL){
        if(current->data==z){
            printf("\n Node found at root ptr:%d",current);
        }
        else{
            if(current->data<z){
                current=current->right;
            }
            else if (current->data>z){
                current=current->left;
            }
        }
        
    }
    if(current==NULL){
        printf("\n Node found not found");
    }
    //return pointer if node is found
    else if(current!=NULL){
        printf("\n Node found at ptr:%d",current);
    }
}
void Delete(struct node ** root){
    int z;
    struct node * current=*root;
    printf("Enter the values to be deleted");
    scanf("%d",&z);
    if(current->data==z){
        printf("\nNode is to be deleted");
    }

}
void preOrder(struct node * root){
    if (root==NULL){
        return;
    }
    printf("%d->",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct node * root){
    if (root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ->",root->data);
    inOrder(root->right);
}
void postOrder(struct node * root){
    if (root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ->",root->data);
}
void display(struct node * root){
    if(root==NULL){
        printf("\nTree is empty");
    }
    struct node * Root=root;
    printf("\nPreOrder traversel");
    preOrder(Root);
    printf("\ninOrder traversel");
    inOrder(Root);
    printf("\nPostOrder traversel");
    postOrder(Root);
}

int main(){
    struct node * root=NULL;
    int i,n,choice;
    printf("Enter number of node in tree:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        createNode(&root);
    }
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n8.Exit\noption:");
        scanf("%d",&choice);
        switch(choice){
            case(1):
                createNode(&root);
                break;
            case(2):
                Delete(&root);
                break;
            case(3):
                display(root);
                break;
            case(4):
                search(&root);
                break;
            case(5):
                //traverse(&root);
                break;
            case(6):
                //min(&root);
                break;
            case(7):
                //max(&root);
                break;
            case(8):
                printf("\nProgram existed");
                return 0;
                break;
            default:
                printf("\n Invalid option");
                break;
        }
    }
}