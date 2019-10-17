//֪ʶ��:ɸ�������� 
/*
By:Luckyblock
��ĿҪ��: 
�������� [l,r] , (l<=r<=maxint , r-l<=1e6)
�� [l,r] �������ĸ��� 

��������:
��Ȼ , ֱ�ӽ�[l,r]�ڵ�����ɸ���ǲ����ܵ�
��Ҫʹ��һЩ����.

��������: 
���� ����x, �������һ��������>=sqrt(x),
���� �����Ӷ� <= sqrt(x)
��: �� Ԥ����� [1,sqrt(maxint)] �е�����,
�� [l,r] �еĺ��� ��Ȼ�������Ӵ����� [1,sqrt(maxint)]��

��ô����ʹ��ɸ�� ��� [1,sqrt(maxint)]�е�����,
���� r-l <=1e6,  
���ʹ�� ��Щ���� ,�ٽ� [l,r]�еĺ���ɸ��
���ͳ�� [l,r] �� δ��ɸȥ�� Ԫ��, ������, ����

ע�� l,r<=maxint,
ɸ [l,r]��Ԫ��ʱ, ���ǵ������±겻�ɿ���maxint
���Խ������±�ȫ����ȥ l����ʹ��  
*/
#include<cstdio>
#include<cmath>
#include<vector>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int MARX = 5e4+10;
//=============================================================
int l,r,ans;
bool flag[MARX]={1,1},flag1[20*MARX];
std:: vector <int> prime;
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
	l=read(),r=read();
	for(int i=2; i<MARX-10; i++)//ɸ��[1,50000]�ڵ����� (50000>sqrt(maxint)) 
	{
	  if(!flag[i]) prime.push_back(i);
	  for(int j=2; i*j<=MARX-10; j++)
	    flag[i*j] = 1;
	}
	 
	for(int i=0,size=prime.size(); i<size; i++)//ʹ��ɸ��������, ��ɸȥ[l,r]�ĺ��� 
	  for(int j=max(2ll,(l-1)/(prime[i])+1); prime[i]*j <= r; j++)
		//��j��С, ʹprime[i]*j <l, �������޹���, �һᵼ������Խ�� 
		//��Ϊj����һ�����ֵ,�Ա���Խ��,����Сѭ������ 
		flag1[prime[i]*j-l] = 1;
	for(int i=l; i<=r; i++) ans += (!flag1[i-l]);//ͳ�ƴ� 
	printf("%lld",ans);
}
