#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int stack[50];
int top = -1;
void push(int);
int pop();
void push(int num)
{
    stack[++top] = num;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char suffix[50], ch;
    int p1, p2, p3, i;
    printf("Enter the valid suffix expression : ");
    gets(suffix);
    for (i = 0; suffix[i] != '\0'; i++)
    {
        ch = suffix[i];
        // puts(ch);
        if (isdigit(ch))
            push(ch - '0');
        else
        {
            p2 = pop();
            p1 = pop();
            switch (ch)
            {
            case '+':
                push(p1 + p2);
                break;
            case '-':
                push(p1 - p2);
                break;
            case '*':
                push(p1 * p2);
                break;
            case '/':
                if (p2 == 0)
                {
                    printf("Divide by Zero error\n");
                    exit(0);
                }
                push(p1 / p2);
                break;
            case '%':
                if (p2 == 0)
                {
                    printf("Divide by Zero error\n");
                    exit(0);
                }
                push(p1 % p2);
                break;
            case '^':
                push(pow(p1, p2));
                break;
            default:
                printf("Invalid Expression\n");
            }
        }
    }
    printf("The value of given suffix expression is : %d\n", pop());
}
