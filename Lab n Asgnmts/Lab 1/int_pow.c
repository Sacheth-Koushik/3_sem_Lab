#include<stdio.h>

int pow(int n, int e)
{
    if (e == 0)
        return 1;
    if ((e & 1) == 0)
        return pow(n * n, e/2);
    return n * pow(n * n, (e - 1)/2);
}

int main()
{
    int n = 2, e = 10;
    int ans = pow(n,e);
    printf("%d\n", ans);
    return 0;
}