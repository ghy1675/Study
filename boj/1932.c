#include <stdio.h>
#define MAX 500
#define max(a,b) a<b?b:a
int main()
{
    int arr[MAX + 1][MAX + 1], i, j, k, l;
    int pvt = 0;
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        for (k = 0; k <= j; k++)
        {
            scanf("%d", &arr[j][k]);
        }
    }

    for (j = 1; j < i; j++)
    {
        for (k = 0; k <= j; k++)
        {
            if (k == 0) arr[j][k] = arr[j - 1][0] + arr[j][k];
            else if (j == i) arr[j][k] = arr[j - 1][k - 1] + arr[j][k];
            else arr[j][k] = max(arr[j - 1][k - 1] + arr[j][k], arr[j - 1][k] + arr[j][k]);

            pvt = max(pvt, arr[j][k]);
        }
    }
    printf("%d\n", pvt);
}