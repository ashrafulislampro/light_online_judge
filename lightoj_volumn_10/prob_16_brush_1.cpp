#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        int n, sum = 0, num;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &num);
            if (num > 0)
            {
                sum += num;
            }
        }
        printf("Case %d: %d\n", caseno, sum);
    }
    return 0;
}