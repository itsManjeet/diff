#include <stdio.h>
#include <string.h>

/* LCS Table of Strings size 50 
 * LCS[i][j] = LCS length
 */
int LCS[50][50];

int max (int a, int b) {
    return (a > b) ? a : b;
}


/* lcs_fill to fill up the lcs table */
void
lcs_fill (char* s1, char* s2,
          int   x,  int   y)
{
    for (int i =  0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {

            /* Starting row and col are filled with 0 */
            if (i == 0 || j == 0)
                LCS[i][j] = 0;

            /* if current character of s1 and s2 matches 
             * then LCS index == 1 + diagonally previous value */
            else if (s1[i-1] == s2[j-1])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            
            /* if not matches, then it will be max of above or previous index*/
            else
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);

        }   
    }
}


/* diff to display the difference */
void
diff (char* s1, char* s2,
      int   x,  int   y)
{
    /* if last char of s1 == s2 */
    if ( x > 0 && y > 0
        && s1[x-1] == s2[y-1])
    {
        diff(s1,s2,x-1,y-1);
        printf(" %c",s1[x-1]);
    }

    /* if char of *s2 not in *s1 */
    else if (y > 0 &&
        (x == 0 || LCS[x][y-1] >= LCS[x-1][y]))
    {
        diff(s1,s2,x,y-1);
        printf(" +%c",s2[y-1]);
    }

    /* if char of *s1 not in *s2 */
    else if (x > 0 &&
        (y == 0 || LCS[x][y-10] < LCS[x-1][y]))
    {
        diff(s1,s2,x-1,y);
        printf(" -%c",s1[x-1]);
    }
}


int
main(int argc,
     char **argv)
{
    char* s1 = "MANJEET SINGH";
    char* s2 = "MANJIT SAINI";
    
    int x = strlen(s1),
        y = strlen(s2);

    /* filling up lcs table */
    lcs_fill(s1, s2, x, y);

    /* displaying lcs table */
    for (int i = 0; i <= x; i++) {
        printf("[ ");
        for (int j = 0; j <= y; j++ ) {
            printf("%d ",LCS[i][j]);
        }
        printf("]\n");
    }

    printf("Difference in string is: ");
    puts(s1);
    puts(s2);

    printf(" is: ");
    diff(s1,s2,x,y);

    return 0;
}