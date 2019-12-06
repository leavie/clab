#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float num;//輸入的數
    float y=1,xDivy,avg;//y從1開始 xDivy->x/y avg->y跟x/y的平均值
    printf("Enter a positive number:");
    scanf("%f",&num);
    while(1){
        xDivy=num/y;
        avg=(y+xDivy)/2;
        if(fabs(avg-y)<0.00001*y) break;//如果符合題目規定就停止
        y=avg;//沒停止繼續做 y就變成新的值 即為avg
    }
    printf("%f\n",avg);
    return 0;
}
