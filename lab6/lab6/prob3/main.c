#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);//��������
    int ans;
    int up=1,down=1,flag=0;//up���l down���� flag�洫�ɪ��Ȧs
    up=b;
    down=a;
    while(down!=1){
        //if(up==0) break;
        ans=up/down;//ans ��n�L���Ʀr�]��ans �Y��up/down������
        up=up-down*ans;//�ѤU��up�ܦ��쥻��up��h��X��ans*down
        if(up==0) break;//up ��0��ܾ㰣 ���� �Y������㰣 �N��̫ܳ�down�|�O1
        //�H�U��up down �洫 �~��U�@�����p��
        flag=up;
        up=down;
        down=flag;
        //printf("up: %d\n",up);
        //printf("down: %d\n",down);
        printf("%d\n",ans);
    }
    if(up!=0)//�Y���㰣 �h�n�L�̫᪺up
        printf("%d\n",up);
    else printf("%d\n",down);//�Ϥ��L�̫�down
    return 0;
}
