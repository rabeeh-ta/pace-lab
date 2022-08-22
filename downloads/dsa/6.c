
#include <stdio.h>
#include <stdlib.h>
#define max 3
char cqueue[max];
int front = -1;
int rear = -1;
void enqueue()
{
    if (front == rear + 1 || (front == 0 && rear == max - 1))
    {
        printf("\n!!!!!!***** Circular Queue is full... *****!!!!!!\n");
    }
    else
    {
        char ele;
        printf("Enter the element which is to be inserted: ");
        getc(stdin);
        scanf("%c", &ele);

        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front != 0 && rear == max - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        cqueue[rear] = ele;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\n!!!!! Circular Queue is empty...!!!!!\n");
    }
    else
    {
        char ele = cqueue[front];
        if (front == rear)
        {

            front = -1;
            rear = -1;
        }
        else if (front == max - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }

        printf("\nThe dequeued element is %c", ele);
    }
}

void display()
{
    int i, j;
    if (front == -1 && rear == -1)
    {
        printf("\n!!!!! Circular Queue is empty...!!!!!\n");
    }
    printf("The elements in a circular queue are: ");
    if (front > rear)
    {
        for (i = front; i <= max; i++)
        {
            printf("\t%c", cqueue[i]);
        }
        for (j = 0; j <= rear; j++)
        {
            printf("\t%c", cqueue[j]);
        }
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("\t%c", cqueue[i]);
        }
    }
    printf("\n");
}
int main()
{

    int choice;
    char ele;

    while (1)
    {
        printf("\n *** Menu ***\n1: Insert an element");
        printf("\n2: Delete an element");
        printf("\n3: Display the element");
        printf("\n4: Exit");
        printf("\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice...");
            break;
        }
    }
    return 0;
}
