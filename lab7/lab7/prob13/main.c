#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    float count=0,time=0;
    float sum=0;
    printf("Enter a sentence:");
    ch=getchar();
    while(ch!='\n'){
        if(ch!=' '){//不是空白 表示要繼續計算該字的長度
            count++;//所以累加count
            //printf("a\n");
        }
        else{//讀到空白表示字結束 開始計算有幾個字了(time) 加總目前長度(sum) count變為0繼續下個字長度計算
            time++;
            sum+=count;
            count=0;
           // printf("b\n");
            //printf("%f %f %f\n",sum,count,time);
        }
        ch=getchar();
    }
    time++;//跳出迴圈後要計算最後一次
    sum+=count;
    printf("Average word length: %.1f",sum/time);
    return 0;
}
