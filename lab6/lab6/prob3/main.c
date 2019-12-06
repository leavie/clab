#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);//紀錄分數
    int ans;
    int up=1,down=1,flag=0;//up分子 down分母 flag交換時的暫存
    up=b;
    down=a;
    while(down!=1){
        //if(up==0) break;
        ans=up/down;//ans 把要印的數字設為ans 即為up/down的答案
        up=up-down*ans;//剩下的up變成原本的up減去算出的ans*down
        if(up==0) break;//up 變0表示整除 結束 若都不能整除 就表示最後down會是1
        //以下做up down 交換 繼續下一次的計算
        flag=up;
        up=down;
        down=flag;
        //printf("up: %d\n",up);
        //printf("down: %d\n",down);
        printf("%d\n",ans);
    }
    if(up!=0)//若不整除 則要印最後的up
        printf("%d\n",up);
    else printf("%d\n",down);//反之印最後down
    return 0;
}
