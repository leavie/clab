#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float num;//��J����
    float y=1,xDivy,avg;//y�q1�}�l xDivy->x/y avg->y��x/y��������
    printf("Enter a positive number:");
    scanf("%f",&num);
    while(1){
        xDivy=num/y;
        avg=(y+xDivy)/2;
        if(fabs(avg-y)<0.00001*y) break;//�p�G�ŦX�D�سW�w�N����
        y=avg;//�S�����~�� y�N�ܦ��s���� �Y��avg
    }
    printf("%f\n",avg);
    return 0;
}
