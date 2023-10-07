#include <stdio.h>

double isPlusZeroMinus(char ch)
{
    if (ch == '+')
        return 0.3;
    if (ch == '0')
        return 0;
    if (ch == '-')
        return -0.3;
}
int main(void)
{
    char gpa[3] = {0, };
    double score= 0.0;

    scanf("%s", gpa);

    switch (gpa[0])
    {
        case 'A':
            score += 4;
            break;
        case 'B':
            score += 3;
            break;
        case 'C':
            score += 2;
            break;
        case 'D':
            score += 1;
            break;
        case 'F':
            printf("%.1f", score);
            return 0;
    }

    score += isPlusZeroMinus(gpa[1]);
    printf("%.1f", score);
    
    return 0;
}