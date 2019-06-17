#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isAlpha(char ch);
int main()
{
    int tos=-1,x,y,i,j;
    char postfix[50],temp[50],op1[50],op2[50];
    printf("Enter postfix expression: ");
    scanf("%[^\n]",postfix);
    char **stack=(char**)malloc(30*sizeof(char*));
    for(i=0;i<=29;i++)
        stack[i]=(char*)calloc(30,sizeof(char));
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isAlpha(postfix[i])==1)
        {
            tos++;
            stack[tos][0]=postfix[i];
            stack[tos][1]='\0';
        }
        else
        {
            strcpy(op2,stack[tos]);
            tos--;
            strcpy(op1,stack[tos]);
            tos--;
            temp[0]=postfix[i];
            x=0;
            for(j=1;j<=strlen(op1);j++)
                temp[j]=op1[x++];
            x=0;
            y=j;
            for(j=y;j<=y+strlen(op2)-1;j++)
                temp[j]=op2[x++];
            temp[j]='\0';
            tos++;
            strcpy(stack[tos],temp);
        }
    }
    printf("\nPrefix expression: %s\n",stack[tos]);
    return 0;
}
int isAlpha(char ch)
{
    if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
        return 1;
    else
        return 0;
}
