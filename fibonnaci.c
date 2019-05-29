//Fibonacci series using Recursion relation
#include<stdio.h>
#include<math.h>
float fibo(int n){
	return (0.447214 * pow((1+sqrt(5))/2,n) - (0.447214 * pow((1 - sqrt(5))/2,n)));
}
int main(){
	int n,i;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		printf("%.1f\t",fibo(i));
	}
	printf("\n");
	return 0;
}
	
