#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 101
int main(void)
{
	char str[MAXSIZE] = {0, };
	int len;

	fgets(str, sizeof(str), stdin);
	len = strlen(str);
	
	for (int i = 0; i < len; i++)
	{
		char newChar;

		if (str[i] >= 'a' && str[i] <= 'z')
			newChar = (str[i] - 'a' + 13) % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			newChar = (str[i] - 'A' + 13) % 26 + 'A';
		else
			newChar = str[i];
		printf("%c", newChar);
	}

	exit(0);
}
