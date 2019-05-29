#include<stdio.h>
#include<conio.h>
#define MAX 10
int front =0;
int rear =0;
int queue[MAX];
int isfull(){
	if(rear==MAX-1){
		return 1;
	}
	return 0;
}
int isempty(){
	if(front==rear){
		return 1;
	}
	return 0;
}
void enqueue(int in){
	if(isfull()){
		printf("Queue is FULL!");
	}else{
		queue[rear++]=in;
		printf("\nQueued Successfully");
	}
}
int dequeue(){
	int a;
	if(isempty()){
		printf("Queue is EMPTY!");
		return 0;
	}
	a = queue[front++];
	return a;
}
void display(){
	int i;
	printf("\n\tQueued Element are: ");
	for(i=front;i<rear;i++){
		printf("\t%d",queue[i]);
	}
}
void main(){
	int a;
	while(1){
		clrscr();
		printf("\n\t1. Insertion Operation");
		printf("\n\t2. Deletion Operation");
		printf("\n\t3. Dislay");
		printf("\n\t4. Exit");
		printf("\n\tChoose Option...:");
		scanf("%d",&a);
		switch (a){
			case 1:
				printf("\nEnter a number to insert: ");
				scanf("%d",&a);
				enqueue(a);
				break;
			case 2:
				a = dequeue();
				if(a){
					printf("Dequeued Element %d successfully",a);
				}
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Choose a valid input");
		}
		getch();
	}
}