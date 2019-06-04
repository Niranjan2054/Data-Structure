//Conversion from Prefix to Post Fix
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define MAX 50
int top = -1;
char arr[MAX];
void push(char ch){
	if(top==MAX-1){
		printf("Stack is Full");
	}else{
		arr[++top] = ch;
	}
}
char pop(){
	if(top>=0){
		return arr[top--];
	}else{
		printf("Stack is Empty");
	}
	return 0;
}
char peek(){
	if(top<0){
		printf("Stack is empty");
	}else if(top>=MAX){
		printf("Stack is Full");
	}else{
		return arr[top];
	}
	return 0;
}
int top1 = -1;
int arr1[MAX];
void push1(int ch){
	if(top1==MAX-1){
		printf("Stack is Full");
	}else{
		arr1[++top1] = ch;
	}
}
int pop1(){
	if(top1>=0){
		return arr1[top1--];
	}else{
		printf("Stack is Empty");
	}
	return 0;
}
int peek1(){
	if(top1<0){
		printf("Stack is empty");
	}else if(top1>=MAX){
		printf("Stack is Full");
	}else{
		return arr1[top1];
	}
	return 0;
}

void preparestatement(char str[]){
	int i,len;
	len = strlen(str);
	for(i = len-1;i>=0;i--){
		str[i+1]=str[i];
	}
	str[0]='(';
	str[len+1]=')';
	str[len+2]='\0';
}
int isparenthesis(char ch){
	if(ch=='('){
		return (1);
	}else if (ch==')'){
		return (2);
	}
	return 0;
}
int checkprecedence(char ch){
	if(ch=='+' || ch =='-'){
		return 1;
	}else if(ch=='*' || ch=='/'){
		return 2;
	}else if(ch=='^' || ch=='%'){
		return 3;
	}
	return 0;
}
void convert(char str[],char exp[]){
	int i,len,track=0;
	char p;
	int a,b;
	len = strlen(str);
	printf("\n     Element    Stack    Expression");
	for(i=0;i<len;i++){
		if(isparenthesis(str[i])){
			if(isparenthesis(str[i])==1){
				push(str[i]);
			}else if(isparenthesis(str[i])==2){
				do{
					p = pop();
					if(p != '('){
						exp[track++]=p;
					}
				}while(p !='(');
			}
		}else if(checkprecedence(str[i])){
			p = peek();
			if(isparenthesis(p)){
				push(str[i]);
			}else{
				a = checkprecedence(p);
				b = checkprecedence(str[i]);
				if(a==b){
					p = pop();
					push(str[i]);
					exp[track++]=p;
				}else if(a>b){
					do{
						p = pop();
						exp[track++]=p;
						p = peek();
						a = checkprecedence(p);
					}while(a>=b);
					push(str[i]);
				}else if(a<b){
					push(str[i]);
				}
			}

		}else{
			exp[track++]=str[i];
		}
		arr[top+1]='\0';
		exp[track+1] ='\0';
		printf("\n\t%c\t%-10s%s",str[i],arr,exp);
	}
	while(top>0){
		p = pop();
		if(p != '('){
			exp[track++] = p;
		}
	}
	exp[track+1]='\0';
	printf("\nEquivalent PostFix:\t  %s",exp);

}
int isalpha(char ch){
	if(ch>='a' && ch <='z'){
		return (1);
	}else if(ch>='A' && ch<= 'Z'){
		return (1);
	}
	return 0;
}
int calc(int num1, int num2, char ch){
	if(ch=='+'){
		return (num2+num1);
	}else if(ch=='-'){
		return (num2-num1);
	}else if(ch=='*'){
		return (num2*num1);
	}else if(ch=='/'){
		return (num2/num1);
	}else if(ch=='%'){
		return (num2%num1);
	}else if(ch=='^'){
		return (pow(num1,num2));
	}
	return 0;
}
void evaluate(char exp[]){
	int i, len;
	int a,b,num;
	len = strlen(exp);
	printf("\n");
	for(i=0;i<len;i++){
		if(isalpha(exp[i])){
			printf("Enter value of %c: ",exp[i]);
			scanf("%d",&num);
			push1(num);
		}else{
			a = pop1();
			b = pop1();
			num = calc(a,b,exp[i]);
			push1(num);
		}
	}
	printf("The result is %d",peek1());
}
void main(){
	char str[MAX],exp[MAX];
	clrscr();
	strcpy(exp,"");
	printf("Enter a expression: ");
	scanf("%s",str);
	preparestatement(str);
	convert(str,exp);
	evaluate(exp);
	getch();
}
