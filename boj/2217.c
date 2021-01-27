#include <stdio.h>
#include <stdlib.h>

int int_icompare(const void* a, const void* b)    
{
    int num1 = *(int*)a;    
    int num2 = *(int*)b;

    if (num1 > num2)    
        return -1;      

    if (num1 < num2)    
        return 1;      

    return 0;   
}

int main()
{
    int arr[100001];
    int i, j = 1, k, ans=0,idx=1, prev;
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr,k, sizeof(int), int_icompare);
    for (i = 0; i < k; i++)
    {
        arr[i] = arr[i] * (i+1);
        if (ans <= arr[i])
            ans = arr[i];
    }
    printf("%d\n", ans);
}