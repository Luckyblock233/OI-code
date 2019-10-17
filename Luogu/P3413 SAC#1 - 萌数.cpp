//֪ʶ��: ��λDP 
/*
By:Luckyblock
��ĿҪ��:
���� ������l,r
�� [l,r] ���ж��ٸ� ��������>=2�Ļ��Ĵ� ����
l <=r <= 1e1000  

��������:
���Է���, һЩ��Ȼ�Ľ���:
1.�������� >=2 �Ļ��Ĵ� �ȼ���:
  ���� ����==2 ���� ���� ����==3 �Ļ��Ĵ�
  
  ֤��: 
  ��̵Ļ��Ĵ�ֻ��: aa ���� aba ������̬
  �� ��һ�����Ĵ���β �����һ��ͬ��ĸ��, �õ�����Ϊһ���Ĵ� 
  
  ������ ÿһ������λ ��ѡ�����, ���ɵ�֪���Ƿ�Ϸ� 
  ������λDP 

2.���Է���, ����һ���Ϸ�����, ����β��/�ײ��������������������,
  �õ������� ��Ȼ��һ���Ϸ�����
   
  ���ʹ�ü��仯DFS ʵ����λDP.
  ����һ����, ������֪�����һλ, �뵹���ڶ�λ,
  �����ͨ��ѡ�� ��β����ӵ���, �Ӷ�����Ϸ�����
  
3.��ʼ����״̬:
  �� f[i][j][k][0/1]: ö�ٵ���iλ, ��i-1λΪj, ��i-2λΪk ,0/1�����ڵ�iλǰ�Ƿ��л��Ĵ�  
  
  - Ϊʲô��Ҫ��� �Ƿ��л��Ĵ�?
  	���� ��������״̬:
	54123 , 32123,
	β����Ԫ����ͬ, ����ǰ�߲��Ϸ�, ���ߺϷ�
	����Ҫ���б��, ��ֹ��ⷢ�� 

4.Ȼ��Ϳ�������λDP�� ���仯dfsģ��
  1.ǰ׺��˼��, �� 1 ~ l-1 �Ĵ�, �� 1 ~ r �Ĵ�, ���������
  2.ö��ÿһλ��, �ж��Ƿ�ȫΪǰ����, �Ƿ񵽴��ѡ����Ͻ�, �Ƿ���Ϊ�Ϸ���
  3.���뵽 ��0��ʱ, ˵���������, ���ش𰸼���
  4.ע����м��仯 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define ll long long
const int MARX = 1010;
const ll mod = 1e9+7;
//=============================================================
char num[MARX];
//f[i][j][k][0/1]: ö�ٵ���iλ, ��i-1λΪj, ��i-2λΪk 
ll ans1,ans2, lim[MARX],f[MARX][10][10][2];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//�ֱ����: ö�ٵ���λ��, ������һ����, �����ڶ�����, �Ƿ񵽴��ѡ����Ͻ�, �Ƿ�ȫΪǰ����, �Ƿ�Ϊ�Ϸ�״̬ 
int dfs(ll pos, ll last1, ll last2, bool limit, bool zero, ll flag) 
{
	ll sum = 0;
	if(!pos) return flag;//�ѵ��� 0λ, ���ش� 
	if(!limit && (!zero) && (last1 != -1) && (last2 != -1) && f[pos][last1][last2][flag] != -1) return f[pos][last1][last2][flag];//�ѱ��ѹ�, ���ؼ��仯��ֵ                        
	for(int i = 0, up = (limit?lim[pos]:9); i <= up; i ++)//ö��ÿһλ(ע���ж��Ͻ� 
	{
	  bool limit1 = (limit && i == up), zero1 = (!i && zero);//���¸����� 
	  ll flag1 = (flag || (!zero && i == last1) || (!zero && i == last2));//�ж��Ƿ�Ϸ� 
	  ll last11 = (zero1 ?-1 : i), last21 = (zero ? -1 : last1);//���� �������� 
	  ll ret = dfs(pos-1, last11, last21, limit1, zero1,flag1) % mod; 
	  sum = (sum + ret) % mod;//�ۼӷ���ֵ 
	}
	if(!limit && (!zero) && (last1 != -1) && (last2 != -1)) return (f[pos][last1][last2][flag] = sum);//�Ϸ�״̬,���м��仯 
	return sum;
}
ll solve(char s[], ll op) //���ַ��� ת��Ϊ���� 
{
	ll lth = strlen(s+1), tot = 1;
	memset(f,-1,sizeof(f));//��ʼ�� 
	for(ll i = 1; i <= lth; i ++) lim[lth-i+1] = s[i] - '0';//����洢 
	while(lim[tot] - op < 0)//l-1��������� 
	{
	  if(tot == lth) break;
	  lim[tot] = 9, tot ++;
	}
	lim[tot] -= op;//l-1��������� 
	return dfs(lth,-1,-1,1,1,0);
}
//=============================================================
signed main()
{
	scanf("%s", num+1);  ans1 = solve(num,1);//��� 
	scanf("%s", num+1);  ans2 = solve(num,0);
	printf("%lld",(ans2 - ans1 + mod) % mod);//ǰ׺�� 
}
