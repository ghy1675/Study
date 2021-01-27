#include <stdio.h>
#include <stdbool.h>

bool arr[1000001];

int main()
{
    int i=-1, k,j;
    int target=-1;
    bool flag = false;
    for (i = 2; i < 1000001; i++)
    {
        for (j = 2; j * i < 1000001; j++)
            arr[i * j] = true;
    }
    while(target!=0)
    {
        scanf("%d", &target);
        {
            for (k = 2; k <target; k++)
            {
                if (!arr[k])
                {
                    if(!arr[target - k])
                    {
                        printf("%d = %d + %d\n",target, k, target - k);
                        break;
                    }
                }
            }
        }
    }
}