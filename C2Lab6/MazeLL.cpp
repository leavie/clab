#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX 100

struct maze {
	int row;
	int col;
	struct maze* prevPosition;
	struct maze* next;
};

typedef maze BFS;
BFS* Bfs(int maze[][MAX], BFS* head, int row, int col, bool visit[][MAX]);
bool checkCanWalk(int maze[][MAX], int row, int col, int i, int j, bool visit[][MAX]);
void addInLL(BFS* tail, BFS* prevPosition, BFS* addPtr);
BFS* createNode(int row, int col);

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

	printf("Please Enter the size of Maze: ");
	scanf("%d %d", &row, &col);

	memset(maze, 0, sizeof(maze));
	memset(visit, false, sizeof(visit));

	BFS* head = NULL;
	BFS* tail = NULL;

	int wallRow, wallCol;

	while (1)
	{
		printf("Please Enter the coordinate of Wall (-1, -1 to end): ");
		scanf("%d %d", &wallRow, &wallCol);

		if (wallRow == -1 && wallCol == -1)
			break;

		maze[wallRow][wallCol] = 1;
	}

	tail = Bfs(maze, head, row, col, visit);

	bool first = false;

	while (tail) 
	{
		if (first)
			printf(" <- ");
		first = true;
		printf("(%d %d)", tail->row, tail->col);
		tail = tail->prevPosition;
	}

}

BFS* Bfs(int maze[][MAX], BFS* head, int row, int col, bool visit[][MAX])
{
	int nowIndex = 1, curRow, curCol, prevIndex = -1;
	BFS* tail;

	head = createNode(0, 0);
	tail = head;
	// 起點

	visit[0][0] = true;

	while (head != NULL)
	{
		curRow = head->row, curCol = head->col;
		// 更新起點

		// 當能上下左右移動且尚未遍歷時 將可以移動的點放入陣列
		while (checkCanWalk(maze, row, col, curRow - 1, curCol, visit) || checkCanWalk(maze, row, col, curRow, curCol - 1, visit) || checkCanWalk(maze, row, col, curRow + 1, curCol, visit) || checkCanWalk(maze, row, col, curRow, curCol + 1, visit))
		{
			BFS* temp = NULL;

			if (checkCanWalk(maze, row, col, curRow - 1, curCol, visit))
			{
				temp = createNode(curRow - 1, curCol);
				addInLL(tail, head, temp);
				visit[curRow - 1][curCol] = true;
				tail = temp;
			}

			if (checkCanWalk(maze, row, col, curRow, curCol - 1, visit))
			{
				temp = createNode(curRow, curCol - 1);
				addInLL(tail, head, temp);
				visit[curRow][curCol - 1] = true;
				tail = temp;
			}

			if (checkCanWalk(maze, row, col, curRow + 1, curCol, visit))
			{
				temp = createNode(curRow + 1, curCol);
				addInLL(tail, head, temp);
				visit[curRow + 1][curCol] = true;
				tail = temp;
			}

			if (checkCanWalk(maze, row, col, curRow, curCol + 1, visit))
			{
				temp = createNode(curRow, curCol + 1);
				addInLL(tail, head, temp);
				visit[curRow][curCol + 1] = true;
				tail = temp;
			}

		}

		head = head->next;
	}

	return tail;
}

bool checkCanWalk(int maze[][MAX], int row, int col, int i, int j, bool visit[][MAX])
{
	if (i < 0 || j < 0 || i >= row || j >= col || maze[i][j] == 1 || visit[i][j])
		return false;
	else
		return true;

}

void addInLL(BFS* tail, BFS* prevPosition, BFS* addPtr)
{
	tail->next = addPtr;
	addPtr->prevPosition = prevPosition;

	return;
}

BFS* createNode(int row, int col)
{
	BFS* newNode = (BFS*)malloc(sizeof(BFS));
	newNode->row = row;
	newNode->col = col;

	newNode->next = newNode->prevPosition = NULL;

	return newNode;
}