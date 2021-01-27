#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool arr[10001];

int main()
{
    int i, j, k, l;
    int target,left, right;
    bool flag = false;
    for (i = 2; i < 10001; i++)
    {
        for (j = 2; j * i < 10001; j++)
            arr[i * j] = true;
    }
    scanf("%d", &i);
    
    for(j =0 ; j < i; j++)
    {
        flag = false;
        scanf("%d", &target);
        {
            for (k = target / 2; k > 1; k--)
            {
                if (!arr[k])
                {
                    left = target - k;
                    for (l = target / 2; l <= target; l++)
                    {
                        if (!arr[l])
                        {
                            if (l == left)
                            {
                                flag = true;
                                break;
                            }
                            else if (l > left)
                                break;
                        }
                    }
                    if (flag)
                    {
                        printf("%d %d\n", k, l);
                        break;
                    }
                }
            }
        }
    }
}