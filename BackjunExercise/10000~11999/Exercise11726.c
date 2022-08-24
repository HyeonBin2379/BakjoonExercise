#include <stdio.h>
#include <stdlib.h>

// 1904번과 본질적으로 동일
// 00타일 = 2x1 타일 사용 시 반드시 짝수개 단위로 사용,
//	    엇갈리게 배치 불가

long long fib[1000001] = {0, };

int main(void)
{
	int input;
	long long answer = 0;

	scanf("%d", &input);
	fib[0] = 1 % 10007;
	fib[1] = 1 % 10007;

	for (int i = 2; i <= input; i++)
	{
		// 가장 왼쪽부터 타일 배치
		// 1x2 타일부터 배치하는 경우 + 2x1 타일부터 배치하는 경우
		fib[i] = (fib[i-1] % 10007) + (fib[i-2] % 10007);
		fib[i] %= 10007;
	}

	answer = fib[input];
	printf("%lld\n", answer);
	exit(0);
}
