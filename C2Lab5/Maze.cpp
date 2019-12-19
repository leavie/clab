#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX 100

struct maze {
	int row;
	int col;
	int prevIndex;
};

typedef maze BFS;
void Bfs(int maze[][MAX], BFS bfs[], int row, int col, bool visit[][MAX]);
bool checkCanWalk(int maze[][MAX], int row, int col, int i, int j, bool visit[][MAX]);
void clear(BFS bfs[], int size);
int addInArray(BFS bfs[], int r, int c, int pIdx);

/*
	visit[][]:
		0 = 未被探索
		1 = 已探索
*/

int main()
{
	int row, col;
	int maze[MAX][MAX];
	bool visit[MAX][MAX];

	scanf("%d %d", &row, &col);

	memset(maze, 0, sizeof(maze));
	memset(visit, false, sizeof(visit));

	BFS arr[MAX * MAX];

	clear(arr, row * col);

	int wallRow, wallCol;

	while (1)
	{
		scanf("%d %d", &wallRow, &wallCol);

		if (wallRow == -1 && wallCol == -1)
			break;

		maze[wallRow][wallCol] = 1;
	}

	Bfs(maze, arr, row, col, visit);

	bool first = false;


	for (int i = row*col-1; i >= 0 ; i--)
	{
		if (arr[i].row == row - 1 && arr[i].col == col - 1) 
		{
			while (arr[i].prevIndex != -1) 
			{
				if (first)
					printf(" -> ");

				first = true;

				printf("%d %d", arr[i].row, arr[i].col);
				
				i = arr[i].prevIndex;
			}

			printf("%d %d", arr[i].row, arr[i].col);
		}
	}


}

void Bfs(int maze[][MAX], BFS bfs[], int row, int col, bool visit[][MAX])
{
	int nowIndex = 1, curRow, curCol, prevIndex = -1;

	// 起點
	bfs[0].row = 0, bfs[0].col = 0, bfs[0].prevIndex = -1;
	visit[0][0] = true;

	for (int i = 0; i < row * col; i++)
	{
		if (bfs[i].row == row - 1 && bfs[i].col == col - 1)
			break;

		// 更新起點
		curRow = bfs[i].row, curCol = bfs[i].col;

		// 當能上下左右移動且尚未遍歷時 將可以移動的點放入陣列
		while (checkCanWalk(maze, row, col, curRow - 1, curCol, visit) || checkCanWalk(maze, row, col, curRow, curCol - 1, visit) || checkCanWalk(maze, row, col, curRow + 1, curCol, visit) || checkCanWalk(maze, row, col, curRow, curCol + 1, visit))
		{
			int temp;

			if (checkCanWalk(maze, row, col, curRow - 1, curCol, visit))
			{
				temp = addInArray(bfs, curRow - 1, curCol, i);
				visit[curRow - 1][curCol] = true;
			}

			if (checkCanWalk(maze, row, col, curRow, curCol - 1, visit))
			{
				temp = addInArray(bfs, curRow, curCol - 1, i);
				visit[curRow][curCol - 1] = true;
			}

			if (checkCanWalk(maze, row, col, curRow + 1, curCol, visit))
			{
				temp = addInArray(bfs, curRow + 1, curCol, i);
				visit[curRow + 1][curCol] = true;
			}

			if (checkCanWalk(maze, row, col, curRow, curCol + 1, visit))
			{
				temp = addInArray(bfs, curRow, curCol + 1, i);
				visit[curRow][curCol + 1] = true;
			}
		}
	}

}

bool checkCanWalk(int maze[][MAX], int row, int col, int i, int j, bool visit[][MAX])
{
	if (i < 0 || j < 0 || i >= row || j >= col || maze[i][j] == 1 || visit[i][j])
		return false;
	else
		return true;

}

void clear(BFS bfs[], int size)
{
	for (int i = 0; i < size; i++)
	{
		bfs[i].row = -1;
		bfs[i].col = -1;
		bfs[i].prevIndex = -1;
	}
}

int addInArray(BFS bfs[], int r, int c, int pIdx)
{
	int i = 1;
	while (bfs[i].row != -1 && bfs[i].col != -1 && bfs[i].prevIndex != -1)
		i++;

	bfs[i].row = r, bfs[i].col = c, bfs[i].prevIndex = pIdx;
	return i;
}