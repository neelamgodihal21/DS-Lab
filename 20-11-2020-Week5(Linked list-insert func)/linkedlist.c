#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void create(){
	struct node *newnode;
	struct node *temp;
	int item;
	
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&item);
	
	newnode->data=item;
	newnode->next=NULL;
	
	if(head==NULL){
		head=newnode;
	}
	else{
		temp=head;
		
		while(temp->next!=NULL){
			temp=temp->next;
		}
		
		temp->next=newnode;
	}
}

void insert_front(){
	struct node *newnode;
	int element;
	printf("Enter the element\n");
	scanf("%d",&element);
	
	newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=element;
	newnode->next=head;
	
	head=newnode;
}

void insert_atpos(int pos){
	 struct node *ptr=head;
	 struct node *ptr2=(struct node *)malloc(sizeof(struct node));
	 int ele;
	 
	 printf("Enter the element to be inserted\n");
	 scanf("%d",&ele);
	 
	 ptr2->data=ele;
	 ptr2->next=NULL;
	 
	 pos--;
	 while(pos!=1){
		 ptr=ptr->next;
		 pos--;
	 }
	
	ptr2->next=ptr->next;
	ptr->next=ptr2;
}

void display(){
	struct node *p;
	p=head;
	
	if(p==NULL){
		printf("There's no node in the list\n");
	}
	else{
		while(p!=NULL){
			printf("%d\t",p->data);
			p=p->next;
		}
	}
}

int main(){
	
	int option,ele;
	int position;
	
	do{
		printf("\n1.Create \n2.Display \n3.Insert at first position \n4.Insert at end \n5.Insert at any position \n6.Exit\n");
		scanf("%d",&option);
		
		switch(option){
			case 1: create();
					break;
					
			case 2: display();
					break;
					
			case 3: insert_front();
					break;
					
			case 4: create();
					break;
					
			case 5: printf("\nEnter the position where you want to insert the element\n");
					scanf("%d",&position);
					insert_atpos(position);
					break;
		}
	}while(option!=6);
	
	
}
