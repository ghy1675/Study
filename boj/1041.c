#include <stdio.h>

#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)

int main() 
{ 
    int i, j, k, n;
    int min1 = 51, min2 = 101, min3 = 151, max1 = 0, prev=0;
    int arr[6];

    long long ans = 0;

    scanf("%d", &n); 
    for (i = 0; i < 6; i++) 
    { 
        scanf("%d", &arr[i]);
        ans += arr[i];
        if (arr[i] >= prev)
        {
            ans -= arr[i];
            //printf("%d %d %lld\n", arr[i], prev, answer);
            ans += prev;
            prev = arr[i];
        }
        max1 = max(max1, arr[i]);
    } 
    if (n == 1) 
    { 
        printf("%lld", ans);
        return 0; 
    } 
    for (i = 0; i < 6; i++)
    {
        min1 = min(min1, arr[i]);
        for (j = i + 1; j < 6; j++) 
        { 
            if (i + j == 5) 
            { 
                continue;
            } 
            min2 = min(min2, arr[i] + arr[j]);
            for (k = j + 1; k < 6; k++) 
            { 
                if (j + k == 5 || k + i == 5)
                { 
                    continue;
                }
                min3 = min(min3, arr[i] + arr[j] + arr[k]);
            }
        } 
    } 
    ans = 0;
    ans += (5 * (long long)n*n - 16 * n + 12) * min1;
    ans += 4 * min3;
    ans += (8 * n - 12) * min2;

    printf("%lld", ans);
}
