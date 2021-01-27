#include <stdio.h>

#define min(a,b) a<b?a:b

int main()
{
    int arr[100001] = {0,1,2,3,1};
    int i, j=1, k;
    scanf("%d", &k);

    for (i = 1; i <= k; i++)
    {
        arr[i] = i;
        for (j = 1; j * j <= i; j++)
        {
            arr[i] = min(arr[i], arr[i - j * j] + 1);
        }
    }
    
    printf("%d\n",arr[k]);
}