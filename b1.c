/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
char stack[30];
int top= -1;
void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top== -1)
    return -1;
    else
    return stack[top--];
}

int select(char x)
{
    if(x=='(')
    return 0;
    if(x=='+'|| x=='-')
    return 1;
    if(x=='*'|| x=='/')
    return 2;
}

int main()
{
    char exp[30];
    char *e, x;
    printf("Enter the expression ");
    scanf("%s", exp);
    e= exp;
    while(*e!= '\0')
    {
        if(isalnum(*e))
        printf("%c" , *e);
        else if(*e=='(')
        push(*e);
        else if(*e== ')')
        {
            while((x=pop())!= '(')
            printf("%c", x);
        }
    
    else 
    {
        while (select(stack[top])>=select(*e))
        printf("%c",pop());
        push(*e);
    }
    e++;
}
while(top!= -1)
{
    printf("%c", pop());
}
    

    return 0;
}

