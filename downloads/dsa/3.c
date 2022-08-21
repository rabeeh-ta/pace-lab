#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 3

void push(int[], int, int);
int pop(int[], int);
void palin(int[], int);
void display(int[], int);

int main()
{
    int choice, stack[MAX], top = -1, ele;
    while (1)
    {
        printf("\n\n***************menu***************");
        printf("\n 1. push an elelment to stack \n 2. pop an element from stack\n 3. checking stack for palindrome\n 4. display the status of the stacks\n 5. exit\n");
        printf("enteryour choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top < MAX - 1)
            {

                printf("Enter the Element to be pushed :");
                scanf("%d", &ele);
                top++;
                push(stack, ele, top);
            }
            else
                printf("stack is full\n");
            break;

        case 2:
            if (top >= 0)
            {
                ele = pop(stack, top);
                top--;
                printf("The element popped is %d ", ele);
                break;
            }
            else
            {
                printf("Stack is empty\n");
                break;
            }

        case 3:
            palin(stack, top);
            break;

        case 4:
            display(stack, top);
            break;

        case 5:
            exit(0);
        }
    }
}

void push(int stack[MAX], int ele, int top)
{
    stack[top] = ele;
}

int pop(int stack[MAX], int top)
{
    return stack[top];
}

void palin(int stack[MAX], int top)
{
    int i, num = 0, count = 0, temp = 0, dup = 0, digit = 0, rev = 0;
    if (top >= 0)
    {
        for (i = top; i >= 0; i--)
        {
            num = stack[i];
            while (num != 0)
            {
                num = num / 10;
                count++;
            }
            temp = temp * pow(10, count) + stack[i];
            count = 0;
        }
        dup = temp;
        while (temp != 0)
        {
            digit = temp % 10;
            rev = rev * 10 + digit;
            temp = temp / 10;
        }
        if (dup == rev)
            printf("the content of the stack is pallindrome");
        else
            printf("the content of the stack is not pallindrome");
    }
    else
        printf("stack is empty\n");
}
void display(int stack[MAX], int top)
{
    int i;
    if (top >= 0)
    {
        printf("the elements of stack are \n\n");
        for (i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }
    else
        printf("stack is empty\n");
}
