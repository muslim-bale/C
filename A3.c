/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int stack[20];

int top=-1;
void push (int x)
{
    stack[++top]= x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression");
    scanf("%s", exp);
    e= exp;
    while(*e!= '\0')
    {
        if(isdigit(*e))
        {
            num= *e-48;
            push(num);
        }
        else 
        {
            n1= pop();
            n2= pop();
            switch(*e)
            {
                case'+':
                {
                    n3=n1+n2;
                    break;
                }
                 case'-':
                {
                    n3=n2-n1;
                    break;
                }
                 case'*':
                {
                    n3=n1*n2;
                    break;
                }
                 case'/':
                {
                    n3=n2/n1;
                    break;
                }
            }
            push(n3);
            
        }
        e++;
    }
    printf("\n The result of the expression %s= %d",exp,pop());

    return 0;
}

