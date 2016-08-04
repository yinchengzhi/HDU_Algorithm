#define _CRT_SECURE_NO_WARNINGS

#include<iostream>  
using namespace std;

int  pre[1050];
bool t[1050];               //t ���ڱ�Ƕ�����ĸ����  

int Find(int x)
{
	int r = x;
	while (r != pre[r])
		r = pre[r];

	int i = x, j;
	while (pre[i] != r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

void mix(int x, int y)
{
	int fx = Find(x), fy = Find(y);
	if (fx != fy)
	{
		pre[fy] = fx;
	}
}

int main()
{
	int N, M, a, b, i, ans;
	while (scanf("%d%d", &N, &M) && N)
	{
		for (i = 1; i <= N; i++)          //��ʼ��   
			pre[i] = i;

		for (i = 1; i <= M; i++)          //���ղ���������   
		{
			scanf("%d%d", &a, &b);
			mix(a, b);
		}


		memset(t, 0, sizeof(t));
		for (i = 1; i <= N; i++)          //��Ǹ����  
		{
			t[Find(i)] = 1;
		}
		for (ans = 0, i = 1; i <= N; i++)
			if (t[i])
				ans++;

		printf("%d\n", ans - 1);

	}
	return 0;
}

