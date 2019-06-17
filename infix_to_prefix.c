#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int prec(char ch);
int isAlpha(char ch);
int main()
{
    char infix[50],prefix[50],stack[50];
    int tos=-1,k=0,i;
    printf("Enter the infix expression: ");
    scanf("%[^\n]",infix);
    strrev(infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(isAlpha(infix[i])==1)
        {
            prefix[k]=infix[i];
            k++;
        }
        else
        {
            if(tos==-1)
            {
                tos++;
                stack[tos]=infix[i];
            }
            else
            {
                if(infix[i]==')' || stack[tos]==')')
                {
                    tos++;
                    stack[tos]=infix[i];
                }
                else if(infix[i]=='(')
                {
                    while(stack[tos]!=')')
                    {
                        prefix[k]=stack[tos];
                        k++;
                        tos--;
                    }
                    tos--;
                }
                else if(prec(infix[i])>=prec(stack[tos]))
                {
                    tos++;
                    stack[tos]=infix[i];
                }
                else
                {
                    while(stack[tos]!=')')
                    {
                        if(prec(infix[i])<prec(stack[tos]))
                        {
                            prefix[k]=stack[tos];
                            k++;
                            tos--;
                            if(tos==-1)
                                break;
                        }
                        else
                            break;
                    }
                    tos++;
                    stack[tos]=infix[i];
                }
            }
        }
    }
    while(tos!=-1)
    {
        prefix[k]=stack[tos];
        k++;
        tos--;
    }
    prefix[k]='\0';
    strrev(prefix);
    printf("\nPrefix expression: %s\n",prefix);
    return 0;
}
int prec(char ch)
{
    switch(ch)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            printf("\nUnsupported operators used!\n");
            exit(0);
    }
}
int isAlpha(char ch)
{
    if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
        return 1;
    else
        return 0;
}
