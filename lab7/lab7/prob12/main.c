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
        if(ch=='+'){//�P�_�J��+�����e���B��Ÿ��O���� �����ӹB��Ÿ����B��
            if(judge==1){//���+��
                sum=pre+now;//sum���Ÿ��e���ƹB��
                pre=sum;//�����B���n�Nsum�ܦ��e�@�Ӽ�(pre)�~���U�@�ӼƦr�B��
                now=0;//now�k0�~��O����J���Ʀr����
            }
            else if(judge==2){//���-��
                sum=pre-now;//sum���Ÿ��e���ƹB��
                pre=sum;//�����B���n�Nsum�ܦ��e�@�Ӽ�(pre)�~���U�@�ӼƦr�B��
                now=0;//now�k0�~��O����J���Ʀr����
            }
            else if(judge==3){//���*��
                sum=pre*now;//sum���Ÿ��e���ƹB��
                pre=sum;//�����B���n�Nsum�ܦ��e�@�Ӽ�(pre)�~���U�@�ӼƦr�B��
                now=0;//�����B���n�Nsum�ܦ��e�@�Ӽ�(pre)�~���U�@�ӼƦr�B��
            }
            else if(judge==4){//���/��
                sum=pre/now;//sum���Ÿ��e���ƹB��
                pre=sum;//�����B���n�Nsum�ܦ��e�@�Ӽ�(pre)�~���U�@�ӼƦr�B��
                now=0;//now�k0�~��O����J���Ʀr����
            }

            //printf("%f %f\n",pre,now);
            judge=1;//��ܿ�J���O+
            point=10;//point�O���p���I���X��
            flag=0;//flag�O�_���p���I
            count++;//count�p���J�L�X��
        }
        //�H�U�Ѧ�+��������
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
        else if(ch=='.'){//�p�G�O�p���I
            point=10;//�p���I�q��@��}�l
            flag=1;//����n���p���I���B��
        }
        else {//�o�̦A����J�Ʀr���[�`
            if(count==0){//count=0��ܬO�Ĥ@���[�` ���n�[�bpre�W��
                if(flag==1){//�p���I���[�`
                    num=ch-'0';
                    pre=pre+num/point;
                    point*=10;//point*10��ܤp���I�h�@��
                }
                else {
                    num=ch-'0';//�D�p��
                    pre=pre*10+num;//����*10�B��
                    //printf("%lf",ch-'0');
                    //printf(" %f ",(float)num);
                    //printf("  %f\n",pre);
                }
            }
            else{//���O�Ĥ@���h�O��now�}�l�B��
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
    //���X�j�餧��n���̫�@���B��
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
