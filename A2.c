
#include <stdio.h>
#define SIZE 5
int myQ[SIZE];
int front = -1; 
int rear = -1; 
int element;
void enQueue()
{
    
    printf("\n Enter the element to be added into the Queue \t");
    scanf("%d", &element);
    
    if(rear == SIZE-1) printf("\n Sorry cannot enqueue - Queue is FULL!!");
    
    else
    {
    if(front == -1) front = 0; 
    
    
    myQ[++rear] = element;
    printf("\n Enqueued by adding element %d in %d position which is value of rear", element,rear);
    printf("\n Queue has %d elements", rear+1);
    }//end else
    
    
}//end enQ

void deQueue()
{
    
    if(front == -1 || front > rear) printf("\n Sorry cannot dequeue - Queue Empty!!");
    else
    {
    element = myQ[front++];
    printf("\nElement %d in %d position(front)of queue deleted", element,front-1);
    printf("\n Queue start shifted to position %d which is value of front", front);
        
        if(front == rear+1)
        {
        
        front = -1;
        rear = -1;
        }
    }
    
    
}//end deQ

void display()
{
    if(front == -1 || front > rear)
    printf("\n Queue is Empty!!");
    else
    {
        printf("\n Displaying Queue Elements:");
        for(int i = front; i<=rear; i++)
        printf("\n %d ", myQ[i]);
       
    }
}
    
    
    


int main()
{
    int choice;
    
    while(1)
    {
        printf("\n Press 1. To Insert into Queue");
        printf("\n Press 2. To Delete from Queue");
        printf("\n Press 3. To Display Queue\t");
        printf("\n Press 4. To Exit Menu\t");
        scanf("%d", &choice);
        
        if(choice == 1)enQueue();
        else if(choice == 2)deQueue();
        else if(choice == 3) display();
        else if(choice == 4) exit(0);
        else printf("\nWrong entry : Press either 1, 2 or 3");
        
    }
    
    
}//end main
