#include<stdio.h>
#include<stdlib.h>
int prec(char ch);
int isAlpha(char ch);
int main()
{
    char infix[50],postfix[50],stack[50];
    int k=0,tos=-1,i;
    printf("Enter the infix expression: ");
    scanf("%[^\n]",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(isAlpha(infix[i])==1)
        {
            postfix[k]=infix[i];
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
                if(infix[i]=='(' || stack[tos]=='(')
                {
                    tos++;
                    stack[tos]=infix[i];
                }
                else if(infix[i]==')')
                {
                    while(stack[tos]!='(')
                    {
                        postfix[k]=stack[tos];
                        k++;
                        tos--;
                    }
                    tos--;
                }
                else if(prec(infix[i])>prec(stack[tos]))
                {
                    tos++;
                    stack[tos]=infix[i];
                }
                else
                {
                    while(stack[tos]!='(')
                    {
                        if(prec(stack[tos])>=prec(infix[i]))
                        {
                            postfix[k]=stack[tos];
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
        postfix[k]=stack[tos];
        k++;
        tos--;
    }
    postfix[k]='\0';
    printf("\nPotsfix expression: %s\n",postfix);
    return 0;
}
int prec(char ch)
{
    switch(ch)
    {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            printf("\nInfix expression involves unsupported operators!\n");
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
