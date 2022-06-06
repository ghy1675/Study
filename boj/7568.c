#include <stdio.h>
int main()
{
	int i, j, rank=0;
	int N;
	int X[51] = { 0, }, Y[51] = { 0, };

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &X[i], &Y[i]);
	}
	for (i = 0; i < N; i++)
	{
		rank = 1;
		for (j = 0; j < N; j++)
		{
			if (X[i] < X[j] && Y[i] < Y[j])
				rank++;
		}
		printf("%d ", rank);
	}
}