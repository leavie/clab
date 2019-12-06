#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,n;
    double x,y;
    double xSum=0,ySum=0,xySum=0,xxSum=0;//分別紀錄x,y,x平方,xy總和
    scanf("%d",&n);//紀錄有幾組資料
    N=n;//之後還要用到N 所以先存起來
    while(n--){
        scanf("%lf %lf",&x,&y);
        xSum+=x;//加總x
        ySum+=y;//加總y
        xySum=xySum+x*y;//加總xy
        xxSum=xxSum+x*x;//加總x平方
    }
    double c1,c2,c3,c5,c6;
    /*
    an->c1;
    b總和x->c2;
    總和y->c3
    b總和x平方->c5
    總和xy->c6
    */
    //我們將兩個方程式的第一項變成相同系數讓其被消除
    //所以後面幾項都要同乘與一樣的數
    c1=N*xSum;
    //c4=xSum*N;
    c2=xSum*xSum;
    c5=xxSum*N;
    c3=ySum*xSum;
    c6=xySum*N;
    //printf("%lf %lf %lf %lf %lf",c1,c2,c5,c3,c6);
    double a,b;
    if((c5-c2)==0) printf("No answer\n");
    else{
        b=(c6-c3)/(c5-c2);//a的那項以先消除 所以先算b
        a=(c3-b*c2)/c1;//把b代回第一式解a
        printf("%lf %lf\n",a,b);
    }
    return 0;
}
