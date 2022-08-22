#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    int n, m, ht[MAX], i, j, k, rec, address, homebucket, currentbucket,
        count = 0, choice;
    printf("Enter the number of employee records : ");
    scanf("%d", &n);
    for (i = 0; i < MAX; i++)
        ht[i] = -1;
    for (k = 0; k < n; k++)
    {
        printf("\nEnter the record %d\n", k + 1);
        scanf("%d", &rec);
        address = rec % MAX;
        homebucket = address;
        currentbucket = homebucket;
        while (ht[currentbucket] != -1)
        {
            currentbucket = (currentbucket + 1) % MAX;
            if (currentbucket == homebucket)
            {
                printf("Hash Table Overflow");
                exit(0);
            }
            count++;
        }
        if (count != 0)
            printf("Collision occured %d times and solved using Linear Probing\n", count);
        count = 0;
        ht[currentbucket] = rec;
        printf("Record : %d\nHome Address : %d\nCurrent Adrress : %d\n", rec, homebucket, currentbucket);
    }
    printf("\nHASH TABLE DISPLAY\n");
    while (1)
    {
        printf("\n\n**********************MENU*****************");
        printf("\n1. Complete Hash table contents\n2. Hash Table showing only record entries\n3. Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Complete Hash Table Contents :\n");
            for (j = 0; j < MAX; j++)
                printf("%d %d\n", j, ht[j]);
            break;
        case 2:
            printf("Hash Table showing Records : \n");
            for (j = 0; j < MAX; j++)
                if (ht[j] != -1)
                    printf("%d %d\n", j, ht[j]);
            break;
        case 3:
            exit(0);
            break;
        }
    }
}
