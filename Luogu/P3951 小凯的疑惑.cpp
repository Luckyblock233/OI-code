/*
不妨设 a < b a<b
假设答案为 x x
若
	x = ma (mod b) (1<= m <= b-1)

即
	x = ma + nb (1≤m ≤b-1)

显然当 n≥0 时 x 可以用 a,b 表示出来，不合题意。

因此当 n = -1 时 x 取得最大值，此时 x = ma - b 

显然当 m 取得最大值 b - 1 时 x 最大，此时 x = (b - 1)a - b = ab-a-b 
因此 a, b 所表示不出的最大的数是 ab - a - b
*/ 
#include<cstdio>
using namespace std;
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",a*b-a-b);
}
