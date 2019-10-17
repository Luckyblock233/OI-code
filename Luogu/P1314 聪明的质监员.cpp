//֪ʶ��:���ִ�,ǰ׺�� 
/*
By:Luckyblock
��ĿҪ��:
���� һ����a, ����m������[li,ri], ����һ����S 
������ѡ�� ����W��ֵ
����i�Ĺ��� Yi = ��(������>=W����������) * ��(������>=W������Ȩֵ��)

�ܹ��� = abs(��Yi - S);
�� ���ܹ�����С�� ����W��ֵ 

��������:
- ��������� W, ������������:
  �� W ����ʱ, wj���ڵ���W�� Ԫ������ ����, �ܹ���Y���� 
  �� W ����ʱ, wj���ڵ���W�� Ԫ������ ����, �ܹ���Y����
  
  ���� W ��ȡֵ ��Y�� �����, �����ͨ�����ִ� ö��W;

- �� W ȷ��ʱ, ����������Y, �Լ��𰸵�������
  1.����ö��!
    ���� ÿһ����������, ����ö�����кϷ�Ԫ��, ����������
	���Ӷ� O(nm) , ��Ȼ�ᱻ���� 
	
  2.Ҫ�� �����ںϷ�Ԫ���� �� �����ںϷ�Ԫ�صĺ�
  	��Ȼ, ����� ��������ɼ��� , 
	����ʹ��ǰ׺�� O(n)ά�� , ����O(1) ���ÿ�������� ����
	�Ϳ� O(1)����� ��������Ĺ��� 
    ���Ӷ� O(n) 
*/
#include<cstdio>
#include<ctype.h>
#include<cstdlib>
#define max(a,b) (a>b?a:b)
#define int long long
const int MARX = 2e5+10;
//=============================================================
int n, m, S, ans, maxw , w[MARX], v[MARX];
int l[MARX], r[MARX];//��ѯ��m������ 
int sum1[MARX], sum2[MARX];
//sum1,2Ϊ ��ǰ׺������, 1Ϊ���������� ��ʯ����, 2Ϊ���������� ��ʯ ��ֵ�� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch); ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch); ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int abs(int x) {return (x<0?-x:x);}//����ֵ ���� 
bool check(int W,int &sum)
{
	sum = 0;
	for(int i = 1; i <= n; i ++) //ά����ǰ׺�� 
	  sum1[i] = sum1[i-1] + (w[i] >= W),
	  sum2[i] = sum2[i-1] + v[i] * (w[i] >= W);
	
	for(int i = 1; i <= m; i ++)//ö�ٲ�ѯ���� 
	{
	  int l1 = l[i], r1 = r[i];//���� ����Ĺ��� 
	  sum += (sum1[r1]-sum1[l1-1]) * (sum2[r1]-sum2[l1-1]);
	}
	return sum > S;//���������� 
}
//=============================================================
signed main()
{
	n = read(),m = read(), S = read();
	for(int i = 1; i <= n; i ++)
	{
	   w[i] = read(), v[i] = read();
	   maxw = max(maxw,w[i]);
	}
	for(int i =1 ; i <= m; i ++) l[i] = read(), r[i] = read();
	
	for(int l = 1,r = maxw; l <= r;)//����ö�� ����W 
	{
	  int mid = (l + r) >> 1, sum;
	  if(check(mid,sum)) l = mid + 1; 
	  else r = mid - 1;
	  if(abs(sum - S) < abs(ans - S)) ans = sum;//���´� 
	}
	printf("%lld",abs(ans - S));
}
