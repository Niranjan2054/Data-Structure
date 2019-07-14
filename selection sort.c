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
    selectionsort(data,n);
    for(i=0;i<n;i++){
        printf("%d\t",data[i]);
    }
    return 0;
}
void selectionsort(int data[20],int n){
    int i,j,small;
    for(i=0;i<n-1;i++){
        small = i;
        for(j=i+1;j<n;j++){
            if(data[small]>data[j])
                small = j;
        }
        j = data[small];
        data[small] = data[i];
        data[i] = j;
    }
}
