#include <stdio.h>
#include <stdlib.h>

enum Sort{ASC, DESC, MIXED};

int main(void)
{
	int code[8] = {0, };
	enum Sort mode;

	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &code[i]);
	}

	if (code[0] < code[1])
		mode = ASC;
	else
		mode = DESC;

	for (int i = 1; i < 7; i++)
	{
		if (mode == ASC)
		{
			if (code[i] > code[i+1])
			{
				mode = MIXED;
				break;
			}	
		}
		else
		{
			if (code[i] < code[i+1])
			{
				mode = MIXED;
				break;
			}
		}
	}

	if (mode == ASC)
		printf("ascending\n");
	else if (mode == DESC)
		printf("descending\n");
	else
		printf("mixed\n");

	exit(0);
}
