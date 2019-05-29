#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *pfirst=NULL;
struct node *pnew, *ptemp;
void getnode(int data){
	pnew = (struct node*)malloc(sizeof(struct node));
	pnew->data=data;
	pnew->next = NULL;
}
void freenode(struct node *ptr){
	free(ptr);
}
void insert(int data){
	getnode(data);
	pnew->next = pfirst;
	pfirst = pnew;
}
int length(){
	int len=0;
	ptemp = pfirst;
	while(ptemp!=NULL){
		ptemp = ptemp->next;
		len++;
	}
	return len;
}
int del(){
	int a;
	if(length()){
		ptemp = pfirst;
		pfirst = pfirst->next;
		a = ptemp->data;
		free(ptemp);
		return a;
	}
	printf("length = %d:",length());
	return 0;
}
void display(){
	if(pfirst!=NULL){
		printf("The Top Element is: %d",pfirst->data);
	}else{
		printf("Stack is empty...");
	}
}
int main(){
	int a,pos;
	while(1){
		printf("\n\n\tLink List Operation");
		printf("\n\t1. Insert into queue");
		printf("\n\t2. Delete from queue");
		printf("\n\t3. Display");
		printf("\n\t4. Exit");
		printf("\n\tChoose Option...: ");
		scanf("%d",&a);
		switch(a){
			case 1:
				printf("Enter element to insert");
				scanf("%d",&a);
				insert(a);
				printf("Element added Successfully");
				break;
			case 2:
				a = del();
				if(a){
					printf("Element %d deleted successfully",a);
				}
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Enter valid option..");

		}
		getchar();
	}
	return 0;
}
