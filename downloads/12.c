#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    int n, m, ht[MAX], i, j, k, rec, address, homebucket, currentbucket, count = 0, choice;
    printf("enter the number of employee records:");
    scanf("%d", &n);
    for (i = 0; i < MAX; i++)
        ht[i] = -1;
    for (k = 0; k < n; k++)
    {
        printf("\n enter the record %d\n", k + 1);
        scanf("%d", &rec);
        address = rec % MAX;
        homebucket = address;
        currentbucket = homebucket;
        while (ht[currentbucket] != -1)
        {
            currentbucket = (currentbucket + 1) % MAX;
            if (currentbucket == homebucket)
            {
                printf("hash table overflow");
                exit(0);
            }
            count++;
        }
        if (count != 0)
            printf("collision occured %d times and solved using linear probing\n", count);
        count = 0;
        ht[currentbucket] = rec;
        printf("record:%d\nhome address:%d\ncurrent address:%d\n", rec, homebucket, currentbucket);
    }
    printf("\n HASH TABLE DISPLAY\n");
    while (1)
    {
        printf("\n\n***************menu****************");
        printf("\n1.complete hash table contents\n2.hash table showing only record enteries\n3.exit\n\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("complete hash table contents :\n");
            for (j = 0; j < MAX; j++)
                printf("%d %d \n", j, ht[j]);
            break;
        case 2:
            printf("hash table showing records :\n");
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
