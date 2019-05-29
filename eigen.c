#include<stdio.h>
#include<math.h>
void matrixMultiplication(float sq[10][10], float col1[10][1], float col2[10][1],int size){
	int i,j,k,sum;
	for(i=0;i<size;i++){		
		col2[i][0] = 0;
		for(k=0;k<3;k++){
			col2[i][0] += sq[i][k] * col1[k][0];
		}
	}
}
void display(float a[10][1],int row){
	int i,j;
	printf("\n");	
	for(i=0;i<row;i++){
		for(j=0;j<1;j++){
			printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}
}
float normalize(float old_eigen[10][1], float new_eigen[10][1], int size){
	float max_value;
	int i;
	max_value = old_eigen[0][0];
	for(i=1;i<size;i++){
		if(max_value<old_eigen[i][0]){
			max_value = old_eigen[i][0];
		}
	}
	for(i=0;i<size;i++){
		new_eigen[i][0] = old_eigen[i][0]/max_value;
	}
	return max_value;
}
int main(){
	float matrix[10][10], old_eigen[10][1], new_eigen[10][1];
	int i,j,k,n;
	float error_limit, o_eigen, n_eigen;
	printf("Enter the size of n: and error limit: and maximum iteration\n");
	scanf("%d%f%d",&n,&error_limit,&k);	
	printf("Enter the element of n*n matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%f",&matrix[i][j]);
		}
	}
	printf("Enter the initial guess of eigen vector: ");
	for(i=0;i<n;i++){
		scanf("%f",&old_eigen[i][0]);
	}
	
	matrixMultiplication(matrix, old_eigen, new_eigen, n);
	o_eigen = normalize(new_eigen,old_eigen,n);
	i = 1;
	do{
		printf("Iteration: %d\n",i);
		printf("Eigen value: %f",o_eigen);
		display(old_eigen,n);
		matrixMultiplication(matrix, old_eigen, new_eigen, n);
		n_eigen = normalize(new_eigen,old_eigen,n);
		if(fabs(n_eigen-o_eigen)<error_limit){
			printf("Answer:\n");
			printf("Eigen value: %f",o_eigen);
			display(old_eigen,n);
			break;
		}
		o_eigen = n_eigen;
		i++;
	}while(i<=k);
	if(i>k){
		printf("Not Convergent!\n Maximum allowed iteration reached");
	}
	return 0;
}
