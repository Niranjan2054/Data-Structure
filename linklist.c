#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *pfirst=NULL;
struct node *pnew, *ptemp, *temp;
void getnode(int data){
	pnew = (struct node*)malloc(sizeof(struct node));
	pnew->data=data;
	pnew->next = NULL;
}
void freenode(struct node *ptr){
	free(ptr);
}
void insert_from_begining(int data){
	getnode(data);
	pnew->next = pfirst;
	pfirst = pnew;
}
void insert_from_end(int data){
	getnode(data);
	ptemp = pfirst;
	while(ptemp->next!=NULL){
		ptemp = ptemp->next;
	}
	ptemp->next = pnew;
}
void insert_before_xth_position(int data, int position){
	int i;
	if(position<0 || position > length()){
		printf("Invalid postion");
	}else{
		if(position ==1 || position ==0){
			insert_from_begining(data);
		}else{
			getnode(data);
			ptemp = pfirst;
			for(i=0;i<position-2 && ptemp->next!=NULL;i++){
				ptemp = ptemp->next;
			}
			pnew->next = ptemp->next;
			ptemp->next = pnew;
		}
	}
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
int delete_from_begining(){
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
int delete_from_end(){
	int a;
	if(length()){
		if(length()==1){
			delete_from_begining();
		}else{
			ptemp = pfirst;
			while(ptemp->next->next!=NULL){
				ptemp = ptemp->next;
			}
			a = ptemp->next->data;
			free(ptemp->next);
			ptemp->next = NULL;
			return a;
		}
	}
	return 0;
}
int delete_from_xth_position(int position){
	int a,i;
	if(position>=1 && position <=length()){
		if(position==1){
			delete_from_begining();
		}else{
			ptemp = pfirst;
			for(i=0;i<position-2;i++){
				ptemp = ptemp->next;
			}
			temp = ptemp->next;
			a = temp->data;
			ptemp->next = ptemp->next->next;
			free(temp);
			return a;
		}
	}else{
		printf("Invalid position");
	}
	return 0;
}
void display(){
	ptemp = pfirst;
	printf("The List Element are: ");
	while(ptemp!=NULL){
		printf("\t%d",ptemp->data);
		ptemp = ptemp->next;
	}
}

int main(){
	int a,pos;
	while(1){
		printf("\n\tLink List Operation");
		printf("\n\t1. Insertion from the begining");
		printf("\n\t2. Insertion from the end");
		printf("\n\t3. Insertion at xth position");
		printf("\n\t4. Deletion from the begining");
		printf("\n\t5. Deletion from the end");
		printf("\n\t6. Deletion of xth data");
		printf("\n\t7. Display");
		printf("\n\t8. Exit");
		printf("\n\tChoose Option...: ");
		scanf("%d",&a);
		switch(a){
			case 1:
				printf("Enter element to insert");
				scanf("%d",&a);
				insert_from_begining(a);
				printf("Element added Successfully");
				break;
			case 2:
				printf("Enter element to insert");
				scanf("%d",&a);
				insert_from_end(a);
				printf("Element added Successfully");
				break;
			case 3:
				printf("Enter element to insert and position");
				scanf("%d%d",&a,&pos);
				insert_before_xth_position(a,pos);
				printf("Element added Successfully");
				break;
			case 4:
				a = delete_from_begining();
				if(a){
					printf("Element %d deleted successfully",a);
				}
				break;
			case 5:
				a  = delete_from_end();
				if(a){
					printf("Element %d deleted Succssfully",a);
				}
				break;
			case 6:
				printf("Enter the position of data to delete: ");
				scanf("%d",&pos);
				a = delete_from_xth_position(pos);
				if(a){
					printf("Element %d deleted Successfully",a);
				}
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("Enter valid option..");

		}
		getchar();
	}
	return 0;
}
