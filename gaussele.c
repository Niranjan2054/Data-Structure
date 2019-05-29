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
			printf("\tEnter the coefficient of %c: ",97+j);
			scanf("%f",&matrix[i][j]);
		}
	}
	for(k=0;k<n-1;k++){
		for(i=k+1;i<n;i++){
			ratio = matrix[i][k]/matrix[k][k];
			for(j=k;j<n+1;j++){
				matrix[i][j] = matrix[i][j] - ratio * matrix[k][j];
			}
		}
	}	
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			printf("%f\t",matrix[i][j]);
		}
		printf("\n");
	}
	//backward elemination
	x[n-1] = matrix[n-1][n]/matrix[n-1][n-1];
	for(i=n-2;i>=0;i--){
		sum =0;
		for(j=i+1;j<n;j++){
			sum+= x[j]*matrix[i][j];
		}
		x[i] = (matrix[i][n] - sum)/matrix[i][i];
	}
	for(i=0;i<n;i++){
		printf("%c = %f\n",97+i,x[i]);
	}
	return 0;
}
