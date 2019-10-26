#include <stdio.h>
int main() {
	double  sum = 0;
	double k = 1;
		for(int i=0; i < 8; i++) {
			double  t = k / (2*i + 1);
			sum += t;
			k *= -1;
	}
	printf("pi=%lf",sum*4);
	return 0;
}
