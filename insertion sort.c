#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[20];
    int i,j,n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
    }
    insertionsort(data,n);
    for(i=0;i<n;i++){
        printf("%d\t",data[i]);
    }
    return 0;
}
void insertionsort(int data[20],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        j = i-1;
        temp = data[i];
        while(j>=0 && data[j]>temp){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp;
    }
}
