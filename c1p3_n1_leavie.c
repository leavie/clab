#include <stdio.h>

int factor(int n) {
int ret = 2;
while (n % ret++);
return ret-1;
}

int main(void)
{
    int number;
    printf("enter the number:");
    scanf("%d",&number);
    printf("the answer is %d",factor(number));
    return 0;
}
