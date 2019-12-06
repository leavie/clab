#include <stdio.h>



int main() {

int a[128];


for(int i=0;i<128;i++) {
    a[i]=0;
}

char c;
while(scanf("%c", &c)&&c!='\n') {
    a[c]++;
}

while(scanf("%c", &c)&&c!='\n') {
    a[c]--;
}

for(int i=0;i<128;i++) {
    if (a[i] !=0) {
        puts("not an anagram");
        return 0;
    }
}

puts("an anagram");
return 0;
}
