#include <stdio.h>

int main(void) {
	int m;
	int n,l;
	scanf("%d\n",&m);
	while(m--){
	    scanf("%d",&n);
	    while(n--) {
	        scanf("%d%",&l);
	        printf("%d", l);
	    }
	    printf("\n");
	}
	return 0;
}
