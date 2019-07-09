#include <stdio.h>
#include <stdlib.h>
int fib(int a){
    if(a==1 || a ==2){
        return 1;
    }else{
        return (fib(a-1) + fib(a-2));
    }
}
int main()
{
    int a,result;
    printf("Enter a number: ");
    scanf("%d",&a);
    result = fib(a);
    printf("The %d th terms  is %d",a,result);
    return 0;
}
