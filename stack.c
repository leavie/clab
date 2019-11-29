#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char *data;
    struct Node *link;
}Node;

typedef struct
{
    Node *top;
}Stack;


Stack createStack(void)
{
    Stack stk;

    stk.top = NULL;
    return stk;
}

int emptyStack(Stack stk)
{
    if (stk.top == NULL)
        return 1;
    else
        return 0;
}

void push(Stack *stk, char *str)
{
    Node *nd = malloc(sizeof(Node));
    char *strg;

    strg = malloc(strlen(str)+1);
    strcpy(strg, str);
    nd->data = strg;
    nd->link = stk->top;
    stk->top = nd;
}

char * pop(Stack *stk)
{
    char *strg;
    Node *temp;

    strg = malloc(strlen(stk->top->data)+1);
    strcpy(strg, stk->top->data);

    temp = stk->top;
    stk->top = stk->top->link;
    free(temp->data);
    free(temp);

    return strg;

}

int main(void)
{
    Stack stack;

    stack = createStack();
    push(&stack, "This is a demo of the operations on a stack.");
    push(&stack, "Please pay attention to the details of the operations.");
    push(&stack, "Finally, I hope you understand the code.");

    while(!emptyStack(stack))
      printf("%s\n", pop(&stack));

    return 0;

}
