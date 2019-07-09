#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main()
{
    int a,b,result;
    printf("Enter the two number: ");
    scanf("%d%d",&a,&b);
    result = gcd(a,b);
    printf("The Greatest Common Divisor is %d",result);
    return 0;
}
