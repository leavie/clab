#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX 100

struct node {
	int x;
	int y;
	struct node* prev;
	struct node* next;
};

typedef struct node Node;

Node* createNode(int r, int c);
Node* backTracking(int maze[][MAX], Node* head, int row, int col, bool visit[][MAX]);
bool canWalk(int maze[][MAX], int row, int col, int curRow, int curCol, bool visit[][MAX]);
void attach(Node* former, Node* newNode);

int main()
{
	int maze[MAX][MAX];
	bool visit[MAX][MAX];
	int row, col;
	Node* head = NULL;

	memset(maze, 0, sizeof(maze));
	memset(visit, false, sizeof(visit));

	printf("Please Enter the size of Maze: ");
	scanf("%d %d", &row, &col);

	while (1)
	{
		int wallRow, wallCol;
		printf("Please Enter the coordinate of Wall (-1 , -1 to end): ");
		scanf("%d %d", &wallRow, &wallCol);

		if (wallRow == -1 && wallCol == -1)
			break;

		maze[wallRow][wallCol] = 1;
	}

	head = backTracking(maze, head, row, col, visit);

	Node* temp = head;
	bool first = false;

	while (temp) 
	{
		if (first)
			printf(" -> ");
		
		first = true;

		printf("(%d %d)", temp->x, temp->y);

		temp = temp->next;
	}

	system("PAUSE");

	return 0;
}

Node* createNode(int r, int c)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->x = r, newNode->y = c;

	newNode->next = newNode->prev = NULL;

	return newNode;
}

Node* backTracking(int maze[][MAX], Node* head, int row, int col, bool visit[][MAX])
{
	int curRow, curCol;

	head = createNode(0, 0);
	visit[0][0] = true;

	Node* temp = head;

	while (temp)
	{
		curRow = temp->x, curCol = temp->y;

		if (curRow == row - 1 && curCol == col - 1)
			break;

		if (canWalk(maze, row, col, curRow - 1, curCol, visit))
		{
			Node* newNode = createNode(curRow - 1, curCol);

			visit[curRow - 1][curCol] = true;
			attach(temp, newNode);
			temp = temp->next;

			continue;
		}
		else if (canWalk(maze, row, col, curRow, curCol - 1, visit))
		{
			Node* newNode = createNode(curRow, curCol - 1);

			visit[curRow][curCol - 1] = true;
			attach(temp, newNode);
			temp = temp->next;

			continue;
		}
		else if (canWalk(maze, row, col, curRow + 1, curCol, visit))
		{
			Node* newNode = createNode(curRow + 1, curCol);

			visit[curRow + 1][curCol] = true;
			attach(temp, newNode);
			temp = temp->next;

			continue;
		}
		else if (canWalk(maze, row, col, curRow, curCol + 1, visit))
		{
			Node* newNode = createNode(curRow, curCol + 1);

			visit[curRow][curCol + 1] = true;
			attach(temp, newNode);
			temp = temp->next;

			continue;
		}
		else
		{
			Node* deleteNode = temp;

			temp = temp->prev, temp->next = NULL;

			free(deleteNode);

			continue;

		}
	}

	return head;
}

bool canWalk(int maze[][MAX], int row, int col, int curRow, int curCol, bool visit[][MAX])
{
	if (curRow<0 || curCol<0 || curRow>row - 1 || curCol>col - 1 || visit[curRow][curCol] || maze[curRow][curCol])
		return false;
	else
		return true;
}

void attach(Node* form, Node* newNode)
{
	form->next = newNode;
	newNode->prev = form;
	return;
}