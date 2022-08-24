#include <stdio.h>
#include <stdlib.h>

typedef struct tagPos
{
	int x;
	int y;
} Pos;

int maze[101][101] = {0, };
Pos direct[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1} };
Pos queue[10001];

int bfs(int row, int col)
{
	int front = 0, rear = 0;

	queue[front].x = 1;	// x좌표
	queue[front].y = 1;	// y좌표
	rear++;

	while (front < rear)
	{
		int x = queue[front].x;
		int y = queue[front].y;
		front++;

		// 상하좌우이동
		for (int i = 0; i < 4; i++)
		{
			int newX = x + direct[i].x;
			int newY = y + direct[i].y;

			if (newX < 1 || newY < 1 || newX > row || newY > col)
				continue;

			if (maze[newX][newY] != 1)
				continue;

			maze[newX][newY] = maze[x][y] + 1;

			queue[rear].x = newX;
			queue[rear].y = newY;
			rear++;
		}
	}

	return maze[row][col];
}
int main(void)
{
	int row, col;
	int i, j, ans;

	scanf("%d %d", &row, &col);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
			scanf("%1d", &maze[i][j]);
	}

	ans = bfs(row, col);

	printf("%d\n", ans);
	exit(0);
}
