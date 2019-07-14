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
    bubblesort(data,n);
    for(i=0;i<n;i++){
        printf("%d\t",data[i]);
    }
    return 0;
}
void bubblesort(int data[20],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(data[j]>data[j+1]){
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
}
