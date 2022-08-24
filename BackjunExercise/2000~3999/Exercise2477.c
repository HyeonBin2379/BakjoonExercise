#include <stdio.h>
#include <stdlib.h>

typedef struct length
{
	int dir;
	int len;
} Length;

int main(void)
{
	int unit, area, subArea;
	int max[2] = {0, 0};	// 0번: 가로, 1번: 세로
	int maxRow = 0, maxCol = 0;
	Length hex[6];

	scanf("%d", &unit);
	for (int i = 0; i < 6; i++)
	{
		scanf("%d%d", &hex[i].dir, &hex[i].len);

		if (hex[i].dir < 3) {
			if (hex[i].len > max[0])
			{
				max[0] = hex[i].len;
				maxRow = i;
			}
		}
		else {
			if (hex[i].len > max[1])
			{
				max[1] = hex[i].len;
				maxCol = i;
			}
		}
	}

	area = hex[maxRow].len*hex[maxCol].len;
	subArea = abs(hex[(maxRow+5) % 6].len - hex[(maxRow+7) % 6].len)
			* abs(hex[(maxCol+5) % 6].len - hex[(maxCol+7) % 6].len);

	printf("%d\n", (area-subArea) * unit);
	exit(0);
}
