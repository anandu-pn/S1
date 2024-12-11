#include<stdio.h>
int display(int a[],int n1);
int merge(int a[], int b[],int n1,int n2);
int arrayin(int a[],int n1);
int main(){
    int n1,n2;
    printf("enter the size of the first array: ");
    scanf("%d",&n1);
    printf("enter the size of second array: ");
    scanf("%d",&n2);
    int a[n1];
    int b[n2];
    arrayin(a,n1);
    printf("\nfirst array is \n:");
    display(a,n1);
    printf("\nsecond array\n");
    arrayin(b,n2);
    printf("\n");
    display(b,n2);
    printf("\n\n merged array");
    merge(a,b,n1,n2);
    return 0;

}
int arrayin(int a[],int n1){
    int i;
    
    for(i=0;i<n1;i++){
        printf("enter the element %d:",i+1);
        scanf("%d",&a[i]);
    }
    return 0;

}
int merge(int a[], int b[],int n1,int n2){
    int n3,i;
    n3=n1+n2;
    int c[n3];
    for(i=0;i<n1;i++){
        c[i]=a[i];
        }
    for(i=0;i<n2;i++){
        c[n1+i]=b[i];
    }
    display(c,n3);
    return 0;
    
    }
int display(int a[],int n1){
    int i;
    printf("\n");
    for(i=0;i<n1;i++){
        printf("%d",a[i]);
        
        }
return 0;}