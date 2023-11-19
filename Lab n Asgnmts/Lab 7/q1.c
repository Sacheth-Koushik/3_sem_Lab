#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a stack structure
typedef struct stack
{
    int top;
    unsigned capacity;
    char** array;
} stack;

// Function to create a new stack with a given capacity
stack* createStack(unsigned capacity)
{
    stack* stk = (stack*)malloc(sizeof(stack));
    stk -> capacity = capacity;
    stk -> top = -1;
    stk -> array = (char**)malloc(stk -> capacity * sizeof(char*));
    return stk;
}

// Function to check if the stack is empty
int isEmpty(stack* stk)
{
    return stk -> top == -1;
}

// Function to push an element onto the stack
void push(stack* stk, char* item)
{
    stk -> array[++ stk -> top] = item;
}

// Function to pop an element from the stack
char* pop(stack* stk)
{
    if (!isEmpty(stk))
        return stk -> array[stk -> top--];
    return NULL;
}


void revWord(char *s)
{
    stack * words = createStack(100);
    int len = (int)strlen(s);
    int start = 0;
    
    for(int i = 0; i <= len; i++)
    {
        if(s[i] == ' ' || s[i] == '\0' || s[i] == '\n')
        {
            int wordLen = i - start;
            if(wordLen > 0)
            {
                char * word = (char*)malloc(wordLen + 1);
                strncpy(word, s + start, wordLen);
                word[wordLen] = '\0';
                push(words, word);
            }
            start = i + 1;
        }
    }
    
    while(!isEmpty(words))
    {
        char * x = pop(words);
        printf("%s ", x);
        free(x);
    }
    printf("\n");
    
    free(words -> array);
    free(words);
}


int main(void)
{
    char s[] = "i love to code";
    revWord(s);
    
    return 0;
}
