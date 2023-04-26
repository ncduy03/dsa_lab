#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    double delta, x1, x2;
    scanf("%d %d %d", &a, &b, &c);
    delta = b*b - 4*a*c;
    if(delta < 0)
    {
        printf("NO SOLUTION\n");
    }
    else if(delta == 0)
    {
        x1 = -b / (2*a);
        printf("%lf\n", x1);
    }
    else
    {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("%lf %lf\n", x1, x2);
    }
    return 0;
}
