//@Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT.
//Inserting and Deleting elements in Circular Queue using Arrays.
// Possible VIVA Questions are displayed in comments with their answers.

#include<stdio.h>
/*Pre-processor directive initializing macro-substitution of SIZE to 5 before code is compiled.
Why do this?
Answer: Faster way of compiling. */

#define SIZE 5

//Prototype / Forward Declaration
/* Viva Q: Is this type of declarion "void enQueue"(void);" required?
Answer: Though this type of declarion is technically the correct way to declare, it is implicit in most compilers. Therefore "void enQueue();" is enough.
 Note: In certain compilers it gives a warning "This type of declaration is not a prototype". Fix it by adding the explicit "void" inside the function bracket.
*/

void enQueue();
void deQueue();
void display();

int myCQ[SIZE]; //Array implementation of Circular Queues

/* Viva Q: What is the advantage of Circular Queues?
 Answer: Once "int myCQ[SIZE];" Queue delcaration is done, SIZE *2 , memory cannot be used for any other programs.
In tbis case 5*2 = 10 continuous memory locations are locked and fixed for the "myCQ" array.
In a Linear Queue,every deletion of the element in Queue moves "front" to the next index.
Hence the size of the Queue appears shrunk.
E.g. "myQ[0] and myQ[1] is deleted means "front" points to 2.Only 3 more array slots are available in this linesr Q.
But, in reality, the memory space for myQ[0] and myQ[1] are available.
Only, the logic for Linear Queue makes them inaccessible for inserting elements.
Circular Queues solves this problem by shifting "rear = -1".
This is when "if(rear == SIZE-1 && front != 0)" is encountered in euQueue function.
This means it makes the deleted elements position available for new insertions to heppen.
In this example myQ[0] and myQ[1] becomes freed up for new elements to be inserted.*/


int front = -1;
int rear = -1;

/* NOTE: Viva Q: Is "int front, rear = -1;" a valid declaration?
Answer: Yes it is. This is called declaration and initialization in the same line
Caution: This may not work in some cases.
Reason: In some compilers it declares "front" and "rear" as integers. But initialises only "rear" to -1.
"front" may in some cases get initialized to 0, which is incorrect in our case.*/

int element;

int main()
{
    int choice;
   
    while(1){
        printf("\n****** CIRCULAR Q MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enQueue();
            break;
            case 2: deQueue();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nPlease select the correct choice!!!\n");
        }
    }
}
void enQueue()
{
    printf("\nEnter the value to be inserted:  ");
    scanf("%d",&element);
    
    printf("\n ***In enQueue entry*** front %d rear %d", front, rear); /*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book*/
    
    /*Viva Q: Which are the conditions when Circular Q is full?
     Answer: There are two conditions for the Circular q to be full:
    a) Enqueing made front = 0 and rear to keep on incrementing till max limit of Queue. No dequeue happened meanwhile
     Note: This is the first part of the "if" statement "(front == 0 && rear == SIZE - 1)" where front <= rear
    b) Enqueing and dequeing happens parallely
     Note: This is the second part of the "if" statement "(front == rear+1)" where "front" is one more than "rear"
    E.g front = 0 rear 5, all elements inserted.
    Start dequeing,front = 1 meaning cQueue[0] is free. rear made 0. cQueue[0] enqueued with value inserted
    dequeue again : front = 1 rear = 0. At this situation Q is full since cQueue[0] is inserted with value previously
     */
    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
    printf("\nSorry - Circular Queue is Full, therefore Insertion not possible!\n");
    
    else
    {
        /* Viva Q: How is EnQueing and DeQueing happening parallely in Circular Queue? */
        /* Answer:
        To tackle the case when Enqueing and dequeing happens parallely
        E.g front = 0 rear 4, all elements inserted. Start dequeing,front = 1 meaning cQueue[0] is free
        rear = 4, front = 1. Now rear has to be shifted to freed position. So rear = -1, so that ++rear will make it 0
        Refer explanation of "What is the advantage of Circular Queues?" above. */
        
        /* Trace the program for this condition and see the significance of this "if" statement */
        
        if(rear == SIZE-1 && front != 0) //Note difference with "(front == 0 && rear == SIZE - 1)" which means Q is FULL!
        rear = -1;
        
        //NOTE: "rear" is pre-incremented. It always points to current array index for enqueing
        myCQ[++rear] = element;
        printf("\nInserted %d Successfully!\n", myCQ[rear]);
        
        //Very first case, when Q is initially empty 
        if(front == -1)
        front = 0;
    }//end else
    
    printf("\n ***In enQueue exit*** front %d rear %d", front, rear); /*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book */
}//end enQueue

void deQueue()
{
    printf("\n ***In deQueue entry*** front %d rear %d", front, rear); /*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book */
    
    // Viva Q: When is Circular Q deemed empty?
    //Answer: This is the ONLY  condition when CIRCULAR Q is empty, that is when front and rear are -1.
    if(front == -1 && rear == -1)
    printf("\nCircular Queue is Empty. Therefore deletion is not possible!\n");
    
    /* Vivas Q: Is "front" always pointing to array index [0] always in Circular Q?
     Answer: No, "front" points to one more than the last index deQueued. Because front is post-incremented */
    else
    {
        /*NOTE: Make sure this is the first statement in else block of dequeue
        Reason: As long as Q is not empty, keep dequeing
        In some compilers if this statement is not put as first line, it messes up with the value of "front"
        and gives incorrect results*/
        
        element = myCQ[front++];
        //NOTE: "front" is post-incremented. It always points to next array index after dequeing
        printf("\nDeleted element is : %d\n",element);
        
        /*Viva Q: Why is below "if" statement required?
        Answer: Trace the program for this condition and see the significance of this "if" statement
        Answer HInt: To handle the case starting from dequeing when e.g front = 6 Rear = 5 when Q is again empty */
        
        if(front-1 == rear)
        front = rear = -1;
        
        /*Viva Q: Why is below "if" statement required?
        Trace the program for this condition and see the significance of this "if" statement
         Answer Tip: To tackle the case starting from dequeing when E.g. Front 6
         Here "front" keeps increasing as 1,2,3,4,5,6 and will keep doing so, if this condiction is not given*/
        
        if(front == SIZE )
            front = 0;
    }//end else
    
    printf("\n ***In deQueue exit*** front %d rear %d", front, rear);/*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book */
}//end deQueue

void display()
{
    if(front == -1)
    printf("\nCircular Queue is Empty!\n");
    else
    {
        int i;
        printf("\nCircular Queue Elements are : \n");
        if(front <= rear)
        {
            /* This is the condition when first enQueue happens, then deQueue. Meaning enQueue & deQueue donot happen parallely. This means "front <= rear" always. */
            for (i=front; i <= rear; i++)
            printf("%d\t",myCQ[i]);
        }
        /* Why is the "else" part of "display" looking so complicated with two for-loops?
         Answer: Display elements inserted in deQueued position and then display elements which were not deQueueed.
        TRY interchanging the execution of these two "for-loops" and see the difference in results for yourselves.
        Meaning, put second for-loop, before first one!
         */
        else
        {
            /* This is the condition when "front > rear". This happens when enQueue and deQueue happens parallely. */
            
            for (i = 0;i <= rear; i++) /*Start from the beginning of the Circular Queue which was deQueued meaning "rear" was re-initialized to "-1" and print the elements inserted. */
            printf("%d\t",myCQ[i]);
            
            for (i = front;i <= SIZE - 1; i++) /*Start from the position of "front" when previous deQueing stopped */
            printf("%d\t", myCQ[i]);
            
            
        }
    }
}//end display



