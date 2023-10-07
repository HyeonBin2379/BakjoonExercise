#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int* cnt){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else {
        (*cnt)++;
        return recursion(s, l+1, r-1, cnt);
    }
}

int isPalindrome(const char *s, int* count){
    (*count)++;
    return recursion(s, 0, strlen(s)-1, count);
}

int main(void)
{
    int testCase;

    scanf("%d", &testCase);
    for (int i = 0; i < testCase; i++)
    {
        char str[1001] = {0,};
        int res;
        int count = 0;
        
        scanf("%s", str);
        res = isPalindrome(str, &count);
        printf("%d %d\n", res, count);
    }
    return 0;
}