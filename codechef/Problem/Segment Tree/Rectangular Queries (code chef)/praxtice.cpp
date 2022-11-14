#include<iostream>
#include<stdlib.h>
int main(){
    int i,n;
    printf("enter the number of intergers:");
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL){
        printf("memory is not available.");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("enter the numbers:");
        scanf("%d",ptr+i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d",*(ptr+i));
    }
    return 0;
}