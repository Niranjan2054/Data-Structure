#include<stdio.h>
int main(){
    int n,i;
    float x[10],y[10],sumx=0,sumy=0,sumxy=0,sumx2=0,a,b,A,B;
    printf("Enter the number of data: ");
    scanf("%d",&n);
    printf("Enter the n pair of data:\n");
    for(i=0;i<n;i++){
        scanf("%f%f",&x[i],&y[i]);
        sumx = sumx + (1/x[i]);
        sumy = sumy + (1/y[i]);
        sumxy = sumxy + 1/(x[i]*y[i]);
        sumx2 = sumx2 + 1/(x[i]*x[i]);
    }
    B = (n*sumxy - sumx * sumy)/(n*sumx2 - sumx * sumx);
    A = (sumy - B * sumx)/n;
    a = 1/A;
    b = B*a;
    printf("The fitted Curve is : y = (%.2f * x)/(%.2f + x)",a,b);
    return 0;
}
