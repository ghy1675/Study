#include "teamnote.h"

int main()
{
    char arr[200], qwe[200], * ptr;
    int i, j, anw;

    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        anw = 0;
        scanf("%s", arr);
        if (arr[0] >= 65)
        {
            printf("skipped\n");
            continue;
        }
        ptr = strtok(arr, "+");
        while (ptr != NULL)
        {
            strcpy(qwe, ptr);
            anw += atoi(qwe);
            ptr = strtok(NULL, "+");
        }
        printf("%d\n", anw);
    }
}