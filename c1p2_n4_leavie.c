#include <stdio.h>
int main() {
int s;

int constant = 1;
int i = 1;
int coef = 2;


scanf("%d", &s);
while (constant < s){
    if ((s - constant) % coef == 0) {
        printf("coef=%d, constant=%d\n", coef, constant);
    }
    i += 1;
    constant += i;
    coef += 1;
}
}
