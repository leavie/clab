#include <stdio.h>
int max=-1, smax=-1;
int min=9999, smin=9999;
int input;
int main(void) {
  scanf("%d", &input);
  while (input >= 0) {
    if (input > max) {
      smax = max;
      max = input;
    } else if (input > smax) {
      smax = input;
    }
    if (input < min) {
      smin = min;
      min = input;
    } else if (input < smin) {
      smin = input;
    }
    scanf("%d", &input);
  }
  printf("smax=%d,smin=%d\n", smax,smin);
  return 0;
}
