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

void delete(int element){
	struct node *temp,*del=NULL;
	
	temp=head;
	if(head==NULL){
		printf("Cannot delete.The list is empty\n");
	}
	
	if(head->data==element){
		head=head->next;
		return;
	}
	
	while(temp->next!=NULL){
		if(temp->next->data==element){
			del=temp->next;
			
			if(del->next==NULL){
				temp->next=NULL;
			}
			else{
				temp->next=del->next;
			}
		}
		else{
			temp=temp->next;
		}
	}

	if(del==NULL){
		printf("Element was not found.Please enter a valid element\n");
	}
}

void delFirst(){
	head=head->next;
	return;
}

void delLast(){
	struct node *temp,*del=NULL;
	
	temp=head;
	while(temp->next!=NULL){
		del=temp->next;
		
		while(del->next==NULL){
			temp->next=NULL;
			return;
		}
		
		temp=temp->next;
	}
}

void display(){
	struct node *p;
	p=head;
	
	if(p==NULL){
		printf("There's no element/node in the list.\n");
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
		printf("\n1.Create \n2.Add \n3.Display \n4.Delete first element \n5.Delete the last element \n6.Delete specific element \n7.Exit\n");
		scanf("%d",&option);
		
		switch(option){
			case 1: create();
					break;
					
			case 2: create();
					break;
			
			case 3: display();
					break;
					
			case 4: delFirst();
					break;
			
			case 5: delLast();
					break;
			
			case 6: printf("Enter the element you want to delete\n");
					scanf("%d",&ele);
					delete(ele);
					break;
		}
	}while(option!=7);
	
	
}
