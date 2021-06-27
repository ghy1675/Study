#include <stdio.h>
int main()
{
	int N, m, M, T, R;
	int cnt = 0, time = 0, now= 0 ;
	scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);
	now = m;
	if (M - m < T)
		time = -1;
	else {
		while (1)
		{
			if (cnt == N)
				break;
			else
			{
				if (now + T <= M)
				{
					cnt++;
					now = now + T;
				}
				else
				{
					now = now - R;
					if (now < m)
					{
						now = m;
				  	}

				}
				time++;
			}
		}
	}
	printf("%d\n", time);
}