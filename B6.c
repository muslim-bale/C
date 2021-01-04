/*
 @Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT, Bangalore
 Purpose: This program does the following:
 a) Creates a Single Link with each node having values that defines a polynomial:
 --- the coefficient
 --- the power
 --- pointer to next such 'poynomial' node
 b) Ensures that Single Linked List is ordered in Descending Value of the polynomial power value. This means:
 --- 'head' node always has the term with the HIGHEST value of power
 --- tail or last node always has the term with the LOWEST value of power
 --- It is allowed to have duplicate terms for the power value. This just means that there will be many nodes with the same values. E.g multiple 3x^4 (OR) 6x^4 and 5x^4
 c) Terminates the polynomial entry / creation when the user enters '0' for the value of BOTH power and coefficient
 NOTE: You can always enter EITHER Coefficient OR Power to be zero to accomodate cases such as
---- 0x^3 where the coefficient of x^3 is zero
---- 4x^0 where the power of coeffcient 4 is zero meaning 4 will be multiplied by 1(that is 4x1)
 d) Evaluates the value of the polynomial where the value of the term 'x' is entered
 e) Assumptions:
 --- It is assumed that the polynomial will add up the terms
 --- If subtraction needs to be done negative coefficients need to be entered
 --- it is assumed that the coefficient and powers are numbers and not alphabets or special characters
 --- When the coefficient value is entered as zero, it is assumed that the data entry for polynomial creation is done. The power value is not considered in this case.
 */

#include <stdio.h>
#include<stdlib.h>
#include <math.h> // For power function to do stuff like x^4
typedef struct polynode
{
    int coeff;
    int power;
    struct polynode *next;
}polynode;

polynode *head;

//Creating the polynomial
void createPolynomial()
{
    polynode *ptr, *newnode, *prev;
    ptr = newnode = prev = NULL;
    int coeff, power;
    printf("Enter the coeff and power terminated when coeff & power value equals 0 \n");
    scanf("%d %d", &coeff, &power);
    
    /*
     NOTE: Inspite of this code, while loop condiction commented is NOT WORKING
    printf("\n Enter value of coeff");
    scanf("%d", &coeff);
    fflush(stdin); //With this statement you are flushing the keyboard buffer
    printf("\n Enter value of power");
    scanf("%d",  &power);
    
     Below while loop condition is NOT Working. Hence the assumtpion:
     --- When the coefficient value is entered as zero, it is assumed that the data entry for polynomial creation is done. The power value is not considered in this case.
    //while(coeff != 0 && power != 0){
    */
    
    while(coeff != 0)
    {
        newnode = (polynode *)malloc(sizeof(polynode));
        newnode->coeff = coeff;
        newnode->power = power;
        newnode->next = NULL; //As it is the 'head' node its link must be NULL
        if(head == NULL) //'head' == NULL initially
            head = newnode ; /* If 'head' is NULL, then there is no list, so newnode is the head Node inserted */
        else //If the list has some nodes
        {
            //'head' node always has the term with the HIGHEST value of power
            if(newnode->power > head->power)//newnode's power value is larger than head node's power
            {
                newnode->next = head;
                head = newnode; //Newnode becomes head
            }
            else
            {
                ptr = head;
                //Keep traversing until the newnode's power value is less than current node's power
                // This is to insert the newnode in the current descending order of power
                //It is allowed to have duplicate terms for the power value. This is the reason it is
                //checked as 'newnode->power  < ptr->power' and not 'newnode->power  <= ptr->power'
                while( (ptr!= NULL) && (newnode->power  < ptr->power) )
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                if(ptr == NULL)    //When current last node is reached
                {
                    prev->next = newnode;///current lastnode's next value is assigned to newnode address
                    newnode->next = ptr; //newnode becomes last node
                }
                else //For newnode has intermediate power values
                {
                    prev->next = newnode;//newnode power value is greater than OR equal to current node
                    newnode->next = ptr;
                }
            }
        }
        
        printf("\n Enter value of coeff");
        scanf("%d", &coeff);
        fflush(stdin); //Demo: Comment this, you may get segmentation fault in some machines
        //This is because '\n' when you press enter is entered into the value of 'power'
        //With this statement you are flushing the keyboard buffer
        printf("\n Enter value of power");
        scanf("%d",  &power);
    }//end of while
}//end of createPolynomial function
//Evaluation of the Polynomial
int evaluatePolynomial()
{
    polynode *ptr;
    int result, x; result = x = 0;
    printf("Enter the value of X in the Polynomial  \n");
    scanf("%d", &x);
    ptr = head;
    while(ptr!= NULL) //Traversing the single linked list till last node
    {
        ///Adding up the coefficient multipled by the term x^power
        result = result + ptr->coeff * pow(x, ptr->power);
        ptr = ptr->next;
    }
    return result;
}
//Display Function
void displayPolynomial()
{
    polynode *ptr;
    if(head == NULL)
    {
        printf("Empty Polynomial \n");
        return;
    }
    ptr = head;
    while(ptr!= NULL) //Traversing the single linked list till last node
    {
        printf("%d*x^%d –>", ptr->coeff, ptr->power);
        ptr = ptr->next;
    }
    printf("NULL"); // Just to say polynomail ended
}

int main()
{
    int choice, result;
    for(;;)
    {
        printf("\n1.Create Polynomial\n2.Evaluate\n3.Display\n4.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                createPolynomial();
                printf("\nUse Option 3 to display the polynomial After Creation");
                break;
            case 2:
                result = evaluatePolynomial();
                printf("\nResult is %d", result);
                break;
            case 3:
                printf("\nPolynomial is ");
                displayPolynomial();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option\n\n");
                break;
        }
    }
}

