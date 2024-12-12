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
    struct node * prv=NULL;
    if(current->data==z){
        printf("\nNode is to be deleted");
    }
    while(current->data!=z && current!=NULL){
                        if(current->data<z){
                prv=current;
                current=current->right;
            }
            //going to left node
            else if(current->data>z){
                prv=current;
                current=current->left;
            }
            else if(current->data!=z){
                break;
            }
    }
    if(current==NULL){
        printf("/n%d not found",z);
    }
    //if deleting node has two children
    else if(current->left!=NULL && current->right!=NULL){
        
    }
    //if only have left child
    else if(current->left!=NULL && current->right==NULL){
        if(prv->data>z){
            prv->left=current->left;
        }
        else if(prv->data<z){
            prv->right=current->left;
        }

    }
    //if only have right sub tree
    else if(current->left==NULL && current->right!=NULL){
        if(prv->data>z){
            prv->left=current->right;
        }
        else if(prv->data<z){
            prv->right=current->right;
        }
        
    }
    //if no child
    else if(current->left==NULL && current->right==NULL){
        free(current);
        if(prv->data>z){
            prv->left=NULL;
        }
        else if(prv->data<z){
            prv->right=NULL;
        }
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
/*Deleting a node from a Binary Search Tree (BST) involves three main scenarios:

1. **Node with No Children (Leaf Node)**:
   - Simply remove the node from the tree.

2. **Node with One Child**:
   - Remove the node and replace it with its child.

3. **Node with Two Children**:
   - Find the node's in-order successor (the smallest node in its right subtree) or in-order predecessor (the largest node in its left subtree).
   - Replace the node's value with the in-order successor's (or predecessor's) value.
   - Delete the in-order successor (or predecessor) node, which will now be a simpler case (either a leaf node or a node with one child).

### Steps for Deleting a Node with Two Children:
1. **Find the Node**: Locate the node to be deleted.
2. **Find the In-Order Successor**: This is the smallest node in the right subtree.
3. **Replace the Node's Value**: Replace the value of the node to be deleted with the in-order successor's value.
4. **Delete the In-Order Successor**: Since the in-order successor is guaranteed to have at most one child, this step is simpler.

By following these steps, you can effectively delete a node from a BST while maintaining its properties. If you need further clarification or have any other questions, feel free to ask!*/