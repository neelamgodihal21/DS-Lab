#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;

};

void create(struct node **hptr){
	
	struct node *newnode,*temp;
	int item;
	
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&item);
	
	newnode->data=item;
	newnode->next=NULL;
	
	if(*hptr==NULL){
		*hptr=newnode;
	}
	else{
		temp=*hptr;
		
		while(temp->next!=NULL){
			
			temp=temp->next;
			
		}
		temp->next=newnode;
	}
}

void display(struct node *hptr){
	
	struct node *temp;
	temp=hptr;
	
	if(hptr==NULL){
		printf("The list is empty");
	}
	else{
		while(temp!=NULL){
			printf("%d",temp->data);
			printf("->");
			temp=temp->next;
		}
	}
}

void reverse(struct node **hptr){
	
	struct node *prev=NULL,*current=*hptr,*next=NULL;
	
	while(current!=NULL){
		next=current->next; //always increment next first
		current->next=prev; //reversing the link
		prev=current; //kinda like incrementing prev
		current=next; //kinda like incrementing current
	}
	*hptr=prev; //setting last node as head(reversing)
}

void concat(struct node *temp1,struct node *temp2){
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=temp2;
	
	/*if(temp1==NULL && temp2==NULL){
		printf("Both the lists are empty!");
	}
	else if(temp1==NULL && temp2!=NULL){
		while(temp2!=NULL){
			
		}
	}*/
}

void sort(struct node *hptr){
	struct node *current=NULL,*next=NULL;
	current=hptr;
	//next=hptr;
	int temp;
	
	while(current->next!=NULL){
		next=current->next;
		
		while(next!=NULL){
			
			if((current->data)>(next->data)){
			temp=current->data;
			current->data=next->data;
			next->data=temp;
			//current=next;
			//next=current->next;
		    }
			next=next->next;
	    }
		current=current->next;
    }
}

int main(){
	
	int option,num;
	struct node *head1=NULL,*head2=NULL,*head3=NULL;
	
	do{
		
		printf("\nEnter your choice\n");
		printf("\n1.Create linked list 1 \n2.Add to list 1 \n3.Create linked list 2 \n4.Add to list 2 \n5.Display \n6.Reverse \n7.Concatination of list 1 and 2 \n8.Sort list \n9.Exit\n");
		scanf("%d",&option);
		
		switch(option){
			case 1:create(&head1);
				   break;
				   
			case 2:create(&head1);
				   break;
				   
			case 3:create(&head2);
				   break;
				   
			case 4:create(&head2);
				   break;
				   
			case 5:printf("Enter the list number");
				   scanf("%d",&num);
				   if(num==1)
					display(head1);
				   else
					display(head2);
				   break;
				   
			case 6:printf("Enter the list number");
				   scanf("%d",&num);
				   if(num==1)
					reverse(&head1);
				   else
					reverse(&head2);
				   break;
				   
			case 7:concat(head1,head2);
				   printf("Concatinated list is: ");
				   display(head1);
				   break;
				   
			case 8:printf("Enter the list number");
				   scanf("%d",&num);
				   if(num==1){
					sort(head1);
					display(head1);
				   }
				   else{
					sort(head2);
					printf("The sorted list is:");
					display(head2);
				   }
				   break;
			// default:printf("Enter a valid option.");
		}
	}while(option!=9);
}
