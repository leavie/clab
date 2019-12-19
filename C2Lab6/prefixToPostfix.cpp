#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

struct node {
	char* data;
	struct node* next;
};

struct stack {
	struct node* top;
	int amount;
};

typedef struct node Node;
typedef struct stack Stack;

void inputToLL(Node** LL, char* input);
Node* createNewNode(char* input);
Stack createStack();
void push(Stack* stack, char* input);
bool isEmpty(Stack* stack);
char* pop(Stack* stack);
void preToPost(Node* LL);

int main()
{
	Node* LL = NULL;

	char input[MAX], c;

	printf("Please enter prefix (use space to separate): \n");
	while (1)
	{
		scanf("%s%c", input, &c);

		inputToLL(&LL, input);

		if (c == '\n')
			break;
	}

	preToPost(LL);
	system("PAUSE");

	return 0;
}

void inputToLL(Node** LL, char* input)
{

	Node* newNode = createNewNode(input);

	if (*LL == NULL)
	{
		*LL = newNode;
		return;
	}
	else
	{
		newNode->next = *LL;
		*LL = newNode;
		return;
	}

}

Node* createNewNode(char* input)
{
	Node* temp = malloc(sizeof(Node));
	char* strg = malloc(strlen(input) + 1);

	strcpy(strg, input);

	temp->data = strg;
	temp->next = NULL;

	return temp;
}

Stack createStack()
{
	Stack temp;

	temp.top = NULL;
	temp.amount = 0;
	return temp;
}

void push(Stack* stack, char* input)
{
	Node* newNode = createNewNode(input);

	if (stack->top == NULL)
		stack->top = newNode;
	else
	{
		newNode->next = stack->top;
		stack->top = newNode;
	}
	stack->amount++;
}

bool isEmpty(Stack* stack)
{
	return stack->top == NULL || stack->amount == 0;
}

char* pop(Stack* stack)
{
	if (!isEmpty(stack))
	{
		char* output;

		output = malloc(strlen(stack->top->data) + 1);
		strcpy(output, stack->top->data);

		Node* remove = stack->top;

		stack->top = stack->top->next;
		free(remove->data);
		free(remove);
		stack->amount--;
		return output;
	}
	else
		return NULL;


}

void preToPost(Node* LL)
{
	Stack stack = createStack();
	Node* temp = LL;

	while (temp != NULL)
	{
		if (!strcmp(temp->data, "+") || !strcmp(temp->data, "-") || !strcmp(temp->data, "*") || !strcmp(temp->data, "/"))
		{
			char* first, * second;
			first = pop(&stack);
			second = pop(&stack);

			if (first && second)
			{
				char* cat = malloc(sizeof(strlen(first) + strlen(second) + strlen(temp->data) + 1));
				strcpy(cat, first);
				strcat(cat, second);
				strcat(cat, temp->data);

				push(&stack, cat);


				free(first);
				free(second);
				first = NULL, second = NULL;
			}
		}
		else
			push(&stack, temp->data);

		temp = temp->next;
	}

	if (stack.amount == 1) 
	{
		printf("The postfix is:\n");
		printf("%s\n", stack.top->data);
	}
	else
		printf("Wrong prefix format!\n");
}
