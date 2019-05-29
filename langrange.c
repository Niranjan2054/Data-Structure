#include<stdio.h>
int main(){
	float x[10], y[10],t,a,yp;
	int i,j,n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("Enter the value of x and f(x): \n");
	for(i=0;i<n;i++){
		scanf("%f%f",&x[i],&y[i]);
	}
	printf("\nEnter the value of x for which value of f(x) is required: ");
	scanf("%f",&a);
	for(i =0;i<n;i++){
		t =1;		
		for(j=0;j<n;j++){
			if(i!=j){
				t*=(a-x[j])/(x[i]-x[j]);
			}
		}
		yp += t * y[i];
	}
	printf("\nThe value of f(%.2f) is %f\n\n",a,yp);
	return 0;
}
