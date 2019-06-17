#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isAlpha(char ch);
int main()
{
    int tos=-1,x,y,i,j;
    char prefix[50],temp[50],op1[50],op2[50];
    printf("Enter prefix expression: ");
    scanf("%[^\n]",prefix);
    strrev(prefix);
    char **stack=(char**)malloc(30*sizeof(char*));
    for(i=0;i<=29;i++)
        stack[i]=(char*)calloc(30,sizeof(char));
    for(i=0;prefix[i]!='\0';i++)
    {
        if(isAlpha(prefix[i])==1)
        {
            tos++;
            stack[tos][0]=prefix[i];
            stack[tos][1]='\0';
        }
        else
        {
            strcpy(op1,stack[tos]);
            tos--;
            strcpy(op2,stack[tos]);
            tos--;
            x=0;
            for(j=0;j<=strlen(op1)-1;j++)
                temp[j]=op1[x++];
            x=0;
            y=j;
            for(j=y;j<=y+strlen(op2)-1;j++)
                temp[j]=op2[x++];
            temp[j]=prefix[i];
            temp[j+1]='\0';
            tos++;
            strcpy(stack[tos],temp);
        }
    }
    printf("\nPostfix expression: %s\n",stack[tos]);
    return 0;
}
int isAlpha(char ch)
{
    if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
        return 1;
    else
        return 0;
}
