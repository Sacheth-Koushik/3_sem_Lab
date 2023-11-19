#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"stack.h"
#include<math.h>

int precedence(char operator)
{
    switch (operator) 
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
  
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch == '^');
}
int isAlnum(char ch)
{
    return ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90)||(ch >= 97 && ch <= 122));
}
char* infixToPostfix(char* infix)
{
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1;
  
    for (i = 0, j = 0; i < len; i++) 
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;
        if (isAlnum(infix[i])) 
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            stack[++top] = infix[i];
        else if (infix[i] == ')') 
        {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }
        else if (isOperator(infix[i])) 
        {
            while (top > -1
                   && precedence(stack[top])
                          >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

int operate(char op, int x, int y)
{
    int res = 0;
    // switch(op)
    // {
    //     case '+':
    //         return x + y;
    //     case '-':
    //         return x - y;
    //     case '*':
    //         return x * y;
    //     case '/':
    //         return x / y;
    //     case '^':
    //         return (int)pow(x,y);
    //     default:
    //         return -9999999;
    // }
    switch(op)
    {
        case '+':
            res = x + y;
            break;
        case '-':
            res = x - y;
            break;
        case '*':
            res = x * y;
            break;
        case '/':
            res = x / y;
            break;
        // case '^':
        //     return (int)pow(x,y);
        default:
            res = -9999999;
    }
    return res;
}

void eval(char *c)
{
    stack *s = create(strlen(c));
    int i = 0;
    while(c[i])
    {

        if(isAlnum(c[i]))
            {push(s, c[i] - '0');i++; continue;}
        int y = peek(s);
        pop(s);
        int x = peek(s);
        pop(s);

        push(s, operate(c[i], x, y));
        i++;
    }
    printf("result is %d\n", peek(s));
}

int main()
{
    char infix[100] = "4+6*3-4/2"; //20
    char* postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    eval(postfix);
    free(postfix);
    return 0;
}