#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
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
            //goint to the right node
            if(current->data<z){
                prv=current;
                current=current->right;
            }
            //going to left node
            else if(current->data>z){
                prv=current;
                current=current->left;
            }
            //if already present
            else if(current->data==z){
                printf("\n%d is already present in BST!",z);
                printf("\n Enter the value of node:");
                scanf("%d",&z);
                temp->data=z;
                continue;
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
    int z;
    if(*root==NULL){
        printf("\ntree is empty");
        return;
    }
    printf("\n Enter the value of node to search:");
    scanf("%d",&z);
    while(current!=NULL && current->data!=z){
        if(current->data<z){
            current=current->right;
        }
        else if (current->data>z){
            current=current->left;
        }
    }
    if(current==NULL){
        printf("\n %d Node found not found",z);
    }
    //return pointer if node is found
    else{
        printf("\n %d found at ptr:%d",z,current);
    }
}
void Delete(struct node ** root){
    int z;
    struct node * current=*root;
    if(*root==NULL){
        printf("\nTree is empty!");
        return;
    }
    printf("\nEnter the values to be deleted: ");
    scanf("%d",&z);
    struct node * prv=NULL;
    while( current!=NULL && current->data!=z){
            //going to right node
            if(current->data<z){
                prv=current;
                current=current->right;
            }
            //going to left node
            else if(current->data>z){
                prv=current;
                current=current->left;
            }
    }
    if(current==NULL){
        printf("\n%d not found",z);
    }
    else{
        //if deleting node has two children
        if(current->left!=NULL && current->right!=NULL){
            //using inorder successor
            struct node * successor=(current->right);
            struct node * succePrv=current;
            while(successor->left!=NULL){
                succePrv=successor;
                successor=successor->left;
            }
            //assingning values of successor to be the previous node to deleted
            current->data=successor->data;
            //following if else condition is ai generated to check for root node del
            if (succePrv != current) { 
                succePrv->left = successor->right; 
                } 
            //in else condition succeprv is current that is root node is being deleted
            else { 
                succePrv->right = successor->right; 
                }
            free(successor);
        }
        //if only have left child
        else if(current->left!=NULL && current->right==NULL){
            //this if condition check if root node only have one left child
            if(prv==NULL){
                *root=current->left;
            }
            else if(prv->data>z){
                prv->left=current->left;
            }
            else if(prv->data<z){
                prv->right=current->left;
            }
            free(current);
        }
        //if only have right sub tree
        else if(current->left==NULL && current->right!=NULL){
            if(prv==NULL){
                *root=current->right;
            }
            else if(prv->data>z){
                prv->left=current->right;
            }
            else if(prv->data<z){
                prv->right=current->right;
            }
            free(current);
        }
        //if no child
        else if(current->left==NULL && current->right==NULL){
            //if only root left to delete
            if(prv==NULL){
                *root=NULL;
            }
            else if(prv->data>z){
                prv->left=NULL;
            }
            else if(prv->data<z){
                prv->right=NULL;
            }
            free(current);
        }
        printf("\n%d is successfully deleted",z);
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
    printf("\nPreOrder traversel: ");
    preOrder(Root);
    printf("\ninOrder traversel: ");
    inOrder(Root);
    printf("\nPostOrder traversel: ");
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
