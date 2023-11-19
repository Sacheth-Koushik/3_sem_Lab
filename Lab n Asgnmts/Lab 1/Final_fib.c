#include<stdio.h>
#include<time.h>


int fib_recur(int n)
{
    if (n == 0 || n == 1) { return n; }
    else
    {
        return fib_recur(n - 1) + fib_recur(n - 2);
    }
}

int fib_iter(int n)
{
    int a = 0,b = 1,c;
    if (n == 2){c = 1;}
    if (n <= 1) { c = 0;}
    if (n == 3) { c = 2;}
    for (int i = 0; i <= n - 2 && n > 2; i++)
    {
        c = a + b;
        a = b;
        b = c; 
    }
    return c;
}

int fib_dp(int n)
{
    int a[n+1];
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;

    if (n<=2){return a[n];}
    for (int i = 3; i <= n; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}

void multiply(int f[2][2], int m[2][2])
{
    int x = f[0][0] * m[0][0] + f[0][1] * m[1][0];
    int y = f[0][0] * m[0][1] + f[0][1] * m[1][1];
    int z = f[1][0] * m[0][0] + f[1][1] * m[1][0];
    int w = f[1][0] * m[0][1] + f[1][1] * m[1][1];
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = w;
}

void power(int f[2][2], int n)
{
    if ( n == 0 || n == 1 )
        return;
    int m[2][2] = {{1,1}, {1,0}};
    power(f, n/2);
    multiply(f,f);
    if (n % 2 != 0)
        multiply(f,m);
}

int fib_mat_mul(int n)
{
    int f[2][2] = {{1,1}, {1,0}};
    if ( n == 0)
        return 0;
    power(f,n-1);
    return f[0][0];
}

int fib_hash(int n)
{
    int arr[31] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28567,46368,75025,121393,196418,317811,514229,832040};
    if (n < 30)
        return arr[n-1];
    int a = arr[29], b = arr[28],c;
    for ( int i = 0;i<=30-n;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Driver Code

int main()
{
    int n = 30;
    clock_t start, end;

    //recursive
    start = clock();
    printf("%d    ", fib_recur(n));
    end = clock();
    double exec_t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", exec_t);

    //iterative
    start = clock();
    printf("%d    ", fib_iter(n));
    end = clock();
    exec_t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", exec_t);

    //dp
    start = clock();
    printf("%d    ", fib_dp(n+1));
    end = clock();
    exec_t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", exec_t);

    //mat mul
    start = clock();
    printf("%d    ", fib_mat_mul(n));
    end = clock();
    exec_t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", exec_t);

    // hash
    start = clock();
    printf("%d    ", fib_hash(n));
    end = clock();
    exec_t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", exec_t);

    return 0;
}