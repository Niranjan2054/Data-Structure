#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
	int i, x[10],y[10],n;
	float sumx=0, sumy=0, sumxy=0, sumx2=0;
	float a,b;
	clrscr();
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("Enter the value of x and it's corresponding y: \n");
	for(i=0;i<n;i++){
	       scanf("%d%d",&x[i],&y[i]);
	       sumx+= x[i];
	       sumy+= log(y[i]);
	       sumxy+=x[i]*log(y[i]);
	       sumx2+=x[i]*x[i];
	}
//	printf("%f %f %f %f\n",sumx, sumy, sumxy, sumx2);
	b = (float)(n*sumxy - sumx * sumy)/(n * sumx2 - sumx * sumx);
  //	printf("b = %f",b);
	a = exp((float)(sumy - b * sumx)/n);
    //	printf("a = %f",a);
	b = exp(b);
	printf("The Fitted Curve is : %.2f*%.2f^x",a,b);
	getch();
}