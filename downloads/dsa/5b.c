#include <stdio.h>
void towers(int, char, char, char);
int main()
{
    int n;
    char source, dest, auxiliary;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("\nSOURCE = %c DESTINATION = %c AUXILIARY = %c\n", 'A', 'C', 'B');
    towers(n, 'A', 'C', 'B');
}
void towers(int n, char source, char dest, char auxiliary)
{
    printf("\n\nTOWERS : %d, %c, %c, %c", n, source, dest,auxiliary);
    if (n == 1)
        printf("\n\nMove from %c to %c", source, dest);
    else
    {
        towers(n - 1, source, auxiliary, dest);
        printf("\nMove from %c to %c", source, dest);
        towers(n - 1, auxiliary, dest, source);
    }
    printf("\n");
}
