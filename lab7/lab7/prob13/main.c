#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    float count=0,time=0;
    float sum=0;
    printf("Enter a sentence:");
    ch=getchar();
    while(ch!='\n'){
        if(ch!=' '){//���O�ť� ��ܭn�~��p��Ӧr������
            count++;//�ҥH�֥[count
            //printf("a\n");
        }
        else{//Ū��ťժ�ܦr���� �}�l�p�⦳�X�Ӧr�F(time) �[�`�ثe����(sum) count�ܬ�0�~��U�Ӧr���׭p��
            time++;
            sum+=count;
            count=0;
           // printf("b\n");
            //printf("%f %f %f\n",sum,count,time);
        }
        ch=getchar();
    }
    time++;//���X�j���n�p��̫�@��
    sum+=count;
    printf("Average word length: %.1f",sum/time);
    return 0;
}
