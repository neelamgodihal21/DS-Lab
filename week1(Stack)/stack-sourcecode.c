//Array implementation of STACK
#include <stdio.h>
#define SIZE 10
int arr[SIZE];
int top=-1;

void push(int x){
	if(top==SIZE-1){
		printf("Error:The stack is full.\n");
		return;
	}
	arr[++top]=x;
}

void pop() {
	if(top==-1){
		printf("Error:There's no element in the stack to pop.\n");
		return;
	}
	top=top-1;
}

void display(){
    if(top==-1){
        printf("There is no element left in the stack to display.\n");
    }
    else{
	    printf("Stack is as follows:\n");
	    for(int i=0;i<=top;i++){
		    printf("%d\n",arr[i]);
	    }
    }
	return;
}
int main() {
    int n,ele,i;
    while(i!=-1) {
 	    printf("Select the required option:\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
        scanf("%d",&n);
            if(n==1){
                printf("Enter the element to be pushed/added to the stack\n");
                scanf("%d",&ele);
                push(ele);
             }
            else if(n==2){
                pop();
            }
             else if(n==3){
                display();
            }
            else if(n==4)
                i=-1;
    }
    return 0;
}
