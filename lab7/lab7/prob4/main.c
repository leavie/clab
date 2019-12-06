#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Enter phone number:");
    ch=getchar();
    //按照題目所規定的英文數字對照 印出來就對了
    while(ch!='\n'){
        if(ch=='A'||ch=='B'||ch=='C')
            ch='2';
        else if(ch=='D'||ch=='E'||ch=='F')
            ch='3';
        else if(ch=='G'||ch=='H'||ch=='I')
            ch='4';
        else if(ch=='J'||ch=='K'||ch=='L')
            ch='5';
        else if(ch=='M'||ch=='N'||ch=='O')
            ch='6';
        else if(ch=='P'||ch=='R'||ch=='S')
            ch='7';
        else if(ch=='V'||ch=='T'||ch=='U')
            ch='8';
        else if(ch=='W'||ch=='X'||ch=='Y')
            ch='9';
        printf("%c",ch);
        ch=getchar();
    }
    printf("\n");
    return 0;
}
