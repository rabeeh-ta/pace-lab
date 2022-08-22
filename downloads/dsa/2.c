#include <stdio.h>
#include <stdlib.h>
void ReadStrings();
void PatternMatching(char[], char[], char[]);
char STR[100], PAT[100], REP[100];
int main()
{
    ReadStrings(STR, PAT, REP);
    PatternMatching(STR, PAT, REP);
}
void ReadStrings(char STR[100], char PAT[100], char REP[100])
{
    printf("Enter the main string STR : ");
    gets(STR);
    printf("Enter the pattern string PAT : ");
    gets(PAT);
    printf("Enter the replace string REP : ");
    gets(REP);
}
void PatternMatching(char STR[100], char PAT[100], char REP[100])
{
    int i, j, k, m, c, flag, count;
    i = m = c = j = count = flag = 0;
    char RESULT[100];
    while (STR[c] != '\0')
    {
        if (STR[m] == PAT[i])
        {
            i++;
            m++;
            if (PAT[i] == '\0')
            {
                for (k = 0; REP[k] != '\0'; k++, j++)
                    RESULT[j] = REP[k];
                i = 0;
                c = m;
                count++;
                flag = 1;
            }
        }
        else
        {
            RESULT[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    if (flag == 0)
        printf("Pattern does not found\n");
    else
    {
        RESULT[j] = '\0';
        printf("Pattern found %d times\n", count);
        printf("The resultant string is\n%s\n", RESULT);
    }
}