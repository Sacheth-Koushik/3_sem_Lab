#include<stdio.h>
#include<math.h>
void prime_conven(int n)
{
    for (int i = 2; i <= n; i++)
    {
        int flag = 1;
        for (int j = 2; j <= (int)sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%d ", i);
    }
    printf("\n");
}

void prime_sieve(int n)
{
    int a[n+1];

    for(int i = 0; i < n+1; i++)
        a[i] = 1;
    
    a[0] = 0;
    a[1] = 0;
    
    for (int i = 2; i <= n; i++)
        if (a[i])
            for (int j = i*i; j <= n; j += i)
                a[j] = 0;

    for(int i = 0; i < n+1; i++)
        if (a[i])
            printf("%d ", i);
            
}

int main()
{
    int n = 50;
    printf("By conven: \n");
    prime_conven(50);
    printf("By sieve: \n");
    prime_sieve(50);
}