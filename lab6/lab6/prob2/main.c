#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double L;//L��J�������
    double high=1,low=0,half=0.5,flag=1;
    /*�G���khigh�q1�}�l low�q0�}�l half �Ohigh+low��������
    �}�l�����G�� �Y�Ȥj��0 �h��ܩҭn�����צbhalf�k��
    �N�n��half�ܦ�low�~��G��
    �ۤϴN�O�b���� �n��half�ܦ�high�~��G��
    */
    scanf("%lf",&L);
   // printf("%lf\n",half);
    while(flag>=0.000001||flag<=-0.000001){//flag�n�ͪ��0�~����
        half=(high+low)/2;
         //printf("%lf\n",half);
        flag=pow(half,4)+2*pow(half,3)+(2-L*L)*pow(half,2)+2*half+1;//��X����{��
        //printf("%lf\n",flag);
        if(flag>0){
            low=half;
        }
        else high=half;
    }
    printf("%lf\n",half);
    return 0;
}
