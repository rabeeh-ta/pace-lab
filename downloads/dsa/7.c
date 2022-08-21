#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
struct node
{
    int sem, phno;
    char usn[50], name[50], branch[50];
    struct node *link;
};
struct node *first = NULL, *last = NULL, *temp = NULL, *temp1 = NULL;
void CreateNode()
{
    int sem, phno;
    char usn[50], name[50], branch[50];
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter usn,name, branch, sem, phno of student \n");
    scanf("%s %s %s %d %d", usn, name, branch, &sem, &phno);
    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem = sem;
    temp->phno = phno;
    temp->link = NULL;
    count++;
}
void InsertAtFront()
{
    if (first == NULL)
    {
        CreateNode();
        first = temp;
        last = first;
    }
    else
    {
        CreateNode();
        temp->link = first;
        first = temp;
    }
}
void InsertAtEnd()
{
    if (first == NULL)
    {
        CreateNode();
        first = temp;
        last = first;
    }
    else
    {
        CreateNode();
        last->link = temp;
        last = temp;
    }
}
void Display()
{
    temp1 = first;
    if (temp1 == NULL)
    {
        printf("\nList is empty \n");
    }
    else
    {
        printf("\nThe elements of SLL are :\n");
        while (temp1 != NULL)
        {
            printf("%s %s %s %d %d\n", temp1->usn, temp1->name, temp1->branch, temp1->sem, temp1->phno);
            temp1 = temp1->link;
        }
    }
    printf("Number of students = %d\n", count);
}
void DeleteAtEnd()
{
    struct node *temp;
    temp = first;
    if (first == NULL)
        printf("\nList is empty\n");
    else if (temp->link == NULL)
    {
        printf("The student record deleted is\n%s %s %s %d %d\n",
               temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        free(temp);
        first = NULL;
        count--;
    }
    else
    {
        while (temp->link != last)
            temp = temp->link;
        printf("The student record deleted is\n%s %s %s %d %d\n",
               last->usn, last->name, last->branch, last->sem, last->phno);
        free(last);
        temp->link = NULL;
        last = temp;
        count--;
    }
}
void DeleteAtFront()
{
    struct node *temp;
    temp = first;
    if (first == NULL)
        printf("\nList is empty\n");
    else if (temp->link == NULL)
    {
        printf("The student record deleted is\n%s %s %s %d %d",
               temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        free(temp);
        first = NULL;
        count--;
    }
    else
    {
        first = temp->link;
        printf("The student record deleted is\n%s %s %s %d %d",
               temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        free(temp);
        count--;
    }
}
int main()
{
    while (1)
    {
        int choice, n, i, choice2, flag1, flag2;
        printf("\n\n**********************MENU*****************");
        printf("\n1.Create a SLL of N students Data by using front insertion\n2. Display the status of SLL and count the number of nodes in it\n3. Perform Insertion/Deletion at End of SLL\n4. PerformInsertion/Deletion at Front of SLL (Demonstaration of SLL as STACK)\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of students : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                InsertAtFront();
            break;
        case 2:
            Display();
            break;
        case 3:
            flag1 = 0;
            while (flag1 == 0)
            {
                printf("\n\n1. Insertion\n2. Deletion\n3. Exit");
                printf("\n\nEnter your option\n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    InsertAtEnd();
                    Display();
                    break;
                case 2:
                    DeleteAtEnd();
                    Display();
                    break;
                case 3:
                    flag1 = 1;
                    break;
                }
            }
            break;
        case 4:
            flag2 = 0;
            printf("\n\nDemonstration of STACK\n");
            while (flag2 == 0)
            {
                printf("\n\n1. Insertion\n2. Deletion\n3. Exit\n");
                printf("\n\nEnter your option\n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    InsertAtFront();
                    Display();
                    break;
                case 2:
                    DeleteAtFront();
                    Display();
                    break;
                case 3:
                    flag2 = 1;
                    break;
                }
            }
            break;
        case 5:
            exit(0);
            break;
        }
    }
}