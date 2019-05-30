#include<stdio.h>
int main(){
	int x[20], y[20],sumx=0, sumy=0, sumxy=0, sumx2=0;
	int n,i;
	float a, b;
	printf("\nEnter the number of data: ");
	scanf("%d",&n);
	printf("Enter the data:\n");
	for(i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		sumx += x[i];
		sumy += y[i];
		sumxy += x[i]*y[i];
		sumx2 += x[i]*x[i];
	}
	//printf("sumx = %d\n sumy = %d\n sumxy = %d\n sum x2 = %d",sumx, sumy, sumxy, sumx2);
	b = (float)(n * sumxy - sumx * sumy)/(n * sumx2 - sumx * sumx);
	a = (float)(sumy - b * sumx)/n;
	printf("The linear equation is : %.2f + %.2f x\n",a,b);
	return 0;
}
