#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count = 0;
int len;
int col[15] = {0,};

bool promising(int level)
{
    for (int i = 0; i < level; i++)
    {
        if (col[i] == col[level])
            return false;
        else if (level-i == abs(col[level]-col[i]))
            return false;
    }
    return true;
}
void queens(int level)
{
    if (level == len) {
        count++;
        return;
    }

    for (int i = 0; i < len; i++)
    {
        col[level] = i;    
        if (promising(level)) {
            queens(level+1);
        }
    }
}

int main(void)
{
    scanf("%d", &len);
    queens(0);
    printf("%d", count);
    return 0;
}