#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int data[1001] = {0, };
	int dp[1001] = {0, };
	int count, answer = 0;

	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < count; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < count; j++)
		{
			if (data[i] > data[j]) {
				dp[i] = (dp[j]+1 > dp[i]) ? dp[j]+1 : dp[i];
			}
		}
		answer = (dp[i] > answer) ? dp[i] : answer;
	}

	printf("%d\n", answer);
	exit(0);
}
