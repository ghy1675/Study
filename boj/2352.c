#include <stdio.h>

int main()
{
    int arr[40001] = {-1}; // 최대 배열 크기
    int i, j, k, l=1,a;

    scanf("%d", &i);
    
    for (j = 0; j < i; j++)
    {
        scanf("%d", &k);
        if (k > arr[l-1]) // 최대값 갱신
        {
            arr[l] = k;
            l++;
        }
        else // lower bound
        {
            for (a = 0; a < l; a++)
            {
                if (k <= arr[a])
                {
                    arr[a] = k;
                    break;
                }
            }
        }
    }
    printf("%d\n", l-1);
}