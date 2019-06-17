#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define blankInt 111
#define blankChar '#'
int main()
{
    int Operand[50];
    float stack[50];
    char Operator[50];
    int i,n,ch,tos=-1,j;
    float op1,op2,x;
    printf("Enter the size of prefix expression: ");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        printf("\n1.Operand\n2.Operator\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the operand: ");
                scanf("%d",&Operand[i]);
                Operator[i]=blankChar;
                break;
            case 2:
                printf("Enter the operator: ");
                scanf("%*c%c",&Operator[i]);
                Operand[i]=blankInt;
                break;
            default:
                printf("Invalid choice: ");
                i--;
                break;
        }
    }
    system("PAUSE");
    system("CLS");
    printf("Prefix Expression: ");
    for(i=0;i<=n-1;i++)
    {
        if(Operand[i]==blankInt)
            printf("%c ",Operator[i]);
        else
            printf("%d ",Operand[i]);
    }
    for(i=0;i<=n-1;i++)
    {
        if(Operand[i]==blankInt)
        {
            switch(Operator[i])
            {
                case '+':
                    op2=stack[tos];
                    tos--;
                    op1=stack[tos];
                    tos--;
                    x=op1+op2;
                    tos++;
                    stack[tos]=x;
                    break;
                case '-':
                    op2=stack[tos];
                    tos--;
                    op1=stack[tos];
                    tos--;
                    x=op1-op2;
                    tos++;
                    stack[tos]=x;
                    break;
                case '*':
                    op2=stack[tos];
                    tos--;
                    op1=stack[tos];
                    tos--;
                    x=op1*op2;
                    tos++;
                    stack[tos]=x;
                    break;
                case '/':
                    op2=stack[tos];
                    tos--;
                    op1=stack[tos];
                    tos--;
                    x=op1/op2;
                    tos++;
                    stack[tos]=x;
                    break;
                case '^':
                    op2=stack[tos];
                    tos--;
                    op1=stack[tos];
                    tos--;
                    x=1;
                    for(j=1;j<=op2;j++)
                        x=x*op1;
                    tos++;
                    stack[tos]=x;
                    break;
                default:
                    system("CLS");
                    printf("\nUnsupported operators are used\n");
                    printf("\n-----------------End Of Program----------------\n");
                    exit(0);
            }
        }
        else
        {
            tos++;
            stack[tos]=Operand[i];
        }
    }
    printf("\n\nValue of the expression = %f\n",x);
    return 0;
}
