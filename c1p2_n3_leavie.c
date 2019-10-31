#include <stdio.h>
int main() {


int sum = 0; // ans
int n; // number
int i = 1; // times of  increment one
int t = 1; // times of next selected number
int k = 1;
scanf("%d", &n);
while (n >= 0){
        printf("i=%d,t=%d,k=%d\n",i,t,k);
        if (i == t) {
            sum += n;
            k += 1;
            t += k;
        }

        i += 1;
        scanf("%d", &n);

}
printf("sum=%d\n",sum);
}
