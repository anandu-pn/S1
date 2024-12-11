#include<stdio.h>
#include<stdlib.h> 
//here the variables n,n1,n2 declared globaly because it is to access
//isPresent function by declaring this way
int n,n1,n2;
//a function to verify the property of the set
int isPresent(int a[],int n,int z){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==z){
            return 1;
        } 
    }
    return 0;    
}
void createSet(int a[], int U[],int num){
    int z,i;
    printf("\nreading element of sets \n");
    for(i=0;i<num;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d",&z);
        if(!(isPresent(a,i,z)) && (U==NULL || isPresent(U,n,z))){
            a[i]=z;
        }
        
        else{
            printf("invalid entry!\n");
            i--;
        }
        
    }
}
void dis(int a[],int num){
    int i;
    for(i=0;i<num;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int i;
    printf("Enter the sze of universel set:");
    scanf("%d",&n);
    int U[n];
    createSet(U,NULL,n);
    while(1){
        printf("\nEnter the size of set 1:");
        scanf("%d",&n1);
        printf("\nEnter the sze of set 2:");
        scanf("%d",&n2);
        if(n1 > n || n2>n){
            printf("\nSize of sets should not be larger than universel set");
        }
        else{
             break;
        }
    }
    int s1[n1];
    createSet(s1,U,n1);
    int s2[n2];
    createSet(s2,U,n2);
    printf("\nUniversel set is:");
    dis(U,n);
    printf("\nSet 1 is:");
    dis(s1,n1);
    printf("\nSet 2 is:");
    dis(s2,n2);
    //representing sets s1 and s2 using bit string method
    int b1[n],b2[n],j;
    for(i=0;i<n;i++){
        b1[i]=0;
        b2[i]=0;
        for(j=0;j<n1;j++){
           if(U[i]==s1[j]){
                b1[i]=1;
                break;
            }
        }
        for(j=0;j<n2;j++){
            if(U[i]==s2[j]){
                b2[i]=1;
                break;
            }
        }
    }
    //performing operations on set like union intersection and difference
    int Union[n],Intersection[n],Difference[n];
    for(i=0;i<n;i++){
        Union[i]=0;
        if(b1[i]==1 || b2[i]==1){
            Union[i]=1;
        }
    }
    for(i=0;i<n;i++){
        Intersection[i]=0;
        if(b1[i]==1 && b2[i]==1){
            Intersection[i]=1;
        }
    }
    for(i=0;i<n;i++){
        Difference[i]=0;
        if(b1[i]==1 && Intersection[i]!=1){
            Difference[i]=1;
        }
    }
    printf("\nSet 1 using bit string:");
    dis(b1,n);
    printf("\nSet 2 using bit string:");
    dis(b2,n);
    //printing union and intersection
    printf("\nUnion of two Set 1 and 2 :");
    dis(Union,n);
    printf("\nIntersection of two Set 1 and 2 :");
    dis(Intersection,n);
    printf("\nDiffernce of two sets :");
    dis(Difference,n);
    return 0;
}