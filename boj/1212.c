#include <stdio.h>
int main()
{
	char arr[333335];
	char table[][8] = { "000","001","010","011","100","101","110","111" };
	int i, j, k, l;
	int flag = 0;
	int zf = 0;

	scanf("%s", arr);
	k = strlen(arr);
	for (i = 0; i < k; i++)
	{
		if (!flag) {
			if (arr[i] < 52)
			{
				if (arr[i] == 49)
				{
					printf("1");
					flag = 1;
				}
				else if (arr[i] > 49)
				{
					printf("%c%c", table[arr[i] - 48][1], table[arr[i] - 48][2]);
					flag = 1;
				}
				else if (arr[i] == 48)
					zf++;
			}
			else
			{
				printf("%s", table[arr[i] - 48]);
				flag = 1;
			}
		}
		else
		{
			printf("%s", table[arr[i] - 48]);
		}
		
	}
	if (zf == k)
		printf("0");
}