#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double L;//L輸入的斜邊長
    double high=1,low=0,half=0.5,flag=1;
    /*二分法high從1開始 low從0開始 half 是high+low的中間值
    開始往內逼近 若值大於0 則表示所要的答案在half右邊
    就要把half變成low繼續逼近
    相反就是在左邊 要把half變成high繼續逼近
    */
    scanf("%lf",&L);
   // printf("%lf\n",half);
    while(flag>=0.000001||flag<=-0.000001){//flag要趨近於0才結束
        half=(high+low)/2;
         //printf("%lf\n",half);
        flag=pow(half,4)+2*pow(half,3)+(2-L*L)*pow(half,2)+2*half+1;//算出的方程式
        //printf("%lf\n",flag);
        if(flag>0){
            low=half;
        }
        else high=half;
    }
    printf("%lf\n",half);
    return 0;
}
