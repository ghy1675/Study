#include <stdio.h>

#define min(a,b) (a<b? a:b)

int main()
{
    int i, j, k, result = -1, N, K;
    int start=1, end, cnt,mid;
    scanf("%d %d", &N, &K);
    end = K;
    while (start<=end)
    {
        cnt = 0;
        mid = (start + end) / 2;
        for (i = 1; i <= N; i++)
        {
            cnt += min(mid / i, N);
        }
        if (cnt < K)
            start = mid + 1;
        else
        {
            result = mid;
            end = mid - 1;
        }
    }
    printf("%d", result);
}