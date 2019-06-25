#include<stdio.h>
#include<conio.h>
struct node{
	struct node *previous, *next;
	int data;
};
int len=0;
struct node *pfirst=NULL, *pnew, *pthis, *ptemp;
void getnode(int data){
	pnew = (struct node*)malloc(sizeof(struct node));
	pnew->data = data;
	pnew->previous = NULL;
	pnew->next = NULL;
}
int length(){
	int a=0;
	pthis = pfirst;
	while(pthis!=NULL){
		a++;
	}
	return a;
}
int insert_from_begining(int data){
	getnode(data);
	if(pnew==NULL){
		return 0;
	}
	pnew->next = pfirst;
	if(pfirst!=NULL){
		pfirst->previous = pnew;
	}
	pfirst = pnew;
	len++;
	return 1;
}
int insert_from_end(int data){
	getnode(data);
	if(pnew==NULL){
		return 0;
	}
	pthis = pfirst;
	while(pthis->next!=NULL){
		pthis= pthis->next;
	}
	pthis->next = pnew;
	pnew->previous = pthis;
	len++;
	return 1;
}
int insert_at_xth_position(int data, int position){
	int i,a;
	getnode(data);
	if(pnew==NULL){
		return 0;
	}
	if(position == 1){
		a = insert_from_begining(data);
		return a;
	}else if(position>1 || position <=len){
		pthis = pfirst;
		for(i=0;i<position-2 && pthis!=NULL;i++){
			pthis=pthis->next;
		}
		pnew->next = pthis->next;
		pthis->next->previous = pnew;
		pthis->next = pnew;
		pnew->previous = pthis;
		len++;
		return 1;
	}
	return 0;
}
int delete_from_begining(){
	int a;
	ptemp = pfirst;
	pfirst = pfirst->next;
	pfirst->previous = NULL;
	a = ptemp->data;
	free(ptemp);
	len--;
	return a;
}
int delete_from_end(){
	int a;
	pthis = pfirst;
	while(pthis->next->next!=NULL){
		pthis= pthis->next;
	}
	a = pthis->next->data;
	free(pthis->next);
	pthis->next =NULL;
	len--;
	return a;
}
int delete_xth_data(int position){
	int a,i;
	if(position == 1){
		a = delete_from_begining();
		return a;
	}else if(position >1 && position <len){
		pthis = pfirst;
		for(i=0;i<position -2 ;i++){
			pthis = pthis->next;
		}
		ptemp = pthis->next;
		pthis->next = ptemp->next;
		ptemp->next->previous = pthis;
		a = ptemp->data;
		free(ptemp);
		len--;
		return a;
	}else if(position==len){
		a = delete_from_end();
		return a;
	}
	return 0;
}
void display(){
	pthis = pfirst;
	printf("\n\tThe data are(is):");
	while(pthis!=NULL){
		printf("\t%d",pthis->data);
		pthis= pthis->next;
	}
}
void main(){
	int a,success,position;
	while(a){
		printf("\n\tDoubly Linked List");
		printf("\n\t1.Insert from Begining");
		printf("\n\t2.Insert from end");
		printf("\n\t3.Insert at xth position");
		printf("\n\t4.Delete from begining");
		printf("\n\t5.Delete Last element");
		printf("\n\t6.Delete xth data");
		printf("\n\t7.Display all Data");
		printf("\n\t8.Exit");
		printf("\n\tChoose Your Option: ");
		scanf("%d",&a);
		switch (a){
			case 1:
				printf("Enter an element to add :");
				scanf("%d",&a);
				success = insert_from_begining(a);
				if(success){
					printf("\n\tElement Added Successfully");
				}else{
					printf("\n\tError Occurred");
				}
				break;
			case 2:
				printf("Enter an element to add :");
				scanf("%d",&a);
				success = insert_from_end(a);
				if(success){
					printf("\n\tElement Added Successfully");
				}else{
					printf("\n\tError Occured");
				}
				break;
			case 3:
				printf("Enter an position and element to add :");
				scanf("%d%d",&position,&a);
				success = insert_at_xth_position(a,position);
				if(success){
					printf("\n\tElement added Successfully");
				}else{
					printf("\n\tError Occured");
				}
				break;
			case 4:
				success = delete_from_begining();
				if(success){
					printf("\n\tElement %d deleted Successfully",success);
				}else{
					printf("\n\tError Occured");
				}
				break;
			case 5:
				success = delete_from_end();
				if(success){
					printf("\n\tElement %d deleted Successfully",success);
				}else{
					printf("\n\tError Occured");
				}
				break;
			case 6:
				printf("Enter an position of element to delete: ");
				scanf("%d",&position);
				success = delete_xth_data(position);
				if(success){
					printf("\n\tElement %d deleted Successfully",success);
				}else{
					printf("\n\tError Occured");
				}
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("\n\tEnter Correct Choice: ");
		}
		getch();
	}
}