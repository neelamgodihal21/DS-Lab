#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int front=-1;
int rear=-1;
int queue[SIZE];

void Enque(int x){
    if((front==0 && rear==SIZE-1)||(front==rear+1)){
        printf("The queue is full.\n");
        return;
    }
    else{
            rear=(rear+1)%SIZE;
            queue[rear]=x;
            if(front==-1){
            front=0;
            }
    } 
}

void Deque(){
    if(front==-1 && rear==-1){
        printf("The queue is empty!\n");
        return;
    }
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%SIZE;
        }
    }
}

void display(){
   if((front==-1) && (rear==-1)){
       printf("The queue is empty.\n");
       return;
   }
   
   if(front>rear)
    {   
        for(int i=front;i<SIZE;i++)
            printf("\t%d",queue[i]);
        for(int j=0;j<=rear;j++)
            printf("\t%d",queue[j]);
    }
    else
    {
        printf("Contents of circular queue are:\n");
        for(int i=front;i<=rear;i++)
            printf("\t%d", queue[i]);
    }
}

int main(){
    int option,num;

    do{
        printf("\n--------CIRCULAR QUEUE--------\n");
        printf("Enter your choice\n");
        printf("1.To add an element to the queue(Enqueue).\n");
        printf("2.To remove an element from the queue(Dequeue).\n");
        printf("3.To display elements of the queue.\n");
        printf("4.To exit.\n");
        scanf("%d",&option);

        switch(option){
            case 1: printf("Enter the element\n");
                    scanf("%d",&num);
                    Enque(num);
                    break;
            case 2:Deque();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);      
        }
    } while(option!=4);
      
    return 0;
}
