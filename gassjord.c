#include<stdio.h>
int main(){
	float matrix[10][11];
	float x[10],sum;
	int n,i,j,k;
	float ratio;
	printf("\n\tEnter the no. of unknown variable: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\n\tEnter the coefficient of the equation: \n");
		for(j=0;j<n+1;j++){
			scanf("%f",&matrix[i][j]);
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(k==i){
				ratio = matrix[k][k];
				for(j=k;j<n+1;j++){
					matrix[i][j] = matrix[i][j]/ratio;
				}
			}else{
				ratio = matrix[i][k]/matrix[k][k];
				for(j=k;j<n+1;j++){
					matrix[i][j] = matrix[i][j] - ratio * matrix[k][j];
				}
			}
		}
	}	
	for(i=0;i<n;i++){
		printf("%c = %f\n",97+i,matrix[i][n]);
	}
	return 0;
}
