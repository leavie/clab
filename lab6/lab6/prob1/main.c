#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,n;
    double x,y;
    double xSum=0,ySum=0,xySum=0,xxSum=0;//���O����x,y,x����,xy�`�M
    scanf("%d",&n);//�������X�ո��
    N=n;//�����٭n�Ψ�N �ҥH���s�_��
    while(n--){
        scanf("%lf %lf",&x,&y);
        xSum+=x;//�[�`x
        ySum+=y;//�[�`y
        xySum=xySum+x*y;//�[�`xy
        xxSum=xxSum+x*x;//�[�`x����
    }
    double c1,c2,c3,c5,c6;
    /*
    an->c1;
    b�`�Mx->c2;
    �`�My->c3
    b�`�Mx����->c5
    �`�Mxy->c6
    */
    //�ڭ̱N��Ӥ�{�����Ĥ@���ܦ��ۦP�t������Q����
    //�ҥH�᭱�X�����n�P���P�@�˪���
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
        b=(c6-c3)/(c5-c2);//a�������H������ �ҥH����b
        a=(c3-b*c2)/c1;//��b�N�^�Ĥ@����a
        printf("%lf %lf\n",a,b);
    }
    return 0;
}
