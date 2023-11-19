#include<stdio.h>

// Q1
void Q1_foo2 (int);
void Q1_foo1(int n)
{
    if (n <= 10)
    {
        printf("%d\t", n);
        n++;
        Q1_foo2(n);
    }
}

void Q1_foo2(int n)
{
    if (n <= 10)
    {
        printf("%d\t", n);
        n++;
        Q1_foo1(n);
    }
}


// Q2

int Q2_foo1()
{
    static int n = 100;
    if (n <= 0)
            return 0;
    return n--;
}



// Q3

int f(int n)
{
    static int r = 0;
    if (n <= 0) return 1;
    if (n > 3)
    {
        r = n;
        return f(n - 2) + 2;
    }
    return f(n-1) + r;
}



//driver code
int main()
{
    // Q1
    printf("Q1\n");
    Q1_foo1(1);
    printf("\n\n\n");
    // Q2
    printf("Q2\n");
    for(Q2_foo1(); Q2_foo1(); Q2_foo1())
        printf("%d\t", Q2_foo1());
    printf("\n\n\n");

    // Q3
    printf("Q3\n");
    printf("%d", f(5));
    printf("\n\n\n");

    return 0;
}