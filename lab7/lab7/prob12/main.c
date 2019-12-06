#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Enter an expression:");
    ch=getchar();
    int count=0,point=10;
    float num,pre=0,sum=0,judge=0,now=0,flag=0;
    while(ch!='\n'){
        if(ch=='+'){//判斷遇到+號之前的運算符號是什麼 先做該運算符號的運算
            if(judge==1){//表示+號
                sum=pre+now;//sum做符號前後兩數運算
                pre=sum;//做完運算後要將sum變成前一個數(pre)繼續跟下一個數字運算
                now=0;//now歸0繼續記錄輸入的數字的值
            }
            else if(judge==2){//表示-號
                sum=pre-now;//sum做符號前後兩數運算
                pre=sum;//做完運算後要將sum變成前一個數(pre)繼續跟下一個數字運算
                now=0;//now歸0繼續記錄輸入的數字的值
            }
            else if(judge==3){//表示*號
                sum=pre*now;//sum做符號前後兩數運算
                pre=sum;//做完運算後要將sum變成前一個數(pre)繼續跟下一個數字運算
                now=0;//做完運算後要將sum變成前一個數(pre)繼續跟下一個數字運算
            }
            else if(judge==4){//表示/號
                sum=pre/now;//sum做符號前後兩數運算
                pre=sum;//做完運算後要將sum變成前一個數(pre)繼續跟下一個數字運算
                now=0;//now歸0繼續記錄輸入的數字的值
            }

            //printf("%f %f\n",pre,now);
            judge=1;//表示輸入的是+
            point=10;//point記錄小數點有幾位
            flag=0;//flag是否為小數點
            count++;//count計算輸入過幾次
        }
        //以下參考+號的註解
        else if(ch=='-'){
            if(judge==1){
                sum=pre+now;
                pre=sum;
                now=0;
            }
            else if(judge==2){
                sum=pre-now;
                pre=sum;
                now=0;
            }
            else if(judge==3){
                sum=pre*now;
                pre=sum;
                now=0;
            }
            else if(judge==4){
                sum=pre/now;
                pre=sum;
                now=0;
            }
             //printf("%f %f\n",pre,now);

            judge=2;
            flag=0;
            point=10;
            count++;
        }
        else if(ch=='*'){
             if(judge==1){
                sum=pre+now;
                pre=sum;
                now=0;
            }
            else if(judge==2){
                sum=pre-now;
                pre=sum;
                now=0;
            }
            else if(judge==3){
                sum=pre*now;
                pre=sum;
                now=0;
            }
            else if(judge==4){
                sum=pre/now;
                pre=sum;
                now=0;
            }
           //printf("%f %f\n",pre,now);
            judge=3;
            flag=0;
            point=10;
            count++;
        }
        else if(ch=='/'){
            if(judge==1){
                sum=pre+now;
                pre=sum;
                now=0;
            }
            else if(judge==2){
                sum=pre-now;
                pre=sum;
                now=0;
            }
            else if(judge==3){
                sum=pre*now;
                pre=sum;
                now=0;
            }
            else if(judge==4){
                sum=pre/now;
                pre=sum;
                now=0;
            }
            //printf("%f %f\n",pre,now);
            judge=4;
            flag=0;
            point=10;
            count++;
        }
        else if(ch=='.'){//如果是小數點
            point=10;//小數點從後一位開始
            flag=1;//之後要做小數點的運算
        }
        else {//這裡再做輸入數字的加總
            if(count==0){//count=0表示是第一次加總 都要加在pre上面
                if(flag==1){//小數點的加總
                    num=ch-'0';
                    pre=pre+num/point;
                    point*=10;//point*10表示小數點多一位
                }
                else {
                    num=ch-'0';//非小數
                    pre=pre*10+num;//直接*10運算
                    //printf("%lf",ch-'0');
                    //printf(" %f ",(float)num);
                    //printf("  %f\n",pre);
                }
            }
            else{//不是第一次則是用now開始運算
                if(flag==1){
                    num=ch-'0';
                    now=now+num/point;
                    point*=10;
                }
                else {
                    num=ch-'0';
                    now=now*10+num;
                }

            }
        }
        ch=getchar();

    }
    //跳出迴圈之後要做最後一次運算
    if(judge==0){
       // printf("%f %f\n",pre,now);
        sum=pre;
    }
    else if(judge==1){
       //  printf("%f %f\n",pre,now);
        sum=pre+now;
    }
    else if(judge==2){
        // printf("%f %f\n",pre,now);
        sum=pre-now;
    }
    else if(judge==3){
       //  printf("%f %f\n",pre,now);
        sum=pre*now;
    }
    else if(judge==4){
        // printf("%f %f\n",pre,now);
        sum=pre/now;
    }
    printf("%f",sum);
    return 0;
}
