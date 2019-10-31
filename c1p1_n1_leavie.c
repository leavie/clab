#include <stdio.h>
int prev = -1;
int count = 0;
int input;
int main(void) {
scanf("%d", &input);
while (input >= 0 ) {
  if (input < prev) {
    count += 1;
  }
  prev = input;
  scanf("%d", &input);
}
printf("count=%d\n", count);
return 0;
}
