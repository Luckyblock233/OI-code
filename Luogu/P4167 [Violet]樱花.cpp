//֪ʶ��:Լ������, Ψһ�ֽⶨ��, ɸ������ 
/*
By:Luckyblock
��ѧ�Ƶ���ʽ�϶� , ʹ����latex������Ⱦ 
��ĿҪ��:

���� $\large n$ , �� $\large \dfrac{1}{x} + \dfrac{1}{y} = \dfrac{1}{n!}$ ����������  �Ķ���

��������:

- ���ȶ� ���ʽ����ת�� :  

  $$\large \dfrac{1}{x} + \dfrac{1}{y} = \dfrac{1}{n!}$$   

  $$\large y\times n!+x\times n! = x\times y$$

  $$\large x\times y - \large y\times n!-x\times n! = 0$$

  $$\large x\times y - \large y\times n!-x\times n! + (n!)^2 = (n!)^2$$

- ���� ʮ����˷��� , ������ʽ�ֽ�, ����: 

   $$\large (x-n!)(y-n!) = n!$$

  ���� $x,y,n \in Z$  ,  �� $(x-n!) \text{��} (y-n!)$ ��Ϊ $n!$ ��Լ��
  �� ��Ŀ�����Ķ��� ,  ��Ϊ $n!$ ��Լ������

-  ���� Ψһ�ֽⶨ�� ,����:
	
	$$\large n! = \prod\limits{p_i^{c_i}}(p_i\mid n)$$
	
	
	����Լ���Ͷ��� ,  ����:
	
	$$\large \alpha(n!) = \prod\limits{(c_i+1)}$$

	����Ŀ���� ��Ϊ:  
	
	$$\large \alpha((n!)^2) = \prod\limits{(2\times c_i+1)}$$

- ���� $\large n!$ �������Ӷ� $\large\le n$ ,   
  �����ʹ��ɸ��ֱ��Ԥ��������� �й��׵�����

- ��һ��ʽ :
	
	���� $\large n!$ , $\large p_i$ �� $\large n!$ ���������ֽ��� , ָ�� ��ֵ $\large c_i$ 
   $$\large c_i = \sum\limits_{k=1}^{\inf}{\lfloor\frac{n}{p_i^k}\rfloor} (p_i^k\le n)$$ 

	���� �˹�ʽ , ���ɿ���� ָ�� $c_i$ ��ֵ
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
#define ll long long
const ll mod = 1e9+7;
const int MARX = 1e6+10;
//=============================================================
int n;
ll ans = 1;
bool flag[MARX];
std::vector <ll> prime;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n = read();
	for(int i = 2; i <= n; i ++) //����ɸԤ�������� <=n������ 
	{
	  if(!flag[i]) prime.push_back(i);
	  for(int j = 2; i * j <= n; j ++)
	    flag[i*j] = 1;
	}	
	
	for(int i = 0,size = prime.size(); i < size && prime[i] <= n; i ++)//ö������ 
	{
	  ll tmp = 0, x = n, y = prime[i];
      for (; x; x /= prime[i]) tmp += x / y;//��� x/y, x/(y^2), x/(y^3)... 
      ans = (ans * (tmp << 1 | 1) % mod) % mod;//�۳� ���㹱�� 
	}
	printf("%lld",ans);
}
