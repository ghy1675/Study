#include <stdio.h>
#define max(a,b) a<b?b:a
int main()
{
    int ans = 0;
    int arr[30001], i, j, k;
    scanf("%d", &i);

    for (j = 0; j < i; j++)
    {
        scanf("%d", &arr[j]);
    }
    for (j = 0; j < i; j++)
    {
        for (k = j + 1; k < i; k++)
        {
            if (arr[k] > arr[j])
                break;
        }
        ans = max(ans, k - j-1);
    }
    printf("%d\n", ans);
}