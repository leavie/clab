#include <stdio.h>
int main() {
	int n; // number to be read
	int p = -1; // previous read number
	int max = 0; // max length
	int len = 0; // current length
	scanf("%d",&n);
	while (n>=0) {
		if ( n > p) {
			len += 1;
		} else {
			len = 1;
		}
		if (len > max) {
				max = len;
		}
		p = n;
		scanf("%d",&n);
	}
	printf("max=%d",max);
	return 0;
}

