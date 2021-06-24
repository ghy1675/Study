#include <stdio.h>
int main()
{
	unsigned long i=0;
	char arr[10001], arr1[10001];
	int j, k;
	scanf("%s %s", arr, arr1);
	for (j = 0; j < strlen(arr); j++)
	{
		for (k = 0; k < strlen(arr1); k++)
		{
			i += (arr[j] - 48)*(arr1[k]-48);
		}
	}
	printf("%ld\n", i);
}