#include <stdio.h>

int main() {
//printf("%d", isValid('@')); // valid or valid that is a question.
char ch;
int freq[128] = {0};
while ((ch=getchar())!='\n') {
    freq[ch]++;
}

int odd_freq = 0; // 奇數出現的次數
for(int i=0;i<128;i++) {
    if (isValid(i) && freq[i] % 2 == 1 && (++odd_freq > 1)) { // 奇數出現的次數超過1次, 印出impossible, 結束程式
        puts("impossible.");
        return 0;
    }
}

// 左至右印出偶數次數的元素每個元素只印一半次數
for(int i=0;i<128;i++) {
    if (isValid(i) && freq[i] > 0) {
        if(freq[i] % 2 == 0) {
            for(int f=0;f<freq[i]/2;f++) {
                printf("%c",i);
            }
        }
    }
}

// 印出奇數次數的元素
for(int i=0;i<128;i++) {
    if (isValid(i) && freq[i] > 0) {
        if(freq[i] % 2 == 1) {
            for(int f=0;f<freq[i];f++) {
                printf("%c",i);
            }
        }
    }
}

// 右至左印出偶數次數的元素 每個元素印完另一半
for(int i=127;i>=0;i--) {
    if (isValid(i) && freq[i] > 0) {
        if(freq[i] % 2 == 0) {
            for(int f=0;f<freq[i]/2;f++) {
                printf("%c",i);
            }
        }
    }
}

return 0;
}

int isValid(int i) {
    return 'a' <= i && i <= 'z' ||  'A' <= i && i <= 'Z' || '0' <= i && i <= '9';
}
