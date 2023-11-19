#include<stdio.h>

int main()
{
    float n = 5;
    int precision = 5;
    int int_sq = 4;
    float increment = 0.1;

    //find base
    int l = 1;
    int r = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid * mid  > n)
        {r = mid - 1;}
        else
        {
            l = mid + 1;
            int_sq = mid;
        }
    }
    float ans = int_sq;
    //digits after int
    for(int i = 0; i < precision; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            float intermediate = ans + increment;
            if ((intermediate * intermediate) > n)
                break;
            else
                ans = intermediate;
        }
        increment /= 10;
    }
    printf("%.5f\n", ans);
    return 0;
}