#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *head = NULL, *thishead, *pnew;
void getnode(int data){
    pnew = (struct node*)malloc(sizeof(struct node));
    pnew->data = data;
    pnew->left = NULL;
    pnew->right = NULL;
}
void insert(int data){
    getnode(data);
    if(head == NULL){
        head = pnew;
    }else{
        insert_node(pnew, head);
    }

}
void insert_node(struct node *newNode, struct node *oldnode){
    if(newNode->data <= oldnode->data){
        if(oldnode->left==NULL){
            oldnode->left = newNode;
        }else{
            insert_node(newNode,oldnode->left);
        }
    }else{
        if(oldnode->right==NULL){
            oldnode->right = newNode;
        }else{
            insert_node(newNode,oldnode->right);
        }

    }
}

void display(struct node *head){
    if(head!=NULL){
        display(head->left);
        printf("%d\t",head->data);
        display(head->right);
    }
}
int search(int a,struct node *head){
    if(head==NULL){
        return 0;
    }else if(head->data==a){
        return head->data;
    }else if(a < head->data){
        search(a,head->left);
    }else{
        search(a,head->right);
    }
}

int main()
{
    int a,choice,success;
    while(1){
        printf("\n\t1.Insert Element");
        printf("\n\t2.Search Element");
        printf("\n\t3.Display Element");
        printf("\n\t4.Exit");
        printf("\n\n\tEnter your Choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("Enter a number to insert: ");
            scanf("%d",&a);
            insert(a);
            break;
        case 2:
            printf("Enter a element to search: ");
            scanf("%d",&a);
            success = search(a,head);
            if(success){
                printf("Element Found, Search Completed");
            }else{
                printf("Element Not Found");
            }
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Choose Correct Option: ");
        }
    }
}
